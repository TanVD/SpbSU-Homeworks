#pragma once

class Stack
{
public:
    virtual ~Stack(){}
    virtual void push(double number) = 0;
    virtual double pop() = 0;
    virtual double top() = 0;
    virtual bool isEmpty() const = 0;
};

