#pragma once
#include "list.h"


class LinkedList : public List
{
public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    bool remove(int value);
    void print();

private:
    class ListElement
    {
    public:
        int value;
        ListElement(int value, ListElement* lNext);
        ListElement* lNext;
    };

    ListElement* head;
};

