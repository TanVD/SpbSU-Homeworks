using System;

namespace _C
{
    public class Set<T>
    {

        public Set()
        {
        }

        /// <summary>
        /// Add the specified value.
        /// </summary>
        /// <param name="value">Value.</param>
        public void Add(T value)
        {
            if (!IsExists(value))
            {
                head = new SetElement(value, head);
                counter++;
            }
        }

        /// <summary>
        /// Remove the specified value.
        /// </summary>
        /// <param name="value">Value.</param>
        public bool Remove(T value)
        {
            SetElement current = head;
            SetElement previous = head;
            while (current != null && !Equals(current.value, value))
            {
                previous = current;
                current = current.lNext;
            }
            if (current != null)
            {
                if (current != head)
                    previous.lNext = current.lNext;
                else
                    head = current.lNext;
                counter--;
                return true;
            }
            return false;
        }

        /// <summary>
        /// Determines whether in this instance is exists the specified value.
        /// </summary>
        /// <returns><c>true</c> if in this instance is exists the specified value; otherwise, <c>false</c>.</returns>
        /// <param name="value">Value.</param>
        public bool IsExists(T value)
        {
            SetElement current = head;
            while (current != null && !Equals(current.value, value))
            {
                current = current.lNext;
            }
            return current != null;
        }
        /// <summary>
            /// Returns length this instance.
        /// </summary>
        public int Length()
        {
            return counter;
        }

        /// <summary>
        /// Returns the associations of two sets/
        /// </summary>
        /// <returns>Association of two sets.</returns>
        /// <param name="secondSet">Second set.</param>
        public Set<T> AssociationSets(Set<T> secondSet)
        {
            Set<T> resultSet = new Set<T>();
            SetElement current = head;
            while (current != null)
            {
                resultSet.Add(current.value);
                current = current.lNext;
            }
            current = secondSet.head;
            while (current != null)
            {
                resultSet.Add(current.value);
                current = current.lNext;
            }
            return resultSet;
        }


        /// <summary>
        /// Returns the intersection of two sets.
        /// </summary>
        /// <returns>Intersection of two sets.</returns>
        /// <param name="secondSet">Second set.</param>
        public Set<T> IntersectSets(Set<T> secondSet)
        {
            Set<T> resultSet = new Set<T>();
            SetElement current = head;
            while (current != null)
            {
                if (secondSet.IsExists(current.value))
                    resultSet.Add(current.value);
                current = current.lNext;
            }
            return resultSet;
        }

        private class SetElement
        {
            public T value;

            public SetElement(T value, SetElement lNext)
            {
                this.lNext = lNext;
                this.value = value;
            }

            public SetElement lNext;
        };

        private int counter = 0;
        private SetElement head = null;
    }
}

