#pragma once

#include "stack.h"
class StackDouble : public Stack
{
public:
    StackDouble();
    ~StackDouble();
    void push(double number);
    double pop();
    double top();
    bool isEmpty() const;

private:
    class StackElement
    {
    public:
        double value;
        StackElement *next;
        StackElement(double value, StackElement* next);
    };
    StackElement* head;

};
