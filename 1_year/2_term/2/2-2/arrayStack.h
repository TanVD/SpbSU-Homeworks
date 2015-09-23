#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();
    void push(double number);
    double pop();
    double top();
    bool isEmpty() const;

private:
    double* array;
    int capacity;
    int size;
};

