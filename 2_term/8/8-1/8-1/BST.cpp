#include <stdio.h>
#include "BST.h"

int BST::TreeNode::height()
{
   return (this != nullptr) ? this->heightField : 0;
}

void BST::TreeNode::updateHeight()
{
   int heightLeft = this->left->height();
   int heightRight = this->right->height();
   this->heightField = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

BST::TreeNode* BST::TreeNode::rotateRight()
{
   TreeNode* pivot = this->left;
   this->left = pivot->right;
   pivot->right = this;
   this->updateHeight();
   pivot->updateHeight();
   return pivot;
}

BST::TreeNode* BST::TreeNode::rotateLeft()
{
   TreeNode* pivot = this->right;
   this->right = pivot->left;
   pivot->left = this;
   this->updateHeight();
   pivot->updateHeight();
   return pivot;
}

int BST::TreeNode::balanceFactor()
{
   return this->right->height() - this->left->height();
}

BST::TreeNode* BST::TreeNode::balance()
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

BST::TreeNode::TreeNode(int value)
{
    this->value = value;
    heightField = 1;
    left = nullptr;
    right = nullptr;
}

BST::BST()
{
    this->root = nullptr;
}

void BST::TreeNode::addNode(int value, TreeNode *&element)
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
        element = new TreeNode(value);
    }
    return;
}

void BST::addNode(int value)
{
    TreeNode::addNode(value, root);
}

bool BST::TreeNode::isExists(int value)
{
    if (this == nullptr)
    {
        return false;
    }
    else if (value < this->value)
    {
        return this->getLeft()->isExists(value);
    }
    else if (value > this->value)
    {
        return this->getRight()->isExists(value);
    }
    return true;
}

bool BST::isExists(int value)
{
    return this->getRoot()->isExists(value);
}



int BST::TreeNode::modeOfElement()
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

int BST::TreeNode::findMinimum()
{
    TreeNode* iter = this;
    while (iter->getLeft() != nullptr)
    {
        iter = iter->getLeft();
    }
    return iter->value;
}

BST::TreeNode *BST::TreeNode::getRight()
{
    return right;
}

BST::TreeNode *BST::TreeNode::getLeft()
{
    return left;
}

void BST::deleteOneDescendant(BST::TreeNode *&element)
{
    TreeNode* tempElement = element;
    if (element->getLeft() != nullptr)
    {
        element = element->getLeft();
    }
    else if (element->getRight() != nullptr)
    {
        element = element->getRight();
    }
    delete tempElement;
}

void BST::deleteTwoDescendant(BST::TreeNode *&element)
{
    int valueMin = element->getRight()->findMinimum();
    TreeNode::deleteNode(valueMin, element);
    element->value = valueMin;
}

void BST::deleteNoDescendant(BST::TreeNode *&element)
{
    delete element;
    element = nullptr;
}

bool BST::TreeNode::deleteNode(int value, BST::TreeNode *&element)
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

bool BST::deleteNode(int value)
{
    return TreeNode::deleteNode(value, this->root);
}

void BST::deleteBST(TreeNode *element)
{
    if (element == nullptr)
    {
        return;
    }
    deleteBST(element->getLeft());
    deleteBST(element->getRight());
    delete element;
    return;

}

BST::~BST()
{
    deleteBST(this->getRoot());
}

QString BST::printStructBST(TreeNode *element, QString result)
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
    result = printStructBST(element->getLeft(), result);
    result = printStructBST(element->getRight(), result);
    result += ")";
    return result;

}

QString BST::printStructOfSet()
{
    QString result;
    return printStructBST(this->getRoot(), result);
}

QString BST::printInorderBST(TreeNode *element, QString result)
{
    if (element == nullptr)
    {
        return result;
    }
    result = printInorderBST(element->getLeft(), result);
    result += QString::number(element->value) + " ";
    result = printInorderBST(element->getRight(), result);
    return result;

}

QString BST::printInorderSet()
{
    QString result;
    return printInorderBST(this->getRoot(), result);
}

QString BST::printReverseInorderBST(TreeNode *element, QString result)
{
    if (element == nullptr)
    {
        return result;
    }
    result = printReverseInorderBST(element->getRight(), result);
    result += QString::number(element->value) + " ";
    result = printReverseInorderBST(element->getLeft(), result);
    return result;
}

BST::TreeNode *BST::getRoot()
{
    return root;
}

QString BST::printReverseInorderSet()
{
    QString result;
    return printReverseInorderBST(this->getRoot(), result);
}

