using System;

namespace Application
{
    public class LinkStack<T> : IStack<T>
    {
        private StackElement head = null;

        public void Push(T value)
        {
            head = new StackElement(value, head);
        }

        public T Pop()
        {
            T result = head.Value;
            head = head.Next;
            return result;
        }

        public T Top()
        {
            return head.Value;
        }

        public bool IsEmpty()
        {
            return head == null;
        }

        private class StackElement
        {
            public T Value { set; get; }
            public StackElement Next { set; get; }

            public StackElement(T value, StackElement next)
            {
                this.Next = next;
                this.Value = value;
            }
        }
    }
}

