#include "postCalculate.h"
#include "stackDouble.h"
#include "stack.h"
#include <ctype.h>

double postCalculate(char expressionPost[], int expressionEnd, bool *isValid)
{
    int symbol = 0;
    Stack *operationalStack = new StackDouble();
    *isValid = true;
    for (int i = 0; i < expressionEnd; i++)
    {
        int operation = expressionPost[i];
        if (expressionPost[i] == '|')
            continue;
        if (isdigit(expressionPost[i]))
        {
            symbol = (expressionPost[i] - '0') + symbol * 10;
            if (expressionPost[i + 1] != '|')
                continue;
            operationalStack->push(symbol);
            symbol = 0;
            continue;
        }
        double tmpSecond = operationalStack->pop();
        double tmpFirst = operationalStack->pop();
        switch(operation)
        {
            case '+':
            {
                operationalStack->push(tmpFirst + tmpSecond);
                break;
            }
            case '-':
            {
                operationalStack->push(tmpFirst - tmpSecond);
                break;
            }
            case '*':
            {
                operationalStack->push(tmpFirst * tmpSecond);
                break;
            }
            case '/':
            {
                if (tmpSecond == 0)
                {
                    *isValid = false;
                    return 0;
                }
                operationalStack->push(tmpFirst / tmpSecond);
                break;
            }
        }
    }
    double result = operationalStack->pop();
    delete operationalStack;
    return result;
}
