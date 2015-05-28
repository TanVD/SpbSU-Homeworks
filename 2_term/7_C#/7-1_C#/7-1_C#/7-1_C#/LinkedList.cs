using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Application
{
    /// <summary>
    /// Generic linked list.
    /// </summary>
    public class LinkedList<T> : IEnumerable<T>
    {
        /// <summary>
        /// Add the specified value.
        /// </summary>
        /// <param name="value">Value.</param>
        public void Add(T value)
        {
            head = new ListElement(value, head);
            length++;
        }

        /// <summary>
        /// Add the specified value by index.
        /// </summary>
        /// <param name="value">Value.</param>
        /// <param name="index">Index.</param>
        public void Add(T value, int index)
        {
            if (!IsExistsIndex(index))
            {
                throw new IndexOutOfRangeException();
            }
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
        /// Returns value specified by index
        /// </summary>
        /// <param name="index">Index.</param>
        public T Index(int index)
        {
            ListElement current = head;
            for (int i = 0; i < index; i++)
            {
                current = current.LNext;
            }
            return current.Value;
        }

        /// <summary>
        /// Removes the value.
        /// </summary>
        /// <returns><c>true</c>, if value was removed, <c>false</c> otherwise.</returns>
        /// <param name="value">Value to remove.</param>
        public bool RemoveValue(T value)
        {
            ListElement current = head;
            ListElement previous = head;
            while (current != null && !Equals(current.Value, value))
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
        /// <param name="index">Index.</param>
        public void RemoveIndex(int index)
        {
            if (!IsExistsIndex(index))
            {
                throw new IndexOutOfRangeException();
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
        }

        /// <summary>
        /// Determines whether in this instance exists index.
        /// </summary>
        /// <returns><c>true</c> if in this instance exists index; otherwise, <c>false</c>.</returns>
        /// <param name="index">Index.</param>
        private bool IsExistsIndex(int index)
        {
            return length >= index;
        }

        /// <summary>
        /// Determines whether in this list exists the specified value.
        /// </summary>
        /// <returns><c>true</c> if in this list exists the specified value; otherwise, <c>false</c>.</returns>
        /// <param name="value">Value.</param>
        public bool IsInList(T value)
        {
            ListElement current = head;
            while (current != null && !Equals(current.Value, value))
            {
                current = current.LNext;
            }
            return current != null;
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
        /// Returns length of this instance.
        /// </summary>
        public int Length()
        {
            return length;
        }

        private class ListElement
        {
            public T Value { set; get; }

            public ListElement(T value, ListElement lNext)
            {
                this.LNext = lNext;
                this.Value = value;
            }

            public ListElement LNext { set; get; }
        };

        private ListElement head = null;
        private int length = 0;

        /// <summary>
        /// Gets the enumerator for generic.
        /// </summary>
        /// <returns>The enumerator.</returns>
        public IEnumerator<T> GetEnumerator()
        {
            return new LinkedListEnumerator(this);
        }

        /// <summary>
        /// Gets the enumerator.
        /// </summary>
        /// <returns>The enumerator.</returns>
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        private class LinkedListEnumerator : IEnumerator<T>
        {
            private ListElement currentPosition = null;
            private LinkedList<T> list;
            private int move;

            public LinkedListEnumerator(LinkedList<T> list)
            {
                this.list = list;
            }

            /// <summary>
            /// Moves to the next value.
            /// </summary>
            /// <returns><c>true</c>, if it was possible to move to the next value, <c>false</c> otherwise.</returns>
            public bool MoveNext()
            {
                if (currentPosition != null)
                {
                    currentPosition = currentPosition.LNext;
                }
                else
                {
                    currentPosition = list.head;
                }
                move++;
                return (move < this.list.Length());
            }

            /// <summary>
            /// Reset current value of this instance.
            /// </summary>
            public void Reset()
            {
                currentPosition = null;
                move = 0;
            }

            /// <summary>
            /// Gets the current value for generic.
            /// </summary>
            /// <value>The current.</value>
            public object Current
            {
                get
                {
                    return this.currentPosition.Value;
                }
            }

            /// <summary>
            /// Gets the current value.
            /// </summary>
            /// <value>The current value.</value>
            T IEnumerator<T>.Current
            {
                get { return this.currentPosition.Value; }
            }


            public void Dispose()
            {
            }

        }
    };
}


