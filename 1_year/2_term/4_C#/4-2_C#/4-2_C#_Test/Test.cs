using NUnit.Framework;
using System;
using _C;

namespace _C_Test
{
    [TestFixture()]
    public class Test
    {
        private ListUnique list;

        [SetUp()]
        public void Initialize()
        {
            list = new ListUnique();
        }

        [Test()]
        public void TestListUniqueAddValue()
        {
            list.Add(5); 
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
            Assert.IsTrue(list.IsInList(7));
            Assert.IsFalse(list.IsInList(10));
        }

        [Test()]
        public void TestListUniqueAddRemove()
        {
            list.Add(5, 0);
            list.Add(7, 0);
            Assert.IsTrue(list.IsInList(5));
            Assert.IsTrue(list.IsInList(7));
            Assert.IsFalse(list.IsInList(10));
        }

        [Test()]
        public void TestListUniqueRemoveValue()
        {
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
            list.RemoveValue(5);
            Assert.IsFalse(list.IsInList(5));
        }

        [Test()]
        [ExpectedException("_C.DeleteNonExistedElement")]
        public void TestListUniqueRemoveValueException()
        {
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
            list.RemoveValue(5);
            list.RemoveValue(9);

        }

        [Test()]
        [ExpectedException("_C.DeleteNonExistedElement")]
        public void TestListUniqueRemoveValueTwiceException()
        {
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
            list.RemoveValue(7);
            list.RemoveValue(7);

        }


        [Test()]
        public void TestListUniqueRemoveIndex()
        {
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
        }

        [Test()]
        [ExpectedException("_C.OutOfIndexes")]
        public void TestListUniqueRemoveIndexException()
        {
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsInList(5));
            list.RemoveIndex(9);
        }

        [Test()]
        [ExpectedException("_C.AddExistedElementException")]
        public void TestListUniqueExecptionAddIndex()
        {
            list.Add(5, 0);
            list.Add(7, 1);
            list.Add(5, 1);
        }

        [Test()]
        [ExpectedException("_C.OutOfIndexes")]
        public void TestAddOutOfIndex()
        {
            list.Add(0, 3);
        }

        [Test()]
        [ExpectedException("_C.AddExistedElementException")] 
        //In mono other ways (like [ExpectedException(typeof(AddExistedElementException))]  don't work.
        //I don't know why. It gives me an internal error. NullReferenceException : object reference not set to an instance of object
        //Maybe it is somehow linked to typeof?
        public void TestListUniqueExecptionAddValue()
        {
            list.Add(5);
            list.Add(7);
            list.Add(5);
        }
    }
}

