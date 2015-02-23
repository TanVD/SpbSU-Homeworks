#include "infToPostForm.h"
#include "arrayStack.h"
#include "stack.h"
#include <ctype.h>

enum OperationsLabels
{
    plus = 11,
    minus = 12,
    multiply = 21,
    divide = 22,
    openedBracket = 30,
    closedBracket = 40
};


int inputOperation(char operationChar)
{
    int operation = 0;
    switch(operationChar)
    {
        case '+':
        {
            operation = plus;
            break;
        }
        case '-':
        {
            operation = minus;
            break;
        }
        case '*':
        {
            operation = multiply;
            break;
        }
        case '/':
        {
            operation = divide;
            break;
        }
        case '(':
        {
            operation = openedBracket;
            break;
        }
        case ')':
        {
            operation = closedBracket;
            break;
        }
    }
    return operation;
}

char outputOperation(int operationInt)
{
    char operation;
    switch(operationInt)
    {
        case plus:
        {
            operation = '+';
            break;
        }
        case minus:
        {
            operation = '-';
            break;
        }
        case multiply:
        {
            operation = '*';
            break;
        }
        case divide:
        {
            operation = '/';
            break;
        }
    }
    return operation;
}

int infToPostform(char expressionIn[], char expressionPost[], int expressionInEnd)
{
    Stack *operationalStack = new ArrayStack();
    int k = 0;
    for (int i = 0; i < expressionInEnd; i++)
    {
        if (isdigit(expressionIn[i]))
        {
            expressionPost[k] = expressionIn[i];
            k++;
            if (!isdigit(expressionIn[i + 1]))
            {
                expressionPost[k++] = '|';
            }
            continue;
        }
        int operation = inputOperation(expressionIn[i]);
        if (operation == 0)
        {
            return 0;
        }

        if (((operation > operationalStack->top() + 1) && (operation != closedBracket))
                || (operationalStack->top() == openedBracket))
        {
            operationalStack->push(operation);
        }
        else
        {
            while ((operation <= operationalStack->top() + 1) || (operation == closedBracket))
            {
                if ((operationalStack->top() == openedBracket) && (operation == closedBracket))
                {
                    operationalStack->pop();
                    break;
                }

                expressionPost[k] = outputOperation(operationalStack->pop());
                k++;

                if (((operation > operationalStack->top() + 1) && (operation != closedBracket))
                        || ((operationalStack->top() == openedBracket) && (operation != closedBracket)))
                {
                    operationalStack->push(operation);
                    break;
                }
            }
        }
    }

    while (!operationalStack->isEmpty())
    {
        expressionPost[k] = outputOperation(operationalStack->pop());
        k++;
    }
    delete operationalStack;
    return k;
}

