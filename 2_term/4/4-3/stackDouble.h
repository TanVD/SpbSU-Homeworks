#pragma once
#include "stack.h"

/**
 * @brief The StackDouble class The ArrayStack class Stack data structure implemented using pointers. Inherited from stack interface class.
 */

class StackDouble : public Stack
{
public:
    StackDouble();
    ~StackDouble();
    /**
     * @brief push Pushes double number in stack
     * @param number Number to push
     */
    void push(double number);
    /**
     * @brief pop Pop double number from stack
     * @return  Popped double number
     */
    double pop();
    /**
     * @brief top Top double number on stack
     * @return Double number on top of stack
     */
    double top();
    /**
     * @brief isEmpty Checks if stack is empty
     * @return Bool value whether the stack is empty or not
     */
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
