#pragma once
#include "stack.h"
/**
 * @brief The ArrayStack class Stack data structure implemented using array. Inherited from stack interface class.
 */

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();
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
     * @return double number on top of stack
     */
    double top();
    /**
     * @brief isEmpty Checks if stack is empty
     * @return Bool value whether the stack is empty or not
     */
    bool isEmpty() const;

private:
    double* array;
    int capacity;
    int size;
};

