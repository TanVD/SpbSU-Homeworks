#pragma once

struct BSTreeNode;

struct BSTree;

BSTree* createBSTree(char equation[]);

void addNode(char value, BSTreeNode *element, int mode);

void printStructBST(BSTree *tree);

void printInorderBST(BSTree *tree);

double countTree(BSTree *tree);

void deleteBST(BSTree *tree);
