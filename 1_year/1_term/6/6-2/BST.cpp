#include <stdio.h>
#include "BST.h"

struct BSTreeNode
{
    char value;
    BSTreeNode* ancestor;
    BSTreeNode* right;
    BSTreeNode* left;
};

struct BSTree
{
    BSTreeNode* root;
};

BSTreeNode* createNewElement(char value)
{
    BSTreeNode* newElement = new BSTreeNode;
    newElement->value = value;
    newElement->left = nullptr;
    newElement->right = nullptr;
    return newElement;
}

enum directionMode
{
    left = 1,
    right = 2
};

void addNode(char value, BSTreeNode *element, int mode)
{
    if (mode == left)
    {
        element->left = createNewElement(value);
        element->left->ancestor = element;
    }
    else if (mode == right)
    {
        element->right = createNewElement(value);
        element->right->ancestor = element;
    }
    return;
}

BSTree* buildTree (BSTree *tree, char equation[])
{

    BSTreeNode *currentNode = new BSTreeNode;
    currentNode = tree->root;
    int mode = left;
    int i = 2;
    while (equation[i] != '\0')
    {
        if (equation[i] == '(')
        {
            i++;
            addNode(equation[i], currentNode, mode);
            if (mode == left)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
            mode = left;
            i++;
            continue;
        }
        if (equation[i] <= '9' && equation[i] >= '0')
        {
            if (mode == left)
            {
                addNode(equation[i], currentNode, left);
                i++;
                mode = right;
            }
            else
            {
                addNode(equation[i], currentNode, right);
                i++;
                mode = left;
            }
            continue;
        }
        if (equation[i] == ')')
        {
            currentNode = currentNode->ancestor;
            if (currentNode == nullptr)
            {
                break;
            }
            i++;
            mode = right;
            continue;
        }
        i++;
    }
    return tree;
}

BSTree* createBSTree(char equation[])
{
    BSTree *tree = new BSTree;
    tree->root = new BSTreeNode;
    tree->root->value = equation[1];
    tree->root->ancestor = nullptr;
    tree->root->left = nullptr;
    tree->root->right = nullptr;
    tree = buildTree(tree, equation);
    return tree;
}

void printStructBST(BSTreeNode *element)
{
    if (element != nullptr)
    {
        printf("%c ", element->value);
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
    if ((element->left != nullptr) && (element->right != nullptr))
        printf("(");
    printInorderBST(element->left);
    printf("%c", element->value);
    printInorderBST(element->right);
    if ((element->left != nullptr) && (element->right != nullptr))
        printf(")");
    return;

}

void printInorderBST(BSTree *tree)
{
    printInorderBST(tree->root);
}

double countInt(BSTreeNode *element)
{
    if ((element->left == nullptr) && (element->right == nullptr))
    {
        return element->value - '0';
    }
    double x = countInt(element->left);
    double x1 = countInt(element->right);
    char c = element->value;
    switch (c)
    {
    case '+':
    {
        return x + x1;
        break;
    }
    case '-':
    {
        return x - x1;
        break;
    }
    case '*':
    {
        return x * x1;
        break;
    }
    case '/':
    {
        return x / x1;
        break;
    }
    }
    return 0;
}

double countTree(BSTree * tree)
{
    return countInt(tree->root);
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

