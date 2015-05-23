#include "linkedList.h"
#include "list.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr)
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
        return true;
    }
    return false;
}

void LinkedList::print()
{
    ListElement *current = head;
    while (current != nullptr)
    {
        std::cout << current->value << std::endl;
        current = current->lNext;
    }
}

LinkedList::ListElement::ListElement(int value, ListElement *lNext)
{
    this->lNext = lNext;
    this->value = value;
}
