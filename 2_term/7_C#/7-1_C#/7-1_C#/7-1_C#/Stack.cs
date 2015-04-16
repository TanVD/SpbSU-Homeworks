using System;

namespace Application
{
    public class Stack<T>
    {
        private StackElement head = null;

        private int size = 0;

        public void Push(T value)
        {
            head = new StackElement(value, head);
            size++;
        }

        public T Pop()
        {
            T result = head.value;
            head = head.next;
            size--;
            return result;
        }

        public T Top()
        {
            return head.value;
        }

        public bool IsEmpty()
        {
            return head == null;
        }

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

