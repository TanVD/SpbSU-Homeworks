using System;

namespace Application
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Stack stack = new Stack();
            stack.Push(3);
            stack.Push(2);
            int x = stack.Pop();
            x = stack.Top();
            Console.WriteLine(x);
            stack.Pop();
            if (stack.IsEmpty())
            {
                Console.Write("Ok");
            }
        }
    }
}
