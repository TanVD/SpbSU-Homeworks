using System;

namespace Application
{
    public class LinkStack<T> : IStack <T>
    {
        public LinkStack()
        {
            head = null;
        }

        public void Push(T value)
        {
            head = new StackElement(value, head);
        }

        public T Pop()
        {
            T result = head.value;
            head = head.next;
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
        private StackElement head;
    }
}

