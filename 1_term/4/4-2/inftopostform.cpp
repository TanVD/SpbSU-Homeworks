#include "inftopostform.h"
#include "stackdouble.h"

enum operationsLabels {plus = 11, minus = 12, multiply = 21, divide = 22, opBracket = 30, clBracket = 40};

int inputOperation(char operationChar)
{
    int operation;
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
            operation = opBracket;
            break;
        }
        case ')':
        {
            operation = clBracket;
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

bool isCipher(char letter)
{
    return ((letter <= '9') && (letter >= '0'));
}

int infToPostForm(char expressionIn[], char expressionPost[], int expressionInEnd)
{
    Stack* operationalStack = createStack();
    int k = 0;

    for (int i = 0; i < expressionInEnd; i++)
    {
        int operation = inputOperation(expressionIn[i]);

        if (isCipher(expressionIn[i]))
        {
            expressionPost[k] = expressionIn[i];
            k++;
            if (!isCipher(expressionIn[i+1]))
            {
                expressionPost[k++] = '|';
            }
            continue;
        }

        if (((operation > top(operationalStack) + 1) && (operation != clBracket)) || (top(operationalStack) == opBracket))
        {
            push(operationalStack, operation);
        }
        else
        {
            while ((operation <= top(operationalStack) + 1) || (operation == clBracket))
            {
                if ((top(operationalStack) == opBracket) && (operation == clBracket))
                {
                    pop(operationalStack);
                    break;
                }

                expressionPost[k] = outputOperation(pop(operationalStack));
                k++;

                if (((operation > top(operationalStack) + 1) && (operation != clBracket)) || ((top(operationalStack) == opBracket) && (operation != clBracket)))
                {
                    push(operationalStack, operation);
                    break;
                }
            }
        }
    }

    while (!isEmpty(operationalStack))
    {
        expressionPost[k] = outputOperation(pop(operationalStack));
        k++;
    }
    deleteStack(operationalStack);
    return k;
}

