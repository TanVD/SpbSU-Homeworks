using System;

namespace Application
{
    /// <summary>
    /// Hash table class which implements Hash table structure using linked lists.
    /// </summary>
    public class HashTable
    {
        public delegate int UsHash(int value, int module);

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

        /// <summary>
        /// Add the specified value to this instance of HashTable.
        /// </summary>
        /// <param name="value">Value to add.</param>
        public void Add(int value)
        {
            int index = userHash(value, module);
            array[index].Add(value);
        }

        /// <summary>
        /// Remove the specified value from this instance of HashTable.
        /// </summary>
        /// <param name="value">Value to remove.</param>
        /// <returns> <c>true</c> if the removal was successfull; otherwise <c>false</c></returns>
        public bool Remove(int value)
        {
            int index = userHash(value, module);
            return array[index].RemoveValue(value);
        }

        /// <summary>
        /// Determines whether this instance of Hashtable contains the specified value.
        /// </summary>
        /// <returns><c>true</c> if this instance contains the specified value; otherwise <c>false</c>.</returns>
        /// <param name="value">Value to find.</param>
        public bool Contains(int value)
        {
            int index = userHash(value, module);
            return array[index].IsInList(value);
        }
    }
}

