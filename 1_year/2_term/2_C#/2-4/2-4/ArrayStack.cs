using System;

namespace Application
{
    public class ArrayStack<T>: IStack<T>
    {
        private T[] array = new T[2];
        private int capacity = 2;
        private int size = 0;

        public void Push(T number)
        {
            if (size == capacity)
            {
                Array.Resize(ref array, capacity * 2);
                capacity = capacity * 2;
            }
            for (int i = capacity - 1; i > 0; i--)
            {
                array[i] = array[i - 1];
            }
            array[0] = number;
            size = size + 1;
        }

        public T Pop()
        {
            T result = array[0];
            size = size - 1;
            for (int i = 0; i < capacity - 1; i++)
            {
                array[i] = array[i + 1];
            }
            if (size == capacity / 2 &&
                capacity % 2 == 0 && capacity / 2 != 0)
            {
                Array.Resize(ref array, capacity / 2);
                capacity = capacity / 2;
            }
            return result;
        }

        public T Top()
        {
            return array[0];
        }

        public bool IsEmpty()
        {
            return size == 0;
        }
    }
}

