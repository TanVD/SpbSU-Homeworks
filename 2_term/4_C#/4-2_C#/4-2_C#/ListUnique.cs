using System;

namespace _C
{
    /// <summary>
    /// Implementation of List not keeping equal values (only one of each)
    /// </summary>
    public class ListUnique : List
    {
        /// <summary>
        /// Add the specified value to this instance of List. According to unique rule.
        /// </summary>
        /// <param name="value">Value to add.</param>
        public override void Add(int value)
        {
            if (IsInList(value))
            {
                throw new AddExistedElementException();
            }
            else
            {
                base.Add(value);
            }
        }

        /// <summary>
        /// Add the specified value to this instance of List to the place determined by index. According to unique rule.
        /// </summary>
        /// <param name="value">Value to add.</param>
        /// <param name="index">Index.</param>
        public override void Add(int value, int index)
        {
            if (!IsExistsIndex(index))
            {
                throw new OutOfIndexes();
            }
            else if (IsInList(value))
            {
                throw new AddExistedElementException();
            }
            else
            {
                base.Add(value, index);
            }
        }

        /// <summary>
        /// Removes the value form this instance of List. According to unique rule.
        /// </summary>
        /// <returns>true</returns>
        /// <c>false</c>
        /// <param name="value">Value to remove.</param>
        public override void  RemoveValue(int value)
        {
            if (!IsInList(value))
            {
                throw new DeleteNonExistedElement();
            }
            else
            {
                base.RemoveValue(value);
            }
        }

        /// <summary>
        /// Removes the value specified by index. According to unique rule.
        /// </summary>
        /// <returns>true</returns>
        /// <c>false</c>
        /// <param name="index">Index.</param>
        public override void RemoveIndex(int index)
        {
            if (!IsExistsIndex(index + 1))
            {
                throw new OutOfIndexes();
            }
            else
            {
                base.RemoveIndex(index);
            }
        }
    }
}

