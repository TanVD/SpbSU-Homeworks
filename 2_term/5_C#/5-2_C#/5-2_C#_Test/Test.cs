using NUnit.Framework;
using System;
using System.Collections.Generic;
using _C;

namespace _C_Test
{
    [TestFixture()]
    public class Test
    {
        [Test()]
        public void TestFilterFunction()
        {
            List<int> list = new List<int>();
            list.Add(5);
            list.Add(9);
            list.Add(2);
            list.Add(4);
            List<int> newList = Filter<int>.Filt(list, x => x % 2 == 0);
            Assert.IsTrue(newList.Exists(x => x == 2));
            Assert.IsTrue(newList.Exists(x => x == 4));
            Assert.IsFalse(newList.Exists(x => x == 9));
        }
    }
}

