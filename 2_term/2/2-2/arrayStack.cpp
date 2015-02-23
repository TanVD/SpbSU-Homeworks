#include "arrayStack.h"

ArrayStack::ArrayStack() : capacity(2), size (0), array(new double[2])
{
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

void ArrayStack::push(double number)
{
    if (size == capacity)
    {
        double* newArray = new double[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            newArray[i] = array[i];
        }
        capacity = capacity * 2;
        delete[] array;
        array = newArray;
    }
    for (int i = size; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = number;
    size = size + 1;
}

double ArrayStack::pop()
{
    int result = array[0];
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    size = size - 1;
    array[size] = 0;
    if (size == capacity/ 2 &&
            capacity % 2 == 0 && capacity / 2 != 0)
    {
        double* newArray = new double[size];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        capacity = capacity / 2;
        delete[] array;
        array = newArray;
    }
    return result;
}

double ArrayStack::top()
{
    return array[0];
}

bool ArrayStack::isEmpty() const
{
    return size == 0;
}

