#include "sortedSet.h"
#include "IComparable.h"
#include "iostream"

SortedSet::SortedSet() : head(nullptr), current(head), counter(0)
{
}

SortedSet::~SortedSet()
{
    SetElement* current = head;
    while (current != nullptr)
    {
        SetElement* toDelete = current;
        current = current->sNext;
        delete toDelete->value;
        delete toDelete;
    }
}

void SortedSet::add(IComparable *value)
{
    SetElement* current = head;
    SetElement* previous = current;
    counter++;
    if (current == nullptr || current->value->compareTo(value) > 0)
    {
        head = new SetElement(value, head);
        this->current = head;
        return;
    }
    while ((current->sNext != nullptr) && (current->value->compareTo(value) < 0))
    {
        previous = current;
        current = current->sNext;
    }
    if (current->value->compareTo(value) >= 0)
    {
        previous->sNext = new SetElement(value, previous->sNext);
    }
    else
    {
        current->sNext = new SetElement(value, current->sNext);
    }
    this->current = head;
}

bool SortedSet::remove(IComparable *value)
{
    SetElement *current  = head;
    SetElement *previous  = head;
    while (current != nullptr && current->value->compareTo(value) != 0)
    {
        previous = current;
        current = current->sNext;
    }
    if (current != nullptr)
    {
        SetElement *toDelete = current;
        if (current != head)
            previous->sNext = current->sNext;
        else
            head = current->sNext;
        delete toDelete;
        counter--;
        this->current = head;
        return true;
    }
    return false;
}

bool SortedSet::isInSet(IComparable *value)
{
    SetElement* current  = head;
    while (current != nullptr && current->value != value)
    {
        current = current->sNext;
    }
    if (current != nullptr)
    {
        return true;
    }
    return false;
}

void SortedSet::print()
{
    SetElement* current = head;
    int counter = 1;
    while (current != nullptr)
    {
        std::cout << counter << " : ";
        current->value->print();
        current = current->sNext;
        std::cout << std::endl;
        counter++;
    }
}

IComparable *SortedSet::next()
{
    SetElement* result = current;
    current = current->sNext;
    return result->value;
}


SortedSet::SetElement::SetElement(IComparable *list, SortedSet::SetElement *sNext) : sNext(sNext), value(list)
{
}
