#include "stackdouble.h"
#include "postcalculate.h"

bool isCiph(char letter)
{
    return ((letter <= '9') && (letter >= '0'));
}

double postCalculate(char expressionPost[], int expressionEnd, bool *isValid)
{
    Stack* operationalStack = createStack();
    int number = 0;
    for (int i = 0; i < expressionEnd; i++)
    {
        int operation = expressionPost[i];
        if (expressionPost[i] == '|')
            continue;
        if (isCiph(expressionPost[i]))
        {
            number = (expressionPost[i] - '0') + number * 10;
            if (expressionPost[i + 1] != '|')
                continue;
            push(operationalStack, number);
            number = 0;

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
