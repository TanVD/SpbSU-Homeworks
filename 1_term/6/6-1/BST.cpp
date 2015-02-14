#include <stdio.h>
#include "BST.h"

struct BSTreeNode
{
    int value;
    BSTreeNode* right;
    BSTreeNode* left;
};

struct BSTree
{
    BSTreeNode* root;
};

BSTreeNode* createNewElement(int value)
{
    BSTreeNode* newElement = new BSTreeNode;
    newElement->value = value;
    newElement->left = nullptr;
    newElement->right = nullptr;
    return newElement;
}

BSTree* createBSTree()
{
    BSTree *tree = new BSTree;
    tree->root = nullptr;
    return tree;
}

void addNode(int value, BSTreeNode *&element)
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
    }
    else
    {
        element = createNewElement(value);
    }
    return;
}

void addNode(int value, BSTree *tree)
{
    addNode(value, tree->root);
}

bool isExists(int value, BSTreeNode *element)
{
    if (element == nullptr)
    {
        return false;
    }
    else if (value < element->value)
    {
        return isExists(value, element->left);
    }
    else if (value > element->value)
    {
        return isExists(value, element->right);
    }
    return true;
}

bool isExists(int value, BSTree *tree)
{
    return isExists(value, tree->root);
}

bool deleteNode(int value, BSTreeNode *&element);

enum modesElement
{
    noDescendant = 0,
    oneDescendant = 1,
    twoDescendant = 2
};

int modeOfElement(BSTreeNode *&element)
{
    if ((element->left == nullptr) && (element->right == nullptr))
    {
        return noDescendant;
    }
    if ((element->left == nullptr) || (element->right == nullptr))
    {
        return oneDescendant;
    }
    return twoDescendant;
}

int findMinimum(BSTreeNode* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node->value;
}

void deleteOneDescendant(BSTreeNode *&element)
{
    BSTreeNode* tempElement = new BSTreeNode;
    tempElement = element;
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

void deleteTwoDescendant(BSTreeNode *&element)
{
    int valueMin = findMinimum(element->right);
    deleteNode(valueMin, element);
    element->value = valueMin;
}

void deleteNoDescendant(BSTreeNode *&element)
{
    delete element;
    element = nullptr;
}

bool deleteNode(int value, BSTreeNode *&element)
{
    if (element == nullptr)
    {
        return false;
    }
    if (value > element->value)
    {
        deleteNode(value, element->right);
    }
    else if (value < element->value)
    {
        deleteNode(value, element->left);
    }
    else if (value == element->value)
    {
        switch (modeOfElement(element))
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

bool deleteNode(int value, BSTree *tree)
{
    return deleteNode(value, tree->root);
}

void deleteBST(BSTreeNode *element)
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

void deleteBST(BSTree *tree)
{
    deleteBST(tree->root);
    delete tree;
}

void printStructBST(BSTreeNode *element)
{
    if (element != nullptr)
    {
        printf("%d ", element->value);
    }
    else
    {
        printf("NULL ");
        return;
    }
    printf("(");
    printStructBST(element->left);
    printStructBST(element->right);
    printf(")");
    return;

}

void printStructBST(BSTree *tree)
{
    printStructBST(tree->root);
}

void printInorderBST(BSTreeNode *element)
{
    if (element == nullptr)
    {
        return;
    }
    printInorderBST(element->left);
    printf("%d ", element->value);
    printInorderBST(element->right);
    return;

}

void printInorderBST(BSTree *tree)
{
    printInorderBST(tree->root);
}

void printReverseInorderBST(BSTreeNode *element)
{
    if (element == nullptr)
    {
        return;
    }
    printReverseInorderBST(element->right);
    printf("%d ", element->value);
    printReverseInorderBST(element->left);
    return;
}

void printReverseInorderBST(BSTree *tree)
{
    printReverseInorderBST(tree->root);
}

