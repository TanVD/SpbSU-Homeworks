using System;

namespace Application
{
    class MainClass
    {
        public static int Factorial(int x)
        {
            if (x > 1)
            {
                return x * Factorial(x - 1);
            }
            else
            {
                return 1;
            }
        }

        public static void Main(string[] args)
        {
            Console.Write("This program will calculate factorial of your number.\nEnter number: ");
            int factorialAns = Factorial(Int32.Parse(Console.ReadLine()));
            Console.Write("Your answer is: {0}", factorialAns);
        }
    }
}
