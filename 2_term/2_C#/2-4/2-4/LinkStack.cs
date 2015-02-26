using System;

namespace Application
{
    public class LinkStack : IStack
    {
        public LinkStack()
        {
            head = null;
        }

        public void Push(double value)
        {
            head = new StackElement(value, head);
        }

        public double Pop()
        {
            double result = head.value;
            head = head.next;
            return result;
        }

        public double Top()
        {
            return head.value;
        }

        public bool IsEmpty()
        {
            return head == null;
        }

        private class StackElement
        {
            public double value;
            public StackElement next;

            public StackElement(double value, StackElement next)
            {
                this.next = next;
                this.value = value;
            }
        }

        StackElement head;
    }
}

