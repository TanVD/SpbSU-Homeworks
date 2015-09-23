using NUnit.Framework;
using System;
using Application;

namespace HashTests
{
    [TestFixture()]
    public class Test
    {
        private HashTable table;

        [Test()]
        public void AddTest()
        {
            Assert.IsTrue(table.Contains(99));
            Assert.IsFalse(table.Contains(80));
            Assert.IsTrue(table.Contains(101));
        }

        [SetUp()]
        public void Initialize()
        {
            table = new HashTable(10001);
            table.Add(99);
            table.Add(101);
        }

        [Test()]
        public void RemoveTest()
        {
            table.Remove(99);
            Assert.IsFalse(table.Contains(99));
            Assert.IsFalse(table.Remove(102));
            Assert.IsTrue(table.Remove(101));
        }

        private int HashFunction(int value, int module)
        {
            int factor = 133;
            int result = 0;
            while (value != 0)
            {
                result = (result * factor + value % 10) % module;
                value = value / 10;
            }
            return result;
        }

        [Test()]
        public void AddByMyFuncTest()
        {
            HashTable.UsHash myDelegate = HashFunction;
            HashTable table = new HashTable(10001, myDelegate);
            table.Add(99);
            table.Add(101);
            Assert.IsTrue(table.Contains(99));
            Assert.IsFalse(table.Contains(80));
            Assert.IsTrue(table.Contains(101));
        }

        [Test()]
        public void RemoveByMyFuncTest()
        {
            HashTable.UsHash myDelegate = HashFunction;
            HashTable table = new HashTable(10001, myDelegate);
            table.Add(99);
            table.Add(101);
            table.Add(102);

            Assert.IsTrue(table.Remove(102));
            Assert.IsTrue(table.Remove(101));
            Assert.IsTrue(table.Remove(99));
            Assert.IsFalse(table.Contains(99));
            Assert.IsFalse(table.Remove(102));

        }
    }
}

