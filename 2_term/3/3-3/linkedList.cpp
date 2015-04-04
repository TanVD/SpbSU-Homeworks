#include "linkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), counter(0)
{
}

LinkedList::~LinkedList()
{
    ListElement* current = head;
    ListElement* toDelete = head;
    while (current != nullptr)
    {
        toDelete = current;
        current = current->lNext;
        delete toDelete;
    }
}

void LinkedList::add(int value)
{
    head = new ListElement(value, head);
    counter++;
}

bool LinkedList::remove(int value)
{
    ListElement *current  = head;
    ListElement *previous  = head;
    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->lNext;
    }
    if (current != nullptr)
    {
        ListElement *toDelete = current;
        if (previous != head)
            previous->lNext = current->lNext;
        else
            head = current->lNext;
        delete toDelete;
        counter--;
        return true;
    }
    return false;
}

void LinkedList::print()
{
    ListElement *current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " " ;
        current = current->lNext;
    }
}

int LinkedList::compareTo(IComparable *that)
{
    if (length() > that->length())
    {
        return 1;
    }
    else if (length() < that->length())
    {
        return -1;
    }
    return 0;
}

int LinkedList::length()
{
    return counter;
}


LinkedList::ListElement::ListElement(int value, ListElement *lNext) : lNext(lNext), value(value)
{
}
