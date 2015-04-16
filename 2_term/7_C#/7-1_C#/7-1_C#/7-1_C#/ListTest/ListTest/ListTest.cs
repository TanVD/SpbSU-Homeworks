using NUnit.Framework;
using System;
using Application;

namespace Test
{
    [TestFixture()]
    public class ListTest
    {
        private LinkedList<int> list;

        [SetUp()]
        public void Initialize()
        {
            list = new LinkedList<int>();
        }

        [Test()]
        public void TestLinkedListAddValue()
        {
            list.Add(5); 
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
            Assert.IsTrue(list.IsInList(7));
            Assert.IsFalse(list.IsInList(10));
        }

        [Test()]
        public void TestLinkedListAddValueIndex()
        {
            list.Add(5, 0); 
            list.Add(7, 0);
            Assert.IsTrue(list.IsInList(5));
            Assert.IsTrue(list.IsInList(7));
            Assert.IsFalse(list.IsInList(10));
        }

        [Test()]
        public void TestLinkedListRemoveValue()
        {
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
            list.RemoveValue(5);
            Assert.IsFalse(list.IsInList(5));
        }

        [Test()]
        public void TestLinkedListRemoveValueIndex()
        {
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
            list.RemoveIndex(1);
            Assert.IsFalse(list.IsInList(5));
        }

        [Test()]
        public void TestLinkedListRemoveValueNonExisted()
        {
            Assert.IsFalse(list.RemoveValue(9));
        }

        [Test()]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void TestLinkedListRemoveIndexException()
        {
            list.RemoveIndex(9);
        }

        [Test()]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void TestAddOutOfIndex()
        {
            list.Add(0, 3);
        }

        [Test()]
        public void TestForEachList()
        {
            for (int i = 0; i < 10; i++)
                list.Add(i);
            int first = 9;
            foreach (int number in list)
            {
                Assert.AreEqual(first--, number);
            }
        }
    }
}

