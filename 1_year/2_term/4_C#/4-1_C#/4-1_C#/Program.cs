using System;

namespace _C
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Console.Write("This program will calculate your equation tree.\nEnter the name of file: ");
            string filename = Console.ReadLine();
            AriphTree tree = ParserOfEquation.ParseFile(filename);
            Console.Write(tree.CalculateTree());
        }
    }
}
