using System;
using System.Collections.Generic;

namespace _C
{
    /// <summary>
    /// Map class is used to create new list applying function to every element of original list.
    /// </summary>
    public class MapClass<T>
    {
        /// <summary>
        /// Creates new list applying lambda function to every element of old list
        /// </summary>
        /// <param name="list">Original list.</param>
        /// <param name="lambda">Lambda to apply to every element of original list.</param>
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

