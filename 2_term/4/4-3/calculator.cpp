#include "calculator.h"
#include "stack.h"
#include "arrayStack.h"
#include "stackDouble.h"
#include <ctype.h>
#include <QString>

Calculator::Calculator() : result(0), valid(true)
{
}

void Calculator::calculate(QString equationIn, int length)
{
    equation = equationIn;
    QString equationPost;
    int newLength = infToPostform(equationIn, equationPost, length);
    valid = true;
    result = postCalculate(equationPost, newLength, &valid);
}

double Calculator::returnResult()
{
    return result;
}

bool Calculator::isResultValid()
{
    return valid;
}

double Calculator::postCalculate(QString expressionPost, int expressionEnd, bool *isValid)
{
    int counterDot = 0;
    bool wasDot = false;
    double symbol = 0;
    Stack *operationalStack = new StackDouble();
    *isValid = true;
    for (int i = 0; i < expressionEnd; i++)
    {
        QChar operation = expressionPost[i];
        if (expressionPost[i] == '|')
            continue;
        if (expressionPost[i].isDigit() || expressionPost[i] == '.')
        {
            if (wasDot)
                counterDot++;
            if (expressionPost[i] != '.')
                symbol = (expressionPost[i].toLatin1() - '0') + symbol * 10;
            else
                wasDot = true;
            if (expressionPost[i + 1] != '|')
                continue;
            for (int j = 0; j < counterDot; j++)
                symbol = symbol / 10;
            wasDot = false;
            counterDot = 0;
            operationalStack->push(symbol);
            symbol = 0;
            continue;
        }
        double tmpSecond = operationalStack->pop();
        double tmpFirst = operationalStack->pop();
        switch (operation.toLatin1())
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

enum OperationsLabels
{
    plus = 11,
    minus = 12,
    multiply = 21,
    divide = 22,
    openedBracket = 30,
    closedBracket = 40
};

int Calculator::inputOperation(QChar operationChar)
{
    int operation = 0;
    switch(operationChar.toLatin1())
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

QChar Calculator::outputOperation(int operationInt)
{
    QChar operation;
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

int Calculator::infToPostform(QString expressionIn, QString &expressionPost, int expressionInEnd)
{
    Stack *operationalStack = new ArrayStack();
    int k = 0;
    for (int i = 0; i < expressionInEnd; i++)
    {
        if (expressionIn[i].isDigit() || expressionIn[i] == '.')
        {
            expressionPost[k] = expressionIn[i];
            k++;
            if (!(expressionIn[i + 1].isDigit() || expressionIn[i + 1] == '.'))
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

