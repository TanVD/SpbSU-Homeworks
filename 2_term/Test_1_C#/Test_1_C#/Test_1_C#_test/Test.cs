using NUnit.Framework;
using System;
using Test_1_C;

namespace Test_1_C_test
{
    [TestFixture()]
    public class Test
    {
        private PriorityQueue<int> queue;

        [SetUp()]
        public void init()
        {
            queue = new PriorityQueue<int>();
        }

        [Test()]
        public void EnqueuDequeueTest()
        {
            queue.Enqueue(6, 3);
            queue.Enqueue(9, 6);
            queue.Enqueue(11, 7);
            Assert.AreEqual(11, queue.Dequeue());
            queue.Enqueue(5, 3);
            Assert.AreEqual(9, queue.Dequeue());
            Assert.AreEqual(6, queue.Dequeue());
            Assert.AreEqual(5, queue.Dequeue());
            queue.Enqueue(11, 2);
            Assert.AreEqual(11, queue.Dequeue());
            queue.Enqueue(15, 2);
            queue.Enqueue(9, 4);
            queue.Enqueue(7, 1);
            queue.Enqueue(3, 3);
            Assert.AreEqual(9, queue.Dequeue());
            Assert.AreEqual(3, queue.Dequeue());
            Assert.AreEqual(15, queue.Dequeue());
            Assert.AreEqual(7, queue.Dequeue());
            try
            {
                queue.Dequeue();
                Assert.Fail();
            }
            catch (DequeuingEmptyQueue)
            {
            }
        }
    }
}

