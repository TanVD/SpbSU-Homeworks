using NUnit.Framework;
using _C;
using System;
using System.Collections.Generic;

namespace _C_Test
{
    [TestFixture()]
    public class Test
    {
        [Test()]
        public void MapListTest()
        {
            List<int> list = new List<int>();
            list.Add(5);
            list.Add(7);
            List<int> listNew = MapClass<int>.Map(list, x => x * x);
            Assert.IsTrue(listNew.Exists(x => x == 25));
            Assert.IsTrue(listNew.Exists(x => x == 49));
        }
    }
}

