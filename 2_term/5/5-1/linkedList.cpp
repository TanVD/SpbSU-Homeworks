#include "linkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), lengthField(0)
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
    lengthField++;
}

bool LinkedList::isInList(int value)
{
    ListElement* current  = head;
    while (current != nullptr && current->value != value)
    {
        current = current->lNext;
    }
    if (current != nullptr)
    {
        return true;
    }
    return false;
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
        if (current != head)
            previous->lNext = current->lNext;
        else
            head = current->lNext;
        delete toDelete;
        lengthField--;
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

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

int LinkedList::pop()
{
    int result = this->head->value;
    this->remove(this->head->value);
    lengthField--;
    return result;
}

int LinkedList::length()
{
    return lengthField;
}

bool LinkedList::isExists(int value)
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
        return true;
    }
    return false;
}

LinkedList::ListElement::ListElement(int value, ListElement *lNext)
{
    this->lNext = lNext;
    this->value = value;
}
