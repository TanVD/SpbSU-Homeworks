#include "arrayStack.h"

ArrayStack::ArrayStack()
{
    this->array = new double[2];
    this->capacity = 2;
    this->size = 0;
}

ArrayStack::~ArrayStack()
{
    delete[] this->array;
}

void ArrayStack::push(double number)
{
    if (this->size == this->capacity)
    {
        double* newArray = new double[this->capacity * 2];
        for (int i = 0; i < this->capacity; i++)
        {
            newArray[i] = this->array[i];
        }
        this->capacity = this->capacity * 2;
        delete[] this->array;
        this->array = newArray;
    }
    for (int i = this->size; i > 0; i--)
    {
        this->array[i] = this->array[i - 1];
    }
    this->array[0] = number;
    this->size = this->size + 1;
}

double ArrayStack::pop()
{
    int result = this->array[0];
    for (int i = 0; i < this->size; i++)
    {
        this->array[i] = this->array[i + 1];
    }
    this->size = this->size - 1;
    this->array[this->size] = 0;
    if (this->size == this->capacity/2 &&
            this->capacity % 2 == 0 && this->capacity / 2 != 0)
    {
        double* newArray = new double[this->size];
        for (int i = 0; i < this->size; i++)
        {
            newArray[i] = this->array[i];
        }
        this->capacity = this->capacity / 2;
        delete[] this->array;
        this->array = newArray;
    }
    return result;
}

double ArrayStack::top()
{
    return this->array[0];
}

bool ArrayStack::isEmpty() const
{
    return this->size == 0;
}

