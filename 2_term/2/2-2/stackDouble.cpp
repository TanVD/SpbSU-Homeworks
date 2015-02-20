#include "stackDouble.h"

StackDouble::StackElement::StackElement(double value, StackElement* next)
{
    this->next = next;
    this->value = value;
}

StackDouble::StackDouble()
{
    head = nullptr;
}

void StackDouble::push(double value)
{
    head = new StackElement(value, head);
}

double StackDouble::pop()
{
    double result = head->value;
    StackElement *delElement = head;
    head = head->next;
    delete delElement;
    return result;
}


double StackDouble::top()
{
    if (head != nullptr)
    {
        return head->value;
    }
    else
    {
        return -1;
    }

}

bool StackDouble::isEmpty() const
{
    return head == nullptr;
}

StackDouble::~StackDouble()
{
    while (!isEmpty())
    {
        pop();
    }
}
