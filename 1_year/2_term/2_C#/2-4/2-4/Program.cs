using System;

namespace Application
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Enter the equation: ");
            string equationIn = Console.ReadLine();
            Calculator calc = new Calculator(new ArrayStack<int>(), new LinkStack<double>());
            calc.Calculate(equationIn.ToCharArray(), equationIn.Length);
            if (calc.IsResultValid())
            {
                Console.Write("Your answer is: ");
                Console.WriteLine(calc.ReturnResult());
            }
            else
            {
                Console.Write("Not possible to calculate");
            }

        }
    }
}
