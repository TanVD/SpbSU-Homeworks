using System;
using System.Collections.Generic;

namespace _C
{
    public class MapClass<T>
    {
        public static List<T> Map(List<T> list, Func<T, T> lambda)
        {
            List<T> newList = new List<T>();
            foreach (var x in list)
            {
                newList.Add(lambda(x));
            }
            return newList;
        }
    }
}

