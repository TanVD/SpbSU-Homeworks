using System;

namespace Application
{
    public class Calculator
    {
        private char[] equation;
        private double result;
        private bool valid;

        public Calculator()
        {
            result = 0;
            valid = true;
            equation = null;
        }

        public void Calculate(char[] equationIn, int length)
        {
            this.equation = equationIn;
            char[] equationPost = new char[length * 2 + 1];
            InfToPostFormTrans infTrans = new InfToPostFormTrans(new ArrayStack<int>());
            int newLength = infTrans.InfToPostForm(equation, equationPost, length);
            valid = true;
            PostCalculation postCalc = new PostCalculation(new LinkStack<double>());
            result = postCalc.PostCalculate(equationPost, newLength, ref valid);
        }

        public double ReturnResult()
        {
            return result;
        }

        public bool IsResultValid()
        {
            return valid;
        }
    }
}

