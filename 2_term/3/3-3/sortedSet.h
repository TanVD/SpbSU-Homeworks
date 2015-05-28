#pragma once
#include "IComparable.h"
#include "linkedList.h"

/**
 * @brief The SortedSet class Sorted List of IComparable descendants.
 */

class SortedSet
{
public:
    SortedSet();
    ~SortedSet();

    /**
     * @brief add Adds new element to List. Maintain List sorted.
     * @param value Value is object of IComparable descendant class
     */
    void add(IComparable* value);

    /**
     * @brief remove Removes value from the list. Maintain List sorted.
     * @param value Value is object of IComparable descendant class
     * @return Return bool. True if value was found and deleted and false if value wasn't found
     */
    bool remove(IComparable* value);

    /**
     * @brief isInSet Checks whether value in list
     * @param value Value to find
     * @return True if value is in list, otherwise false
     */
    bool isInSet(IComparable* value);

    /**
     * @brief print Prints elements of SortedSet using virtual method print in IComparable objects.
     */
    void print();

    /**
     * @brief next Used to iterate through structure.
     * @return next value in set starting with head
     */
    IComparable* next();
private:
    class SetElement
    {
    public:
        IComparable* value;
        SetElement(IComparable* list, SetElement* sNext);
        SetElement* sNext;
    };
    int counter;
    SetElement *head;
    SetElement *current;
};

