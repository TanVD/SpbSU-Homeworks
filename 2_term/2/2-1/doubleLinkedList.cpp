#include "doubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() : head(nullptr)
{
}

DoubleLinkedList::~DoubleLinkedList()
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

void DoubleLinkedList::add(int value)
{
    ListElement* newElement = new ListElement(value, head, nullptr);
    if (head != nullptr)
    {
        head->lPrevious = newElement;
    }
    head = newElement;
}

bool DoubleLinkedList::remove(int value)
{
    ListElement* current = head;
    while (current != nullptr && current->value != value)
    {
        current = current->lNext;
    }
    if (current != nullptr)
    {
        ListElement *toDelete = current;
        if (current != head)
        {
            current->lPrevious->lNext = current->lNext;
            if (current->lNext != nullptr)
                current->lNext->lPrevious = current->lPrevious;
        }
        else
        {
            head = current->lNext;
        }
        delete toDelete;
        return true;
    }
    return false;
}

void DoubleLinkedList::print()
{
    ListElement *current = head;
    while (current != nullptr)
    {
        std::cout << current->value << std::endl;
        current = current->lNext;
    }
}



DoubleLinkedList::ListElement::ListElement(int value, ListElement *lNext, ListElement *lPrevious)
{
    this->lNext = lNext;
    this->value = value;
    this->lPrevious = lPrevious;
}
