using System;

namespace Application
{
    /// <summary>
    /// Generic stack class.
    /// </summary>
    public class Stack<T>
    {
        private StackElement head = null;

        private int size = 0;

        /// <summary>
        /// Push the specified value to the stack.
        /// </summary>
        /// <param name="value">Value.</param>
        public void Push(T value)
        {
            head = new StackElement(value, head);
            size++;
        }

        /// <summary>
        /// Pop the specified value from this instance.
        /// </summary>
        public T Pop()
        {
            T result = head.value;
            head = head.next;
            size--;
            return result;
        }

        /// <summary>
        /// Top of this instance.
        /// </summary>
        public T Top()
        {
            return head.value;
        }

        /// <summary>
        /// Determines whether this instance is empty.
        /// </summary>
        /// <returns><c>true</c> if this instance is empty; otherwise, <c>false</c>.</returns>
        public bool IsEmpty()
        {
            return head == null;
        }

        /// <summary>
        /// Returns size of this instance.
        /// </summary>
        public int Size()
        {
            return size;
        }

        private class StackElement
        {
            public T value { set; get; }

            public StackElement next { set; get; }

            public StackElement(T value, StackElement next)
            {
                this.next = next;
                this.value = value;
            }
        }
    }
}

