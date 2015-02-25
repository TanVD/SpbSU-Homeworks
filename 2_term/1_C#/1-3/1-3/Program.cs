using System;

namespace Application
{
    class MainClass
    {
        private static void MySwap(ref int a, ref int b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }

        private static void QuickSort(int[] a, int start, int end)
        {
            if (start < end)
            {
                int sepPoint;
                sepPoint = MakeParts(a, start, end);
                QuickSort(a, start, sepPoint - 1);
                QuickSort(a, sepPoint + 1, end);
            }
        }

        private static int MakeParts(int[] a, int start, int strongPoint)
        {
            int[] myArray = new int[3];
            Random rand = new Random();
            myArray[0] = rand.Next() % (strongPoint - start + 1) + start;
            myArray[1] = rand.Next() % (strongPoint - start + 1) + start;
            myArray[2] = rand.Next() % (strongPoint - start + 1) + start;

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < (2-i); k++)
                {
                    if (a[myArray[k]] > a[myArray[k + 1]])
                    {
                        int tmp = myArray[k];
                        myArray[k] = myArray[k + 1];
                        myArray[k + 1] = tmp;
                    }
                }
            }
            MySwap(ref a[myArray[2]], ref a[strongPoint]);
            int afterSepElement = start;
            for (int i = start; i < strongPoint; i++)
            {
                if (a[i] <= a[strongPoint])
                {
                    MySwap(ref a[afterSepElement], ref a[i]);
                    ++afterSepElement;
                }
            }
            MySwap(ref a[afterSepElement], ref a[strongPoint]);
            int result = afterSepElement;
            return result;
        }

        public static void Main(string[] args)
        {
            Console.WriteLine("This program will sort your array.\nEnter the array: ");
            string input = Console.ReadLine();
            char space = ' ';
            string[] inputSplitted = input.Split(space);
            int[] numberArray = new int[2];
            int counter = 0;
            int capacity = 2;
            foreach (string x in inputSplitted)
            {
                if (counter > (capacity - 1))
                {
                    Array.Resize(ref numberArray, capacity * 2);
                    capacity *= 2;
                }
                numberArray[counter++] = Int32.Parse(x);
            }
            QuickSort(numberArray, 0, counter - 1);
            Console.WriteLine("Your sorted array is: ");
            for (int i = 0; i < counter; i++)
            {
                Console.Write("{0} ", numberArray[i]);
            }
        }
    }
}
