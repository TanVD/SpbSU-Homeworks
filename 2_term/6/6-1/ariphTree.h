#pragma once
#include <QString>

/**
 * @brief The AriphTree class implements binary tree structure.
 */
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
    void createLeftElement(QChar  value);

    /**
     * @brief CreateRightElement Creates right child of node which is current
     * @param value Value to put in node
     */
    void createRightElement(QChar value);

    /**
     * @brief DownLeft Current node is changed to left child of node current at that moment
     */
    void moveToLeftChild();

    /**
     * @brief DownRight Current node is changed to right child of node current at that moment
     */
    void moveToRightChild();

    /**
     * @brief Up Current is changed to parent of node which was current
     */
    void up();

    /**
     * @brief IsLeftFree Checks if the left child is nullptr
     * @return Bool. True if the left child is nullptr, otherwise false.
     */
    bool isLeftFree();

    /**
     * @brief IsRightFree Checks if the right child is nullptr
     * @return Bool. True if the right child is nullptr, otherwise false.
     */
    bool isRightFree();

    /**
     * @brief SetDefault Sets current node to head of tree
     */
    void setDefault();

    /**
     * @brief CalculateTree Returns value of equation of tree
     * @return Int value equal to equation of tree
     */
    int calculateTree();

    /**
     * @brief ValueCurrent Returns char value of current node
     * @return Char value of current node
     */
    QChar valueCurrent();

    /**
     * @brief PrintTree Prints equation of tree
     * @return QString which represents equation of tree
     */
    QString printTree();

private:
    class AriphTreeElement
    {
    public:
        AriphTreeElement(QChar value, AriphTreeElement *ancestor);
        virtual ~AriphTreeElement();
        AriphTreeElement *leftElement;
        AriphTreeElement *rightElement;
        AriphTreeElement *ancestor;
        QChar value;

        void print(QString &stringPrint);

        virtual int calculate() = 0;
    };

    class AriphTreeElementMultiply : public AriphTreeElement
    {
    public:
        AriphTreeElementMultiply(QChar value, AriphTreeElement *ancestor) : AriphTreeElement(value, ancestor)
        {
        }
        int calculate();
    };

    class AriphTreeElementPlus : public AriphTreeElement
    {
    public:
        AriphTreeElementPlus(QChar value, AriphTreeElement *ancestor) : AriphTreeElement(value, ancestor)
        {
        }
        int calculate();
    };

    class AriphTreeElementMinus : public AriphTreeElement
    {
    public:
        AriphTreeElementMinus(QChar value, AriphTreeElement *ancestor) : AriphTreeElement(value, ancestor)
        {
        }
        int calculate();
    };

    class AriphTreeElementDivide : public AriphTreeElement
    {
    public:
        AriphTreeElementDivide(QChar value, AriphTreeElement *ancestor) : AriphTreeElement(value, ancestor)
        {
        }
        int calculate();
    };

    class AriphTreeElementDigit : public AriphTreeElement
    {
    public:
        AriphTreeElementDigit(QChar value, AriphTreeElement *ancestor) : AriphTreeElement(value, ancestor)
        {
        }
        int calculate();
    };

    AriphTreeElement *current;

    AriphTreeElement* chooseChild(QChar value, AriphTreeElement* ancestor);

public:
    AriphTreeElement *head;
};
