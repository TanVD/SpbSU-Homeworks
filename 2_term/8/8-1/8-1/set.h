#pragma once
#include <BST.h>
#include <QPair>
#include <QVector>

class Set :public BST
{
public:
    /**
     * @brief addNode Adds node in set, maybe more than one
     * @param value value to add
     */
    virtual void addNode(int value);

    /**
     * @brief deleteNode Deletes node from set
     * @param value value to delete
     * @return true if deleted successfull
     */
    virtual bool deleteNode(int value);

private:
    QVector<int> valueVector;
    QVector<int> valueHowMuchTimeVector;
};
