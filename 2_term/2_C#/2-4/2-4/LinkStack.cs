using System;

namespace Application
{
    public class LinkStack : IStack <double>
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
            public double value { set; get; }
            public StackElement next { set; get; }

            public StackElement(double value, StackElement next)
            {
                this.next = next;
                this.value = value;
            }
        }
        private StackElement head;
    }
}

