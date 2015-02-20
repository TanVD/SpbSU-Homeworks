#include "doubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
    this->head = nullptr;
}

DoubleLinkedList::~DoubleLinkedList()
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

void DoubleLinkedList::add(int value)
{
    ListElement* newElement = new ListElement(value, this->head, nullptr);
    if (this->head != nullptr)
    {
        this->head->lPrevious = newElement;
    }
    this->head = newElement;
}

bool DoubleLinkedList::remove(int value)
{
    ListElement* current = this->head;
    while (current != nullptr && current->value != value)
    {
        current = current->lNext;
    }
    if (current != nullptr)
    {
        ListElement *toDelete = current;
        current->lPrevious->lNext = current->lNext;
        current->lNext->lPrevious = current->lPrevious;
        delete toDelete;
        return true;
    }
    return false;
}

void DoubleLinkedList::print()
{
    ListElement *current = this->head;
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
