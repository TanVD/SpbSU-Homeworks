#pragma once

/**
 * @brief The Stack class Interface of stack.
 */

class Stack
{
public:
    virtual ~Stack(){}
    /**
     * @brief push Pushes double number to stack structure (virtual)
     * @param number Number to push
     */
    virtual void push(double number) = 0;
    /**
     * @brief pop Pops double numbers from stack structure (virtual)
     * @return Popped number
     */
    virtual double pop() = 0;
    /**
     * @brief top Number on top of stack structure (virtual)
     * @return Number on top
     */
    virtual double top() = 0;
    /**
     * @brief isEmpty Checks whether stack struture empty or not (virtual)
     * @return Bool value whether the stack structure is empty or not
     */
    virtual bool isEmpty() const = 0;
};

