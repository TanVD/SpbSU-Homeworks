using System;

namespace Application
{
    public class Stack
    {
        private StackElement head { set; get; }

        public Stack()
        {
            head = null;
        }

        public void Push(int value)
        {
            head = new StackElement(value, head);
        }

        public int Pop()
        {
            int result = head.value;
            head = head.next;
            return result;
        }

        public int Top()
        {
            return head.value;
        }

        public bool IsEmpty()
        {
            return head == null;
        }

        private class StackElement
        {
            public int value { set; get; }

            public StackElement next { set; get; }

            public StackElement(int value, StackElement next)
            {
                this.next = next;
                this.value = value;
            }
        }
    }
}

