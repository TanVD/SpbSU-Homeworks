#pragma once
#include <QString>

class Set
{
public:
    Set();
    ~Set();

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

private:
    class SetNode
    {
    public:
        static void addNode(int value, SetNode *&element);
        int value;
        int counter;
        SetNode* right;
        SetNode* left;
        void updateHeight();
        int height();
        int heightField;
        SetNode(int value);
        int balanceFactor();
        SetNode* balance();
        bool deleteNode(int value);
        SetNode *rotateRight();
        SetNode *rotateLeft();
        bool isExists(int value);
        int modeOfElement();
        int findMinimum();
    };
    SetNode* root;

    static void deleteOneDescendant(Set::SetNode *&element);
    static void deleteCellWithMoreThanOneIn(Set::SetNode *&element);
    static void deleteTwoDescendant(Set::SetNode *&element);
    static void deleteNoDescendant(Set::SetNode *&element);
    static bool deleteNode(int value, Set::SetNode *&element);
    void deleteBST(SetNode *element);
    QString printStructBST(SetNode *element, QString result);
    QString printInorderBST(SetNode *element, QString result);
    QString printReverseInorderBST(SetNode *element, QString result);

};
