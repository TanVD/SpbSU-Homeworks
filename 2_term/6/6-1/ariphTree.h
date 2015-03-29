#pragma once
#include <QString>

class AriphTree
{
public:
    /**
     * @brief AriphTree Creates tree of equation
     * @param value Puts first operation in head
     */
    AriphTree(QChar value);

    ~AriphTree();
    /**
     * @brief CreateLeftElement Creates left child of node which is current
     * @param value Value to put in node
     */
    void CreateLeftElement(QChar  value);
    /**
     * @brief CreateRightElement Creates right child of node which is current
     * @param value Value to put in node
     */
    void CreateRightElement(QChar value);
    /**
     * @brief DownLeft Current node is changed to left child of node which was current
     */
    void DownLeft();
    /**
     * @brief DownRight Current node is changed to right child of node which was current
     */
    void DownRight();
    /**
     * @brief Up Current is changed to parent of node which was current
     */
    void Up();
    /**
     * @brief IsLeftFree Checks if left child is nullptr
     * @return Bool if left child is nullptr
     */
    bool IsLeftFree();
    /**
     * @brief IsRightFree Checks if right child is nullptr
     * @return Bool - right child is nullptr or not
     */
    bool IsRightFree();
    /**
     * @brief SetDefault Sets current node to head of tree
     */
    void SetDefault();
    /**
     * @brief CalculateTree Returns value of equation of tree
     * @return Int value equal to equation of tree
     */
    int CalculateTree();
    /**
     * @brief ValueCurrent Returns char value of current node
     * @return Char value of current node
     */
    QChar ValueCurrent();
    /**
     * @brief PrintTree Prints equation of tree
     * @return QString which represents equation of tree
     */
    QString PrintTree();

private:
    class AriphTreeElement
    {
    public:
        AriphTreeElement(QChar value, AriphTreeElement *ancestor);
        ~AriphTreeElement();
        AriphTreeElement *leftElement;
        AriphTreeElement *rightElement;
        AriphTreeElement *ancestor;
        QChar value;

        void Print(QString &stringPrint);

        int Calculate();
    };

    AriphTreeElement *current;
public:

    AriphTreeElement *head;
};
