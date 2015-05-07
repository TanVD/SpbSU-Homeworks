using System;
using System.Collections.Generic;

namespace _C
{
    /// <summary>
    /// Fold class implements function accumulating by some rule values of list
    /// </summary>
    public class FoldClass<T>
    {
        /// <summary>
        /// Function accumulating by some rule values of list
        /// </summary>
        /// <param name="list">List to fold.</param>
        /// <param name="start">Starting value for function.</param>
        /// <param name="accamFunction">Rule used for accumulating.</param>
        /// <returns>Accumulated value.</returns>
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

