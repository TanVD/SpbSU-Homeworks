using System;

namespace Application
{
    public class Calculator
    {
        private char[] equation = null;
        private double result = 0;
        private bool valid = true;
        private IStack<int> infStack = null;
        private IStack<double> postStack = null;

        public Calculator(IStack<int> infStack, IStack<double> postStack)
        {
            this.infStack = infStack;
            this.postStack = postStack;
        }

        public void Calculate(char[] equationIn, int length)
        {
            this.equation = equationIn;
            char[] equationPost = new char[length * 2 + 1];
            InfToPostFormTrans infTrans = new InfToPostFormTrans(infStack);
            int newLength = infTrans.InfToPostForm(equation, equationPost, length);
            valid = true;
            PostCalculation postCalc = new PostCalculation(postStack);
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

