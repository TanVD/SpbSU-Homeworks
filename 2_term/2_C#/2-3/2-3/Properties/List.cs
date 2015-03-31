using System;

namespace Application
{
    public class List
    {
        public void Add(int value)
        {
            head = new ListElement(value, head);
            length++;
        }

        public void Add(int value, int index)
        {
            if (index != 0)
            {
                ListElement current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current.LNext;
                }
                current.LNext = new ListElement(value, current.LNext);
                length++;
            }
            else
            {
                Add(value);
            }
        }

        public int Index(int index)
        {
            ListElement current = head;
            for (int i = 0; i < index; i++)
            {
                current = current.LNext;
            }
            return current.Value;
        }

        public bool RemoveValue(int value)
        {
            ListElement current = head;
            ListElement previous = head;
            while (current != null && current.Value != value)
            {
                previous = current;
                current = current.LNext;
            }
            if (current != null)
            {
                if (current != head)
                    previous.LNext = current.LNext;
                else
                    head = current.LNext;
                length--;
                return true;
            }
            return false;
        }

        public bool RemoveIndex(int index)
        {
            if (!IsExistsIndex(index))
            {
                return false;
            }
            if (index != 0)
            {
                ListElement current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current.LNext;
                }
                current.LNext = current.LNext.LNext;
            }
            else
            {
                head = head.LNext;
            }
            length--;
            return true;
        }

        private bool IsExistsIndex(int index)
        {
            if (head == null)
                return false;
            ListElement current = head;
            for (int i = 0; i < index; i++)
            {
                if (current.LNext == null)
                    return false;
                current = current.LNext;
            }
            return true;
        }

        public bool IsInList(int value)
        {
            ListElement current = head;
            while (current != null && current.Value != value)
            {
                current = current.LNext;
            }
            if (current != null)
            {
                return true;
            }
            return false;
        }

        public void Print()
        {
            ListElement current = head;
            while (current != null)
            {
                Console.Write("{0} ", current.Value);
                current = current.LNext;
            }
        }

        public int Length()
        {
            return length;
        }

        private class ListElement
        {
            public int Value { set; get; }

            public ListElement(int value, ListElement lNext)
            {
                this.LNext = lNext;
                this.Value = value;
            }

            public ListElement LNext { set; get; }
        };

        private ListElement head = null;
        private int length = 0;
    };
}


