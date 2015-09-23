using System;

namespace Application
{
    class MainClass
    {
        public static void WriteMatrix(int[,] matrix)
        {
            int centerSize = matrix.GetLength(1) / 2;
            int radius = 1;
            Console.Write("{0} ", matrix[centerSize, centerSize]);
            while (radius <= centerSize)
            {
                for (int i = 1; i < radius * 2 + 1; i++)
                {
                    Console.Write("{0} ", matrix[centerSize + radius, centerSize - radius + i]);
                }
                for (int i = 1; i < radius * 2 + 1; i++)
                {
                    Console.Write("{0} ", matrix[centerSize + radius - i, centerSize + radius]);
                }
                for (int i = 1; i < radius * 2 + 1; i++)
                {
                    Console.Write("{0} ", matrix[centerSize - radius, centerSize + radius - i]);
                }
                for (int i = 1; i < radius * 2 + 1; i++)
                {
                    Console.Write("{0} ", matrix[centerSize - radius + i, centerSize - radius]);
                }
                radius++;
            }
        }

        public static void Main(string[] args)
        {
            Console.WriteLine("This program will print your matrix spiral way.\nEnter size of matrix: ");
            int size = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Enter matrix: ");
            int[,] matrix = new int[size, size];
            for (int i = 0; i < size; i++)
            {
                string input = Console.ReadLine();
                char space = ' ';
                string[] inputSplitted = input.Split(space);
                int counter = 0;
                foreach (string x in inputSplitted)
                {
                    matrix[counter++, i] = Int32.Parse(x);
                }
            }
            WriteMatrix(matrix);
        }
    }
}
