#pragma once
#include <QString>

class BST
{
public:
    BST();
    virtual ~BST();

    /**
     * @brief addNodeInSet Adds new value in set
     * @param value Value to add
     */
     virtual void addNode(int value);

    /**
     * @brief isExistsInSet Determines if value is in set
     * @param value Value to find
     * @return True if value is in set, otherwise false
     */
    bool isExists(int value);

    /**
     * @brief deleteNodeInSet Deletes node of set specified by value, if there are more than one equal value in set, it decrements counter of node.
     * @param value Value to delete, specified by index
     * @return True if value was deleted, otherwise false
     */
    virtual bool deleteNode(int value);

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

private:

    enum modesElement
    {
        noDescendant = 0,
        oneDescendant = 1,
        twoDescendant = 2
    };

    class TreeNode
    {
    public:
        int value;
        void updateHeight();
        int height();
        int heightField;
        TreeNode(int value);
        int balanceFactor();
        TreeNode* balance();
        TreeNode *rotateRight();
        TreeNode *rotateLeft();
        bool isExists(int value);
        int modeOfElement();
        int findMinimum();
        static void addNode(int value, TreeNode *&element);
        static bool deleteNode(int value, BST::TreeNode *&element);
        TreeNode* right;
        TreeNode* left;
    };

    void deleteBST(TreeNode *element);
    QString printStructBST(TreeNode *element, QString result);
    QString printInorderBST(TreeNode *element, QString result);
    QString printReverseInorderBST(TreeNode *element, QString result);
private:
    TreeNode* root;
    static void deleteOneDescendant(BST::TreeNode *&element);
    static void deleteCellWithMoreThanOneIn(BST::TreeNode *&element);
    static void deleteTwoDescendant(BST::TreeNode *&element);
    static void deleteNoDescendant(BST::TreeNode *&element);

};
