using System;
using System.Collections.Generic;

namespace _C
{
    /// <summary>
    /// Class Filter implements function to filt original list and return new.
    /// </summary>
    public class Filter<T>
    {
        /// <summary>
        /// Filt the specified list by the specified predicate.
        /// </summary>
        /// <param name="list">List to filt.</param>
        /// <param name="newListPredicate">Predicate for new list.</param>
        /// <returns>filtered list.</returns>
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

