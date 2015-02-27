using System;

namespace Application
{
    public class InfToPostFormTrans
    {
        private enum OperationsLabels
        {
            plus = 11,
            minus = 12,
            multiply = 21,
            divide = 22,
            openedBracket = 30,
            closedBracket = 40
        }

        private static int InputOperation(char operationChar)
        {
            int operation = 0;
            switch (operationChar)
            {
                case '+':
                    {
                        operation = (int)OperationsLabels.plus;
                        break;
                    }
                case '-':
                    {
                        operation = (int)OperationsLabels.minus;
                        break;
                    }
                case '*':
                    {
                        operation = (int)OperationsLabels.multiply;
                        break;
                    }
                case '/':
                    {
                        operation = (int)OperationsLabels.divide;
                        break;
                    }
                case '(':
                    {
                        operation = (int)OperationsLabels.openedBracket;
                        break;
                    }
                case ')':
                    {
                        operation = (int)OperationsLabels.closedBracket;
                        break;
                    }
            }
            return operation;
        }

        private static char OutputOperation(int operationInt)
        {
            char operation = ' ';
            switch (operationInt)
            {
                case  (int) OperationsLabels.plus:
                    {
                        operation = '+';
                        break;
                    }
                case  (int) OperationsLabels.minus:
                    {
                        operation = '-';
                        break;
                    }
                case (int) OperationsLabels.multiply:
                    {
                        operation = '*';
                        break;
                    }
                case (int) OperationsLabels.divide:
                    {
                        operation = '/';
                        break;
                    }
            }
            return operation;
        }

        public static int InfToPostForm(char[] expressionIn, char[] expressionPost, int expressionInEnd)
        {
            IStack <int> operationalStack = new ArrayStack();
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

                if (((operation > operationalStack.Top() + 1) && (operation != (int)OperationsLabels.closedBracket))
                    || (operationalStack.Top() == (int)OperationsLabels.openedBracket))
                {
                    operationalStack.Push(operation);
                }
                else
                {
                    while ((operation <= (operationalStack.Top() + 1)) || (operation == (int) OperationsLabels.closedBracket))
                    {
                        if ((operationalStack.Top() == (int)OperationsLabels.openedBracket) && (operation == (int)OperationsLabels.closedBracket))
                        {
                            operationalStack.Pop();
                            break;
                        }

                        expressionPost[k] = OutputOperation(operationalStack.Pop());
                        k++;

                        if (((operation > operationalStack.Top() + 1) && (operation != (int)OperationsLabels.closedBracket))
                            || ((operationalStack.Top() == (int)OperationsLabels.openedBracket) && (operation != (int)OperationsLabels.closedBracket)))
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

