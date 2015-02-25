using System;

namespace Application
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int fib0 = 0;
			int fib1 = 1;
            Console.Write("This program will calculate the number of fibonacci sequence.\nEnter index of number in sequence: ");
            int number = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < number; i++)
            {
                int tmp = fib0 + fib1;
                fib0 = fib1;
                fib1 = tmp;
            }
            Console.Write("Your answer is {0}", fib0);
		}
	}
}
