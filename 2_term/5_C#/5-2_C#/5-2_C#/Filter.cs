using System;
using System.Collections.Generic;

namespace _C
{
    public class Filter<T>
    {
        public static List<T> Filt(List<T> list, Func <T, bool> newListPredicate)
        {
            List<T> newList = new List<T>();
            foreach (var x in list)
            {
                if (newListPredicate(x))
                {
                    newList.Add(x);
                }
            }
            return newList;
        }
    }
}

