#pragma once
#include "IComparable.h"

/**
 * @brief The LinkedList class Implements Linked List structure
 */
class LinkedList : public IComparable
{
public:
    LinkedList();
    ~LinkedList();
    /**
     * @brief add Method adding new value in head of list
     * @param value Int value to be added
     */
    void add(int value);
    /**
     * @brief remove Method deleting specific value in list
     * @param value Int value to be deleted
     * @return Return bool. True if value was found and deleted and false if value wasn't found
     */
    bool remove(int value);
    /**
     * @brief print Implementation of virtual method from IComparable. Prints elements of LinkedList.
     */
    void print();
    /**
     * @brief compareTo Implementation of cirtual method from IComparable. Compares LinkedList to other descendant of IComparable.
     * @param that IComparable object brought to compare with
     * @return Int (1, 0, -1) 1 if this > that, 0 if this == that, -1 if this < that
     */
    int compareTo(IComparable* that);
    /**
     * @brief length Implementation of virtual method returnin length used for comparation
     * @return Int value used for comparation
     */
    int length();

private:
    class ListElement
    {
    public:
        int value;
        ListElement(int value, ListElement* lNext);
        ListElement* lNext;
    };

    int counter;
    ListElement* head;
};

