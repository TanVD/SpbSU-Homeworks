using System;

namespace TDD
{
    public class Stack
    {
        public void Push(int value)
        {
            head = new StackElement(value, head);
            size++;
        }

        public int Pop()
        {
            int result = head.value;
            head = head.sNext;
            size--;
            return result;
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

