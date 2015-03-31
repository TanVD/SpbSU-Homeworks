using System;

namespace Application
{
    public class InfToPostFormTrans
    {
        private IStack<int> priorityOperationsStack;

        public InfToPostFormTrans(IStack<int> stack)
        {
            priorityOperationsStack = stack;
        }

        private enum OperationsLabels
        {
            plus,
            minus,
            multiply,
            divide,
            openedBracket,
            closedBracket
        }

        private static int PriorityOfOperation(OperationsLabels label)
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

        private static OperationsLabels InputOperation(char operationChar)
        {
            OperationsLabels operation = OperationsLabels.plus;
            switch (operationChar)
            {
                case '+':
                    {
                        operation = OperationsLabels.plus;
                        break;
                    }
                case '-':
                    {
                        operation = OperationsLabels.minus;
                        break;
                    }
                case '*':
                    {
                        operation = OperationsLabels.multiply;
                        break;
                    }
                case '/':
                    {
                        operation = OperationsLabels.divide;
                        break;
                    }
                case '(':
                    {
                        operation = OperationsLabels.openedBracket;
                        break;
                    }
                case ')':
                    {
                        operation = OperationsLabels.closedBracket;
                        break;
                    }
            }
            return operation;
        }

        private static char OutputOperation(OperationsLabels operationLabel)
        {
            char operation = ' ';
            switch (operationLabel)
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
                OperationsLabels operation = InputOperation(expressionIn[i]);

                if (((PriorityOfOperation(operation) > priorityOperationsStack.Top() + 1) && (operation != OperationsLabels.closedBracket))
                    || (priorityOperationsStack.Top() == PriorityOfOperation(OperationsLabels.openedBracket)))
                {
                    priorityOperationsStack.Push(PriorityOfOperation(operation));
                }
                else
                {
                    while ((PriorityOfOperation(operation) <= (priorityOperationsStack.Top() + 1)) || (operation == OperationsLabels.closedBracket))
                    {
                        if ((priorityOperationsStack.Top() == PriorityOfOperation(OperationsLabels.openedBracket)) && (operation == OperationsLabels.closedBracket))
                        {
                            priorityOperationsStack.Pop();
                            break;
                        }

                        expressionPost[k] = OutputOperation(OperationOfPriority(priorityOperationsStack.Pop()));
                        k++;

                        if (((PriorityOfOperation(operation) > priorityOperationsStack.Top() + 1) && (operation != OperationsLabels.closedBracket))
                            || ((priorityOperationsStack.Top() == PriorityOfOperation(OperationsLabels.openedBracket)) && (operation != OperationsLabels.closedBracket)))
                        {
                            priorityOperationsStack.Push(PriorityOfOperation(operation));
                            break;
                        }
                    }
                }
            }

            while (!priorityOperationsStack.IsEmpty())
            {
                expressionPost[k] = OutputOperation(OperationOfPriority(priorityOperationsStack.Pop()));
                k++;
            }
            return k;
        }
    }
}

