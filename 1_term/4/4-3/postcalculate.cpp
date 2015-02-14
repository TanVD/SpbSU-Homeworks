#include <iostream>
#include "stackdouble.h"
#include <string>
#include "postcalculate.h"

using namespace std;

bool isCipher(char letter)
{
    return ((letter <= '9') && (letter >= '0'));
}

double postCalculate(char expressionPost[], int expressionEnd, bool *isValid)
{
    Stack* operationalStack = createStack();

    for (int i = 0; i < expressionEnd; i++)
    {
        int operation = expressionPost[i];

        if (isCipher(expressionPost[i]))
        {
            push(operationalStack, (expressionPost[i] - '0'));
            continue;
        }

        double tmpSecond = pop(operationalStack);
        double tmpFirst = pop(operationalStack);
        switch(operation)
        {
            case '+':
            {
                push(operationalStack, tmpFirst + tmpSecond);
                break;
            }
            case '-':
            {
                push(operationalStack, tmpFirst - tmpSecond);
                break;
            }
            case '*':
            {
                push(operationalStack, tmpFirst * tmpSecond);
                break;
            }
            case '/':
            {
                if (tmpSecond == 0)
                {
                    *isValid = false;
                    return 0;
                }
                push(operationalStack, tmpFirst / tmpSecond);
                break;
            }
        }
    }
    double result = pop(operationalStack);
    deleteStack(operationalStack);
    return result;
}
