using System;

namespace TDD
{
    /// <summary>
    /// Stack class which implements Stack using linked list
    /// </summary>
    public class Stack
    {
        /// <summary>
        /// Push the specified value to this instance of Stack.
        /// </summary>
        /// <param name="value">Value to push.</param>
        public void Push(int value)
        {
            head = new StackElement(value, head);
            size++;
        }
        /// <summary>
        /// Pop the value from this instance of Stack.
        /// </summary>
        /// <returns>Int representing value popped from this instance of Stack.</returns>
        public int Pop()
        {
            int result = head.value;
            head = head.sNext;
            size--;
            return result;
        }
        /// <summary>
        /// Determines whether this instance of Stack is empty.
        /// </summary>
        /// <returns><c>true</c> if this instance is empty; otherwise, <c>false</c>.</returns>
        public bool IsEmpty()
        {
            return head == null;
        }

        /// <summary>
        /// Size of this instance of Stack.
        /// </summary>
        /// <returns> Int representing the size of stack</returns>
        public int Size()
        {
            return size;
        }


        private class StackElement
        {
            public StackElement(int value, StackElement sNext)
            {
                this.sNext = sNext;
                this.value = value;
            }

            public StackElement sNext { set; get; }
            public int value { set; get; }
        }

        private int size;

        private StackElement head;
    }
}

