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
            list.Remove(5);
            list.Print();
        }
    }
}
