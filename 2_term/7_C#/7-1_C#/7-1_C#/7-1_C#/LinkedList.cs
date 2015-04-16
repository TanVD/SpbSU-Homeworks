using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Application
{
    public class LinkedList<T> : IEnumerable<T> 
    {
        public void Add(T value)
        {
            head = new ListElement(value, head);
            length++;
        }

        public void Add(T value, int index)
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

        public T Index(int index)
        {
            ListElement current = head;
            for (int i = 0; i < index; i++)
            {
                current = current.LNext;
            }
            return current.Value;
        }

        public bool RemoveValue(T value)
        {
            ListElement current = head;
            ListElement previous = head;
            while (current != null && !Equals(current.Value, value))
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
            if (length >= index)
                return true;
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

        public IEnumerator<T> GetEnumerator()
        {
            return new LinkedListEnumerator(this);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        private class LinkedListEnumerator : IEnumerator<T>
        {
            private int currentPosition = -1;
            private LinkedList<T> list;

            public LinkedListEnumerator(LinkedList<T> list)
            {
                this.list = list;
            }

            public bool MoveNext()
            {
                currentPosition++;
                return (currentPosition < this.list.Length());
            }

            public void Reset()
            {
                currentPosition = -1;
            }

            public object Current
            {
                get
                {
                    return this.list.Index(currentPosition);
                }
            }

            T IEnumerator<T>.Current
            {
                get { return list.Index(currentPosition); }
            }


            public void Dispose()
            {
            }

        }

        private class ListElement
        {
            public T Value { set; get; }

            public ListElement(T value, ListElement lNext)
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


