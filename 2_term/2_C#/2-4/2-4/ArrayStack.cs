using System;

namespace Application
{
    public class ArrayStack: IStack
    {
        private double[] array;
        private int capacity;
        private int size;

        public ArrayStack()
        {
            capacity = 2;
            size = 0;
            array = new double[2];
        }

        public void Push(double number)
        {
            if (size == capacity)
            {
                Array.Resize(ref array, capacity * 2);
                capacity = capacity * 2;
            }
            for (int i = size; i > 0; i--)
            {
                array[i] = array[i - 1];
            }
            array[0] = number;
            size = size + 1;
        }

        public double Pop()
        {
            double result = array[0];
            for (int i = 0; i < size - 1; i++)
            {
                array[i] = array[i + 1];
            }
            size = size - 1;
            array[size] = 0;
            if (size == capacity / 2 &&
                capacity % 2 == 0 && capacity / 2 != 0)
            {
                Array.Resize(ref array, capacity / 2);
            }
            return result;
        }

        public double Top()
        {
            return array[0];
        }

        public bool IsEmpty()
        {
            return size == 0;
        }
    }
}

