#include "set.h"


void Set::addNode(int value)
{
    if (this->isExists(value))
    {
        valueHowMuchTimeVector[valueVector.indexOf(value)] += 1;
    }
    else
    {
        BST::addNode(value);
        valueVector.append(value);
        valueHowMuchTimeVector.append(1);
    }
}

bool Set::deleteNode(int value)
{
    int index = valueVector.indexOf(value);
    if (index != -1)
    {
        valueHowMuchTimeVector[index] -= 1;
        if (valueHowMuchTimeVector[index] == 0)
        {
            valueHowMuchTimeVector.remove(index);
            valueVector.remove(index);
            BST::deleteNode(value);
        }
        return true;
    }
    return false;
}
