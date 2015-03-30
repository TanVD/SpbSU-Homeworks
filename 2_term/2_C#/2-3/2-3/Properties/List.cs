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
                    current = current.lNext;
                }
                current.lNext = new ListElement(value, current.lNext);
                length++;
            }
            else
            {
                Add(value);
            }
        }

        public bool RemoveValue(int value)
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
                if (current != head)
                    previous.lNext = current.lNext;
                else
                    head = current.lNext;
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
                    current = current.lNext;
                }
                current.lNext = current.lNext.lNext;
                length++;
            }
            else
            {
                head = head.lNext;
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
                if (current.lNext == null)
                    return false;
                current = current.lNext;
            }
            return true;
        }

        public bool IsInList(int value)
        {
            ListElement current = head;
            while (current != null && current.value != value)
            {
                current = current.lNext;
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
                Console.Write("{0} ", current.value);
                current = current.lNext;
            }
        }

        public int Length()
        {
            return length;
        }

        private class ListElement
        {
            public int value { set; get; }

            public ListElement(int value, ListElement lNext)
            {
                this.lNext = lNext;
                this.value = value;
            }

            public ListElement lNext { set; get; }
        };

        private ListElement head = null;
        private int length = 0;
    };
}


