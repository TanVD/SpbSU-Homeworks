using System;

namespace Application
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            List list = new List();
            list.Add(2);
            list.Add(3);
            list.Add(5);
            list.RemoveValue(5);
            list.RemoveValue(3);
            list.Add(11, 0);
            list.Add(12, 1);
            list.Print();
            list.RemoveIndex(0);
            list.Print();

        }
    }
}
