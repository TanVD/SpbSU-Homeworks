#pragma once

struct BSTree;
struct BSTreeNode;

BSTree* createBSTree();

void addNode(int value, BSTree *tree);

bool isExists(int value, BSTree *tree);

bool deleteNode(int value, BSTree *tree);

void printInorderBST(BSTree *tree);

void printStructBST(BSTree *tree);

void printReverseInorderBST(BSTree *tree);

void deleteBST(BSTree *tree);
