using System;

namespace Application
{
    public class List
    {
        public List()
        {
            head = null;
        }

        public void Add(int value)
        {
            head = new ListElement(value, head);
        }

        public bool Remove(int value)
        {
            ListElement current = head;
            ListElement previous = head;
            while (current != null && current.value != value)
            {
                previous = current;
                current = current.lNext;
            }
            if (current != null)
            {
                if (previous != head)
                    previous.lNext = current.lNext;
                else
                    head = current.lNext;
                return true;
            }
            return false;
        }

        public void Print()
        {
            ListElement current = head;
            while (current != null)
            {
                Console.Write("{0} ", current.value);
                current = current.lNext;
            }
        }

        private class ListElement
        {
            public int value;

            public ListElement(int value, ListElement lNext)
            {
                this.lNext = lNext;
                this.value = value;
            }

            public ListElement lNext;
        };

        private ListElement head;
    };
}


