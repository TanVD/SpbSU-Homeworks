#pragma once

class calculator
{
public:
    calculator();
    ~calculator();
    void calculate(char* equation, int length);
    double returnResult();
    bool isResultValid();

private:
    char* equation;
    double result;
    bool valid;

};

