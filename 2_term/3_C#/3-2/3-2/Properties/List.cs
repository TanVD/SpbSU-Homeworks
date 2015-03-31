using System;

namespace Application
{
    /// <summary>
    /// List class which implements structure of linked list.
    /// </summary>
    public class List
    {
        /// <summary>
        /// Add the specified value to this instance of List.
        /// </summary>
        /// <param name="value">Value to add.</param>
        public void Add(int value)
        {
            head = new ListElement(value, head);
            length++;
        }

        /// <summary>
        /// Add the specified value to this instance of List to the place determined by index.
        /// </summary>
        /// <param name="value">Value to add.</param>
        /// <param name="index">Index.</param>
        public void Add(int value, int index)
        {
            if (index != 0)
            {
                ListElement current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current.LNext;
                }
                current.LNext = new ListElement(value, current.LNext);
                length++;
            }
            else
            {
                Add(value);
            }
        }

        /// <summary>
        /// Returns specified by index value.
        /// </summary>
        /// <param name="index">Index.</param>
        public int Index(int index)
        {
            ListElement current = head;
            for (int i = 0; i < index; i++)
            {
                current = current.LNext;
            }
            return current.Value;
        }

        /// <summary>
        /// Removes the value form this instance of List.
        /// </summary>
        /// <returns><c>true</c>, if value was removed, <c>false</c> otherwise.</returns>
        /// <param name="value">Value to remove.</param>
        public bool RemoveValue(int value)
        {
            ListElement current = head;
            ListElement previous = head;
            while (current != null && current.Value != value)
            {
                previous = current;
                current = current.LNext;
            }
            if (current != null)
            {
                if (current != head)
                    previous.LNext = current.LNext;
                else
                    head = current.LNext;
                length--;
                return true;
            }
            return false;
        }

        /// <summary>
        /// Removes the value specified by index.
        /// </summary>
        /// <returns><c>true</c>, if value was removed, <c>false</c> otherwise.</returns>
        /// <param name="index">Index.</param>
        public bool RemoveIndex(int index)
        {
            if (!IsExistsIndex(index))
            {
                return false;
            }
            if (index != 0)
            {
                ListElement current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current.LNext;
                }
                current.LNext = current.LNext.LNext;
            }
            else
            {
                head = head.LNext;
            }
            length--;
            return true;
        }

        private bool IsExistsIndex(int index)
        {
            if (head == null)
                return false;
            ListElement current = head;
            for (int i = 0; i < index; i++)
            {
                if (current.LNext == null)
                    return false;
                current = current.LNext;
            }
            return true;
        }

        /// <summary>
        /// Determines whether this value is in list .
        /// </summary>
        /// <returns><c>true</c> if this value is in list; otherwise, <c>false</c>.</returns>
        /// <param name="value">Value to find.</param>
        public bool IsInList(int value)
        {
            ListElement current = head;
            while (current != null && current.Value != value)
            {
                current = current.LNext;
            }
            if (current != null)
            {
                return true;
            }
            return false;
        }


        /// <summary>
        /// Print this instance.
        /// </summary>
        public void Print()
        {
            ListElement current = head;
            while (current != null)
            {
                Console.Write("{0} ", current.Value);
                current = current.LNext;
            }
        }

        /// <summary>
        /// Length of this instance.
        /// </summary>
        /// <returns>Lenght of this instance </returns>
        public int Length()
        {
            return length;
        }

        private class ListElement
        {
            public int Value { set; get; }

            public ListElement(int value, ListElement lNext)
            {
                this.LNext = lNext;
                this.Value = value;
            }

            public ListElement LNext { set; get; }
        };

        private ListElement head = null;
        private int length = 0;
    };
}


