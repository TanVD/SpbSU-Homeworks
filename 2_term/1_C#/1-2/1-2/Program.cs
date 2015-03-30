using System;

namespace Application
{
    class MainClass
    {
        public static int Fibonacci(int number)
        {
            int fib0 = 0;
            int fib1 = 1;
            for (int i = 0; i < number; i++)
            {
                int tmp = fib0 + fib1;
                fib0 = fib1;
                fib1 = tmp;
            }
            return fib0;
        }

        public static void Main(string[] args)
        {
            Console.Write("This program will calculate the number of fibonacci sequence.\nEnter index of number in sequence: ");
            int number = Int32.Parse(Console.ReadLine());
            Console.Write("Your answer is {0}", Fibonacci(number));
        }
    }
}
