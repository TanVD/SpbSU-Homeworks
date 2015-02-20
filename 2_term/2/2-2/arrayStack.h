#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();
public:
    void push(double number);
    double pop();
    double top();
    bool isEmpty() const;

private:
    double* array;
    int capacity;
    int size;
};

