using System;

namespace Application
{
    public class HashTable
    {
        private int module;
        private List[] array;

        private int HashFunction(int value)
        {
            int factor = 101;
            int result = 0;
            while (value != 0)
            {
                result = (result * factor + value % 10) % module;
                value = value / 10;
            }
            return result;
        }

        public HashTable(int module)
        {
            this.module = module;
            array = new List[module];
            for (int i = 0; i < module; i++)
            {
                array[i] = new List();
            }
        }

        public void Add(int value)
        {
            int index = HashFunction(value);
            array[index].Add(value);
        }

        public bool Remove(int value)
        {
            int index = HashFunction(value);
            return array[index].Remove(value);
        }

        public bool IsInHashTable(int value)
        {
            int index = HashFunction(value);
            return array[index].IsInList(value);
        }
    }
}

