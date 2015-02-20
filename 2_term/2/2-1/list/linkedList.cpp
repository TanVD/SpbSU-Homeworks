#include "linkedList.h"
#include "list.h"
#include <iostream>

LinkedList::LinkedList()
{
    this->head = nullptr;
}

LinkedList::~LinkedList()
{
    ListElement* current = this->head;
    ListElement* toDelete = this->head;
    while (current != nullptr)
    {
        toDelete = current;
        current = current->lNext;
        delete toDelete;
    }
}

void LinkedList::add(int value)
{
    this->head = new ListElement(value, this->head);
}

bool LinkedList::remove(int value)
{
    ListElement *current  = this->head;
    ListElement *previous  = this->head;
    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->lNext;
    }
    if (current != nullptr)
    {
        ListElement *toDelete = current;
        previous->lNext = current->lNext;
        delete toDelete;
        return true;
    }
    return false;
}

void LinkedList::print()
{
    ListElement *current = this->head;
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
