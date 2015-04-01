#include "calculatorSimple.h"

CalculatorSimple::CalculatorSimple() : result(0), firstArgument(0), secondArgument(0), operation(0)
{
}

int CalculatorSimple::getResult()
{
    return result;
}

void CalculatorSimple::setFirstArgument(int value)
{
    firstArgument = value;
    calc();
}

void CalculatorSimple::setSecondArgument(int value)
{
    secondArgument = value;
    calc();
}

void CalculatorSimple::setOperation(int value)
{
    operation = value;
    calc();
}

enum OperationsLabels
{
    plus = 0,
    minus = 1,
    multiply = 2,
    divide = 3
};

void CalculatorSimple::calc()
{
    switch (operation) {
    case plus:
    {
        result = firstArgument + secondArgument;
        break;
    }
    case minus:
    {
        result = firstArgument - secondArgument;
        break;
    }
    case multiply:
    {
        result = firstArgument * secondArgument;
        break;
    }
    case divide:
    {
        if (secondArgument != 0)
            result = firstArgument / secondArgument;
        else
            result = 0;
        break;
    }
    }
}

