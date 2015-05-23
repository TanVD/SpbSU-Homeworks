#include "set.h"

Set::SetNode::SetNode(int value) : TreeNode(value), counter(1), left(nullptr), right(nullptr)
{}

Set::SetNode *Set::SetNode::balance()
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

Set::SetNode *Set::SetNode::rotateRight()
{
    SetNode* pivot = this->left;
    this->left = pivot->right;
    pivot->right = this;
    this->updateHeight();
    pivot->updateHeight();
    return pivot;
}

Set::SetNode *Set::SetNode::rotateLeft()
{
    SetNode* pivot = this->right;
    this->right = pivot->left;
    pivot->left = this;
    this->updateHeight();
    pivot->updateHeight();
    return pivot;
}

BST::TreeNode *Set::SetNode::getLeft()
{
    return left;
}

BST::TreeNode *Set::SetNode::getRight()
{
    return right;
}

int Set::SetNode::modeOfElement()
{
    if (this->counter > 1)
    {
        return moreThanInOneCell;
    }
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

void Set::SetNode::addNode(int value, Set::SetNode *&element)
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
        else if (value == element->value)
        {
            element->counter += 1;
        }
        element = element->balance();
    }
    else
    {
        element = new SetNode(value);
    }
    return;
}

void Set::deleteCellWithMoreThanOneIn(Set::SetNode *&element)
{
    element->counter -= 1;
}

Set::Set() : root(nullptr)
{
}

void Set::addNodeInSet(int value)
{
    SetNode::addNode(value, root);
}

bool Set::deleteNodeInSet(int value)
{
    SetNode::deleteNode(value, root);
}

BST::TreeNode *Set::getRoot()
{
    return root;
}

void Set::deleteOneDescendant(Set::SetNode *&element)
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

void Set::deleteTwoDescendant(Set::SetNode *&element)
{
    int valueMin = element->right->findMinimum();
    SetNode::deleteNode(valueMin, element);
    element->value = valueMin;
}

void Set::deleteNoDescendant(Set::SetNode *&element)
{
    delete element;
    element = nullptr;
}

bool Set::SetNode::deleteNode(int value, Set::SetNode *&element)
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
        case moreThanInOneCell:
        {
            deleteCellWithMoreThanOneIn(element);
            break;
        }
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
