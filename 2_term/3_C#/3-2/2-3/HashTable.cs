using System;

namespace Application
{
    public class HashTable
    {
        public delegate int UsHash(int value,int module);

        private UsHash userHash = HashFunction;
        private int module;
        private List[] array;

        private static int HashFunction(int value, int module)
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

        public HashTable(int module, UsHash func)
        {
            this.module = module;
            array = new List[module];
            for (int i = 0; i < module; i++)
            {
                array[i] = new List();
            }
            userHash = func;
        }

        public void Add(int value)
        {
            int index = 0;
            index = userHash(value, module);
            array[index].Add(value);
        }

        public bool Remove(int value)
        {
            int index = 0;
            index = userHash(value, module);
            return array[index].Remove(value);
        }

        public bool Contains(int value)
        {
            int index = 0;
            index = userHash(value, module);
            return array[index].IsInList(value);
        }
    }
}

