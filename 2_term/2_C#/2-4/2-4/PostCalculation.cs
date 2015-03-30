using System;

namespace Application
{
    public class PostCalculation
    {
        public PostCalculation(IStack<double> stack)
        {
            operationalStack = stack;
        }

        private IStack <double> operationalStack;

        public double PostCalculate(char[] expressionPost, double expressionEnd, ref bool isValid)
        {
            double symbol = 0;
            isValid = true;
            for (int i = 0; i < expressionEnd; i++)
            {
                int operation = expressionPost[i];
                if (expressionPost[i] == '|')
                    continue;
                if (Char.IsDigit(expressionPost[i]))
                {
                    symbol = (expressionPost[i] - '0') + symbol * 10;
                    if (expressionPost[i + 1] != '|')
                        continue;
                    operationalStack.Push(symbol);
                    symbol = 0;
                    continue;
                }
                double tmpSecond = operationalStack.Pop();
                double tmpFirst = operationalStack.Pop();
                switch (operation)
                {
                    case '+':
                        {
                            operationalStack.Push(tmpFirst + tmpSecond);
                            break;
                        }
                    case '-':
                        {
                            operationalStack.Push(tmpFirst - tmpSecond);
                            break;
                        }
                    case '*':
                        {
                            operationalStack.Push(tmpFirst * tmpSecond);
                            break;
                        }
                    case '/':
                        {
                            if (tmpSecond == 0)
                            {
                                isValid = false;
                                return 0;
                            }
                            operationalStack.Push(tmpFirst / tmpSecond);
                            break;
                        }
                }
            }
            double result = operationalStack.Pop();
            return result;
        }
    }
}

