using System;
using System.Collections.Generic;

namespace _C
{
    public class FoldClass<T>
    {
        public static T Fold(List<T> list, T start, Func<T, T, T> accamFunction)
        {
            T result = start;
            for (int i = 0; i < list.Count; i++)
            {
                result = accamFunction(result, list[i]);
            }
            return result;
        }
    }
}

