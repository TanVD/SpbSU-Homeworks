using System;

namespace Test_1_C
{
    public class PriorityQueue<T>
    {
        private int counter = 0;
        private QueueElement tail = null;
        private QueueElement head = null;

        public PriorityQueue()
        {
        }

        /// <summary>
        /// Adding new value in a queue in according with a rule of Priority.
        /// </summary>
        /// <param name="value">Value to be added.</param>
        /// <param name="priority">Priority of value.</param>
        public void Enqueue(T value, int priority)
        {
            QueueElement current = tail;
            while (current != null && current.Priority < priority)
            {
                current = current.LNext;
            }
            if (current == null && current == tail)//At least one element
            {
                tail = new QueueElement(value, priority, null, null);
                head = tail;
            }
            else if (current == null)//Adding in head
            {
                head.LNext = new QueueElement(value, priority, head, head.LNext);
                head = head.LNext;
            }
            else if (current == tail)//Adding in tail
            {
                tail.LPrevious = new QueueElement(value, priority, tail.LPrevious, tail);
                tail = tail.LPrevious;
            }
            else//All other variants. At least two elements. Adding between.
            {
                QueueElement newElement = new QueueElement(value, priority, current.LPrevious, current);
                current.LPrevious.LNext = newElement;
                current.LPrevious = newElement;
            }
            counter++;
        }

        /// <summary>
        /// Popping last value of queue (with the highest priority).
        /// </summary>
        /// <returns>Popped value.</returns>
        public T Dequeue()
        {
            if (Length() == 0)
                throw new DequeuingEmptyQueue();
            T result = head.Value;
            if (counter > 1)
            {
                head = head.LPrevious;
                head.LNext = null;
            }
            else
            {
                head = null;
                tail = null;
            }
            counter--;
            return result;
        }

        /// <summary>
        /// Length of this instance.
        /// </summary>
        /// <returns>length of this instance as int.</returns>
        public int Length()
        {
            return counter;
        }

        private class QueueElement
        {
            public T Value { set; get; }

            public int Priority { set; get; }

            public QueueElement LNext { set; get; }

            public QueueElement LPrevious { set; get; }

            public QueueElement(T value, int priority, QueueElement lPrevious, QueueElement lNext)
            {
                this.LNext = lNext;
                this.LPrevious = lPrevious;
                this.Value = value;
                this.Priority = priority;
            }
        }
    }

    public class DequeuingEmptyQueue : Exception
    {
        public DequeuingEmptyQueue()
        {
        }
    }
}