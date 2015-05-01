#include "list.h"


List::List() : lengthField(0), head(nullptr)
{
}

List::~List()
{
    ListElement* current = head;
    while (current != nullptr)
    {
        ListElement* toDelete = current;
        current = current->lNext;
        delete toDelete;
    }
    lengthField = 0;
}

void List::add(int value)
{
    head = new ListElement(value, head);
    lengthField++;
}

void List::add(int value, int index)
{
    if (index != 0)
    {
        ListElement* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->lNext;
        }
        current->lNext = new ListElement(value, current->lNext);
        lengthField++;
    }
    else
    {
        add(value);
    }
}

int List::index(int index)
{
    ListElement* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->lNext;
    }
    return current->value;
}

void List::removeValue(int value)
{
    ListElement* current = head;
    ListElement* previous = head;
    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->lNext;
    }
    if (current != nullptr)
    {
        if (current != head)
            previous->lNext = current->lNext;
        else
            head = current->lNext;
        lengthField--;
    }
}

void List::removeIndex(int index)
{
    if (index != 0)
    {
        ListElement* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->lNext;
        }
        current->lNext = current->lNext->lNext;
    }
    else
    {
        head = head->lNext;
    }
    lengthField--;
}

bool List::isExistsIndex(int index)
{
    return (lengthField >= index);
}

bool List::isInList(int value)
{
    ListElement* current = head;
    while (current != nullptr && current->value != value)
    {
        current = current->lNext;
    }
    return current != nullptr;
}

void List::print()
{
    ListElement* current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->lNext;
    }
}

int List::length()
{
    return lengthField;
}
