#pragma once
#include <BST.h>

class Set : public BST
{
public:
    Set();
    virtual void addNodeInSet(int value);
    virtual bool deleteNodeInSet(int value);

private:
    class SetNode : public TreeNode
    {
    public:
        int counter;
        SetNode(int value);
        SetNode* left;
        SetNode* right;
        SetNode* balance();
        SetNode *rotateRight();
        SetNode *rotateLeft();
        TreeNode* getLeft();
        TreeNode* getRight();
        int modeOfElement();
        static void addNode(int value, SetNode *&element);
        static bool deleteNode(int value, SetNode *&element);
    };

    enum modesElementAdd
    {
        moreThanInOneCell = 3
    };
    SetNode* root;
    TreeNode* getRoot();
    static void deleteCellWithMoreThanOneIn(SetNode *&element);

    static void deleteOneDescendant(SetNode *&element);
    static void deleteTwoDescendant(SetNode *&element);
    static void deleteNoDescendant(SetNode *&element);


};
