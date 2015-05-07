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
        public void FoldListTest()
        {
            List<int> list = new List<int>() {1, 2, 3};
            int result = FoldClass<int>.Fold(list, 1, (acc, elem) => acc * elem);
            Assert.AreEqual(6, result);
        }
    }
}

