#pragma once

class CalculatorSimple
{
public:
    CalculatorSimple();
    int getResult();
    void setFirstArgument(int value);
    void setSecondArgument(int value);
    void setOperation(int value);
private:
    void calc();
    int result;
    int firstArgument;
    int secondArgument;
    int operation;
};

