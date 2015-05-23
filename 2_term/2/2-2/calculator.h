#pragma once

class Calculator
{
public:
    Calculator();
    ~Calculator();
    void calculate(char* equation, int length);
    double returnResult();
    bool isResultValid();

private:
    char* equation;
    double result;
    bool valid;
    static double postCalculate(char expressionPost[], int expressionEnd, bool *isValid);
    static int infToPostform(char expressionIn[], char expressionPost[], int expressionInEnd);
    static char outputOperation(int operationInt);
    static int inputOperation(char operationChar);

};

