#pragma once
#include "list.h"

/**
 * @brief The LinkedList class Class of Linked List.
 */

class LinkedList : public List
{
public:
    LinkedList();
    ~LinkedList();
    /**
     * @brief add Adds element to Linked List.
     * @param value Value to add.
     */
    void add(int value);
    /**
     * @brief remove Removes element from Linked List.
     * @param value Value to remove.
     * @return True if value was succesfully removed, false if not.
     */
    bool remove(int value);
    /**
     * @brief print Prints all elements of Linked List starting with head.
     */
    void print();
    /**
     * @brief isEmpty Return true if Linked List is empty
     * @return Bool whether Linked List empty or not.
     */
    bool isEmpty();
    /**
     * @brief pop Pops value from linked list, need for Hash Table reconstruction.
     * @return Returns popped value.
     */
    int pop();
    /**
     * @brief length Returns length of Linked List
     * @return Length of Linked List.
     */
    int length();
    /**
     * @brief isExists Returns true if value is in the Linked List, false if not
     * @param value Value to find.
     * @return Bool whether value is in Linked List or not.
     */
    bool isExists(int value);

private:
    class ListElement
    {
    public:
        int value;
        ListElement(int value, ListElement* lNext);
        ListElement* lNext;
    };
    int lengthField;
    ListElement* head;
};

