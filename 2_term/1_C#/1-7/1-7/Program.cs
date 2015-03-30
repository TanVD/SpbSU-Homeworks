using System;

namespace Application
{
    class MainClass
    {
        private static void SelectSort(ref int[][] array, int width, int height)
        {
            for (int i = 0; i < array.Length; i++)
            {
                int min = i;
                for (int j = i; j < array.Length; j++)
                {
                    if (array[min][0] > array[j][0])
                    {
                        min = j;
                    }
                }
                int[] tmp = array[min];
                array[min] = array[i];
                array[i] = tmp;
            }
        }

        public static void Main(string[] args)
        {
            Console.WriteLine("This program will sort your matrix by first number of column.\nEnter the width and height of matrix.");
            Console.Write("Enter the width: ");
            int width = Int32.Parse(Console.ReadLine());
            Console.Write("Enter the height: ");
            int height = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Enter matrix: ");
            int[][] matrix = new int[width][];
            for (int i = 0; i < width; i++)
            {
                matrix[i] = new int[height];
            }
            for (int i = 0; i < height; i++)
            {
                string input = Console.ReadLine();
                char space = ' ';
                string[] inputSplitted = input.Split(space);
                int counter = 0;
                foreach (string x in inputSplitted)
                {
                    matrix[counter++][i] = Int32.Parse(x);
                }
            }
            SelectSort(ref matrix, width, height);
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    Console.Write("{0} ", matrix[j][i]);
                }
                Console.WriteLine();
            }

        }
    }
}
