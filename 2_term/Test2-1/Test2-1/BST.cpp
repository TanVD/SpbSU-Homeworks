#include <stdio.h>
#include "BST.h"

int Tree::TreeNode::height()
{
   return (this != nullptr) ? this->heightField : 0;
}

void Tree::TreeNode::updateHeight()
{
   int heightLeft = this->left->height();
   int heightRight = this->right->height();
   this->heightField = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

Tree::TreeNode* Tree::TreeNode::rotateRight()
{
   TreeNode* pivot = this->left;
   this->left = pivot->right;
   pivot->right = this;
   this->updateHeight();
   pivot->updateHeight();
   return pivot;
}

Tree::TreeNode* Tree::TreeNode::rotateLeft()
{
   TreeNode* pivot = this->right;
   this->right = pivot->left;
   pivot->left = this;
   this->updateHeight();
   pivot->updateHeight();
   return pivot;
}

int Tree::TreeNode::balanceFactor()
{
   return this->right->height() - this->left->height();
}

Tree::TreeNode* Tree::TreeNode::balance()
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

Tree::TreeNode::TreeNode(int value)
{
    this->value = value;
    heightField = 1;
    left = nullptr;
    right = nullptr;
}

Tree::Tree()
{
    this->root = nullptr;
}

void Tree::TreeNode::addNode(int value, TreeNode *&element)
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

void Tree::addNodeInSet(int value)
{
    TreeNode::addNode(value, this->root);
}

bool Tree::TreeNode::isExists(int value)
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

bool Tree::isExistsInSet(int value)
{
    return this->root->isExists(value);
}

enum modesElement
{
    noDescendant = 0,
    oneDescendant = 1,
    twoDescendant = 2,
};

int Tree::TreeNode::modeOfElement()
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

int Tree::TreeNode::findMinimum()
{
    TreeNode* iter = this;
    while (iter->left != nullptr)
    {
        iter = iter->left;
    }
    return iter->value;
}

void Tree::deleteOneDescendant(Tree::TreeNode *&element)
{
    TreeNode* tempElement = element;
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

void Tree::deleteTwoDescendant(Tree::TreeNode *&element)
{
    int valueMin = element->right->findMinimum();
    deleteNode(valueMin, element);
    element->value = valueMin;
}

void Tree::deleteNoDescendant(Tree::TreeNode *&element)
{
    delete element;
    element = nullptr;
}

bool Tree::deleteNode(int value, Tree::TreeNode *&element)
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

bool Tree::deleteNodeInSet(int value)
{
    return deleteNode(value, this->root);
}

void Tree::deleteBST(TreeNode *element)
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

Tree::~Tree()
{
    deleteBST(this->root);
}

QString Tree::printStructBST(TreeNode *element, QString result)
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

QString Tree::printStructOfSet()
{
    QString result;
    return printStructBST(this->root, result);
}

QString Tree::printInorderBST(TreeNode *element, QString result)
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

QString Tree::printInorderSet()
{
    QString result;
    return printInorderBST(this->root, result);
}

QString Tree::printReverseInorderBST(TreeNode *element, QString result)
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

QString Tree::printReverseInorderSet()
{
    QString result;
    return printReverseInorderBST(this->root, result);
}

IteratorInterface<int> *Tree::getEnumerator()
{
   return new IteratorBST(this->root);
}

Tree::IteratorBST::IteratorBST(TreeNode *&root) : root(root), current(0)
{
    QVector<TreeNode*> bypass;
    vectorOfBypass = makeBypass(root, bypass);
}

int Tree::IteratorBST::next()
{
    return vectorOfBypass[current++]->value;
}

bool Tree::IteratorBST::isEmpty()
{
    return current == vectorOfBypass.length();
}

void Tree::IteratorBST::reset()
{
    current = 0;
}

void Tree::IteratorBST::remove()
{
    deleteNode(vectorOfBypass[current]->value, root);
    vectorOfBypass.clear();
    vectorOfBypass = makeBypass(root, vectorOfBypass);
    if (current == vectorOfBypass.length() && current > 0)
        current--;

}

QVector<Tree::TreeNode *> Tree::IteratorBST::makeBypass(TreeNode *element, QVector<TreeNode *> arrayBypass)
{
    if (element == nullptr)
    {
        return arrayBypass;
    }
    arrayBypass = makeBypass(element->left, arrayBypass);
    arrayBypass.append(element);
    arrayBypass = makeBypass(element->right, arrayBypass);
    return arrayBypass;
}
