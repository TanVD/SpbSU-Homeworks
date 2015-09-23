using System;

namespace Application
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            HashTable table = new HashTable(10);
            table.Add(83);
            table.Add(909);
            table.Add(11);
            bool x = table.Remove(83);
            x = table.Contains(909);
            x = table.Contains(83);
        }
    }
}
