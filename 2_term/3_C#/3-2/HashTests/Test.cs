using NUnit.Framework;
using System;
using Application;

namespace HashTests
{
    [TestFixture()]
    public class Test
    {
        [Test()]
        public void AddTest()
        {
            HashTable table = new HashTable(10001);
            table.Add(99);
            table.Add(101);
            Assert.IsFalse(!table.Contains(99));
            Assert.IsFalse(table.Contains(80));
            Assert.IsFalse(!table.Contains(101));
        }

        [Test()]
        public void RemoveTest()
        {
            HashTable table = new HashTable(10001);
            table.Add(99);
            table.Add(101);
            table.Remove(99);
            Assert.IsFalse(table.Contains(99));
            Assert.IsFalse(table.Remove(102));
            Assert.IsFalse(!table.Remove(101));
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
            HashTable.UsHash myDelegate = new HashTable.UsHash(HashFunction);
            HashTable table = new HashTable(10001, myDelegate);
            table.Add(99);
            table.Add(101);
            Assert.IsFalse(!table.Contains(99));
            Assert.IsFalse(table.Contains(80));
            Assert.IsFalse(!table.Contains(101));
        }

        [Test()]
        public void RemoveByMyFuncTest()
        {
            HashTable.UsHash myDelegate = new HashTable.UsHash(HashFunction);
            HashTable table = new HashTable(10001, myDelegate);
            table.Add(99);
            table.Add(101);
            table.Remove(99);
            Assert.IsFalse(table.Contains(99));
            Assert.IsFalse(table.Remove(102));
            Assert.IsFalse(!table.Remove(101));
        }
    }
}

