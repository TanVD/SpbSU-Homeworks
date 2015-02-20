#pragma once
#include "list.h"

class DoubleLinkedList : public List
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void add(int value);
    bool remove(int value);
    void print();

private:
    class ListElement
    {
    public:
        int value;
        ListElement(int value, ListElement* lNext, ListElement* lPrevious);
        ListElement* lNext;
        ListElement* lPrevious;
    };

    ListElement* head;
};

