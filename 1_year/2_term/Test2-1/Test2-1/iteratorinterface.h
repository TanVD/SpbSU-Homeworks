#pragma once

template <typename T>
class IteratorInterface
{
public:

    /**
     * @brief next Returns next value of collection
     * @return  T type
     */
    virtual T next() = 0;

    /**
     * @brief isEmpty Returns true if it was last element
     * @return Bool
     */
    virtual bool isEmpty() = 0;

    /**
     * @brief reset Set current element on first
     */
    virtual void reset() = 0;

    /**
     * @brief remove Removes next element
     */
    virtual void remove() = 0;
};

