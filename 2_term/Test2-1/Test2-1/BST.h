#pragma once
#include <QString>
#include <QVector>
#include "iteratorinterface.h"

class Tree
{
public:
    Tree();
    ~Tree();

    /**
     * @brief addNodeInSet Adds new value in set
     * @param value Value to add
     */
    void addNodeInSet(int value);

    /**
     * @brief isExistsInSet Determines if value is in set
     * @param value Value to find
     * @return True if value is in set, otherwise false
     */
    bool isExistsInSet(int value);

    /**
     * @brief deleteNodeInSet Deletes node of set specified by value, if there are more than one equal value in set, it decrements counter of node.
     * @param value Value to delete, specified by index
     * @return True if value was deleted, otherwise false
     */
    bool deleteNodeInSet(int value);

    /**
     * @brief printInorderSet Prints set inorder
     */
    QString printInorderSet();

    /**
     * @brief printStructOfSet Prints set as struct
     */
    QString printStructOfSet();

    /**
     * @brief printReverseInorderSet Prints set inorder reverse
     */
    QString printReverseInorderSet();

    /**
     * @brief getEnumerator Returns inorder enumerator of tree
     * @return IteratorInterface object
     */
    IteratorInterface<int>* getEnumerator();

private:
    class TreeNode
    {
    public:
        static void addNode(int value, TreeNode *&element);
        int value;
        TreeNode* right;
        TreeNode* left;
        void updateHeight();
        int height();
        int heightField;
        TreeNode(int value);
        int balanceFactor();
        TreeNode* balance();
        bool deleteNode(int value);
        TreeNode *rotateRight();
        TreeNode *rotateLeft();
        bool isExists(int value);
        int modeOfElement();
        int findMinimum();
    };
    TreeNode* root;

    static void deleteOneDescendant(Tree::TreeNode *&element);
    static void deleteTwoDescendant(Tree::TreeNode *&element);
    static void deleteNoDescendant(Tree::TreeNode *&element);
    static bool deleteNode(int value, Tree::TreeNode *&element);
    void deleteBST(TreeNode *element);
    QString printStructBST(TreeNode *element, QString result);
    QString printInorderBST(TreeNode *element, QString result);
    QString printReverseInorderBST(TreeNode *element, QString result);

    class IteratorBST : public IteratorInterface<int>
    {
    public:
        IteratorBST(TreeNode*& root);
        int next();
        bool isEmpty();
        void reset();
        void remove();
    private:
        QVector<TreeNode*> makeBypass(TreeNode* element, QVector<TreeNode*> arrayBypass);
        int current;
        QVector<TreeNode*> vectorOfBypass;
        TreeNode*& root;
    };

};
