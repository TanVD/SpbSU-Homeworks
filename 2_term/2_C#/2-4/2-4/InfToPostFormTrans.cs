using System;

namespace Application
{
    public class InfToPostFormTrans
    {

        public InfToPostFormTrans(IStack<int> stack)
        {
            operationalStack = stack;
        }

        private IStack <int> operationalStack;

        private enum OperationsLabels
        {
            plus = 11,
            minus = 12,
            multiply = 21,
            divide = 22,
            openedBracket = 30,
            closedBracket = 40
        }

        private static int priorityOfOperation(OperationsLabels label)
        {
            switch (label)
            {
                case OperationsLabels.plus:
                    {
                        return 11;
                    }
                case OperationsLabels.minus:
                    {
                        return 12;
                    }
                case OperationsLabels.multiply:
                    {
                        return 21;
                    }
                case OperationsLabels.divide:
                    {
                        return 22;
                    }
                case OperationsLabels.openedBracket:
                    {
                        return 30;
                    }
                case OperationsLabels.closedBracket:
                    {
                        return 40;
                    }
            }
            return 0;
        }

        private static OperationsLabels OperationOfPriority(int priority)
        {
            switch (priority)
            {
                case 11:
                    {
                        return OperationsLabels.plus;
                    }
                case 12:
                    {
                        return OperationsLabels.minus;
                    }
                case 21:
                    {
                        return OperationsLabels.multiply;
                    }
                case 22:
                    {
                        return OperationsLabels.divide;
                    }
                case 30:
                    {
                        return OperationsLabels.openedBracket;
                    }
                case 40:
                    {
                        return OperationsLabels.closedBracket;
                    }
            }
            return 0;
        }

        private static int InputOperation(char operationChar)
        {
            int operation = 0;
            switch (operationChar)
            {
                case '+':
                    {
                        operation = priorityOfOperation(OperationsLabels.plus);
                        break;
                    }
                case '-':
                    {
                        operation = priorityOfOperation(OperationsLabels.minus);
                        break;
                    }
                case '*':
                    {
                        operation = priorityOfOperation(OperationsLabels.multiply);
                        break;
                    }
                case '/':
                    {
                        operation = priorityOfOperation(OperationsLabels.divide);
                        break;
                    }
                case '(':
                    {
                        operation = priorityOfOperation(OperationsLabels.openedBracket);
                        break;
                    }
                case ')':
                    {
                        operation = priorityOfOperation(OperationsLabels.closedBracket);
                        break;
                    }
            }
            return operation;
        }

        private static char OutputOperation(int operationInt)
        {
            char operation = ' ';
            switch (OperationOfPriority(operationInt))
            {
                case  OperationsLabels.plus:
                    {
                        operation = '+';
                        break;
                    }
                case  OperationsLabels.minus:
                    {
                        operation = '-';
                        break;
                    }
                case OperationsLabels.multiply:
                    {
                        operation = '*';
                        break;
                    }
                case OperationsLabels.divide:
                    {
                        operation = '/';
                        break;
                    }
            }
            return operation;
        }

        public int InfToPostForm(char[] expressionIn, char[] expressionPost, int expressionInEnd)
        {
            int k = 0;
            for (int i = 0; i < expressionInEnd; i++)
            {
                if (expressionIn[i] == ' ')
                    continue;
                if (Char.IsDigit(expressionIn[i]))
                {
                    expressionPost[k] = expressionIn[i];
                    k++;
                    if (i == expressionInEnd - 1)
                    {
                        expressionPost[k++] = '|';
                    }
                    else if (!Char.IsDigit(expressionIn[i + 1]))
                    {
                        expressionPost[k++] = '|';
                    }
                    continue;
                }
                int operation = InputOperation(expressionIn[i]);
                if (operation == 0)
                {
                    return 0;
                }

                if (((operation > operationalStack.Top() + 1) && (operation != priorityOfOperation(OperationsLabels.closedBracket)))
                    || (operationalStack.Top() == priorityOfOperation(OperationsLabels.openedBracket)))
                {
                    operationalStack.Push(operation);
                }
                else
                {
                    while ((operation <= (operationalStack.Top() + 1)) || (operation == priorityOfOperation(OperationsLabels.closedBracket)))
                    {
                        if ((operationalStack.Top() == priorityOfOperation(OperationsLabels.openedBracket)) && (operation == priorityOfOperation(OperationsLabels.closedBracket)))
                        {
                            operationalStack.Pop();
                            break;
                        }

                        expressionPost[k] = OutputOperation(operationalStack.Pop());
                        k++;

                        if (((operation > operationalStack.Top() + 1) && (operation != priorityOfOperation(OperationsLabels.closedBracket)))
                            || ((operationalStack.Top() == priorityOfOperation(OperationsLabels.openedBracket)) && (operation != priorityOfOperation(OperationsLabels.closedBracket))))
                        {
                            operationalStack.Push(operation);
                            break;
                        }
                    }
                }
            }

            while (!operationalStack.IsEmpty())
            {
                expressionPost[k] = OutputOperation(operationalStack.Pop());
                k++;
            }
            return k;
        }


    }
}

