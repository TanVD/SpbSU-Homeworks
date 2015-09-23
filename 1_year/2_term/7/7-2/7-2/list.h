#pragma once
#include <iostream>

/**
 * @brief List class which implements structure of linked list.
 */
class List
{
public:

    List();

    virtual ~List();

    /**
     * @brief add Add the specified value to this instance of List.
     * @param value Value to add.
     */
    virtual void add(int value);

    /**
     * @brief add Add the specified value to this instance of List to the place determined by index.
     * @param value Value to add.
     * @param index Index.
     */
    virtual void add(int value, int index);

    /**
     * @brief index Returns specified by index value.
     * @param index Index.
     * @return Value specified by index.
     */
    int index(int index);

    /**
     * @brief remove Value Removes the value form this instance of List.
     * @param value Value to remove.
     */
    virtual void removeValue(int value);

    /**
     * @brief removeIndex Removes the value specified by index.
     * @param index Index.
     */
    virtual void removeIndex(int index);

    /**
     * @brief isExistsIndex Determines whether in this instance exists the specified index.
     * @param index Index to find.
     * @return true if in this instance exists the specified index; otherwise, false.
     */
    bool isExistsIndex(int index);

    /**
     * @brief isInList Determines whether this value is in list.
     * @param value Value to find.
     * @return true if this value is in list; otherwise, false.
     */
    bool isInList(int value);

    /**
     * @brief print Print this instance.
     */
    void print();

    /**
     * @brief length Length of this instance.
     * @return Length of this instance
     */
    int length();

private:
    class ListElement
    {
    public:
        int value;

        ListElement* lNext;

        ListElement(int value, ListElement* lNext) : lNext(lNext), value(value)
        {
        }
    };
    ListElement* head;
    int lengthField;
};
