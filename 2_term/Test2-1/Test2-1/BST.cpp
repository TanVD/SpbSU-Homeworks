#include <stdio.h>
#include "BST.h"

int Set::SetNode::height()
{
   return (this != nullptr) ? this->heightField : 0;
}

void Set::SetNode::updateHeight()
{
   int heightLeft = this->left->height();
   int heightRight = this->right->height();
   this->heightField = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

Set::SetNode* Set::SetNode::rotateRight()
{
   SetNode* pivot = this->left;
   this->left = pivot->right;
   pivot->right = this;
   this->updateHeight();
   pivot->updateHeight();
   return pivot;
}

Set::SetNode* Set::SetNode::rotateLeft()
{
   SetNode* pivot = this->right;
   this->right = pivot->left;
   pivot->left = this;
   this->updateHeight();
   pivot->updateHeight();
   return pivot;
}

int Set::SetNode::balanceFactor()
{
   return this->right->height() - this->left->height();
}

Set::SetNode* Set::SetNode::balance()
{
    this->updateHeight();
    if (this->balanceFactor() == 2)
    {
        if (this->right->balanceFactor() < 0)
            this->right = this->right->rotateRight();
        return this->rotateLeft();
    }
    if (this->balanceFactor() == -2)
    {
        if (this->left->balanceFactor() > 0)
            this->left = this->left->rotateLeft();
        return this->rotateRight();
    }
    return this;
}

Set::SetNode::SetNode(int value)
{
    this->value = value;
    heightField = 1;
    left = nullptr;
    right = nullptr;
}

Set::Set()
{
    this->root = nullptr;
}

void Set::SetNode::addNode(int value, SetNode *&element)
{
    if (element != nullptr)
    {
        if (value > element->value)
        {
            addNode(value, element->right);
        }
        else if (value < element->value)
        {
            addNode(value, element->left);
        }
        element = element->balance();
    }
    else
    {
        element = new SetNode(value);
    }
    return;
}

void Set::addNodeInSet(int value)
{
    SetNode::addNode(value, this->root);
}

bool Set::SetNode::isExists(int value)
{
    if (this == nullptr)
    {
        return false;
    }
    else if (value < this->value)
    {
        return this->left->isExists(value);
    }
    else if (value > this->value)
    {
        return this->right->isExists(value);
    }
    return true;
}

bool Set::isExistsInSet(int value)
{
    return this->root->isExists(value);
}

enum modesElement
{
    noDescendant = 0,
    oneDescendant = 1,
    twoDescendant = 2,
};

int Set::SetNode::modeOfElement()
{
    if ((this->left == nullptr) && (this->right == nullptr))
    {
        return noDescendant;
    }
    if ((this->left == nullptr) || (this->right == nullptr))
    {
        return oneDescendant;
    }
    return twoDescendant;
}

int Set::SetNode::findMinimum()
{
    SetNode* iter = this;
    while (iter->left != nullptr)
    {
        iter = iter->left;
    }
    return iter->value;
}

void Set::deleteOneDescendant(Set::SetNode *&element)
{
    SetNode* tempElement = element;
    if (element->left != nullptr)
    {
        element = element->left;
    }
    else if (element->right != nullptr)
    {
        element = element->right;
    }
    delete tempElement;
}

void Set::deleteTwoDescendant(Set::SetNode *&element)
{
    int valueMin = element->right->findMinimum();
    deleteNode(valueMin, element);
    element->value = valueMin;
}

void Set::deleteNoDescendant(Set::SetNode *&element)
{
    delete element;
    element = nullptr;
}

bool Set::deleteNode(int value, Set::SetNode *&element)
{
    if (element == nullptr)
    {
        return false;
    }
    if (value > element->value)
    {
        deleteNode(value, element->right);
        element = element->balance();
    }
    else if (value < element->value)
    {
        deleteNode(value, element->left);
        element = element->balance();
    }
    else if (value == element->value)
    {
        switch (element->modeOfElement())
        {
        case oneDescendant:
        {
            deleteOneDescendant(element);
            break;
        }
        case twoDescendant:
        {
            deleteTwoDescendant(element);
            break;
        }
        case noDescendant:
        {
            deleteNoDescendant(element);
            break;
        }
        }
    }
    return true;
}

bool Set::deleteNodeInSet(int value)
{
    return deleteNode(value, this->root);
}

void Set::deleteBST(SetNode *element)
{
    if (element == nullptr)
    {
        return;
    }
    deleteBST(element->left);
    deleteBST(element->right);
    delete element;
    return;

}

Set::~Set()
{
    deleteBST(this->root);
}

QString Set::printStructBST(SetNode *element, QString result)
{
    if (element != nullptr)
    {
        result += QString::number(element->value) + " ";
    }
    else
    {
        result += "NULL ";
        return result;
    }
    result += "(";
    result = printStructBST(element->left, result);
    result = printStructBST(element->right, result);
    result += ")";
    return result;

}

QString Set::printStructOfSet()
{
    QString result;
    return printStructBST(this->root, result);
}

QString Set::printInorderBST(SetNode *element, QString result)
{
    if (element == nullptr)
    {
        return result;
    }
    result = printInorderBST(element->left, result);
    result += QString::number(element->value) + " ";
    result = printInorderBST(element->right, result);
    return result;

}

QString Set::printInorderSet()
{
    QString result;
    return printInorderBST(this->root, result);
}

QString Set::printReverseInorderBST(SetNode *element, QString result)
{
    if (element == nullptr)
    {
        return result;
    }
    result = printReverseInorderBST(element->right, result);
    result += QString::number(element->value) + " ";
    result = printReverseInorderBST(element->left, result);
    return result;
}

QString Set::printReverseInorderSet()
{
    QString result;
    return printReverseInorderBST(this->root, result);
}

