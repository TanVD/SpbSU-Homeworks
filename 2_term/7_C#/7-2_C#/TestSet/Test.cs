using NUnit.Framework;
using System;
using _C;

namespace TestSet
{
    [TestFixture()]
    public class Test
    {
        [SetUp()]
        public void Initialize()
        {
            set = new Set<int>();
        }

        [Test()]
        public void AddOneTest()
        {
            set.Add(5);
        }

        [Test()]
        public void AddSeveralTest()
        {
            set.Add(5);
            set.Add(9);
            set.Add(11);
            set.Add(22);
        }

        [Test()]
        public void IsExistsOneTest()
        {
            set.Add(99);
            Assert.IsTrue(set.IsExists(99));
        }

        [Test()]
        public void IsExistsSeveralTest()
        {
            set.Add(99);
            Assert.IsTrue(set.IsExists(99));
            set.Add(9);
            Assert.IsTrue(set.IsExists(9));
            set.Add(107);
            Assert.IsTrue(set.IsExists(107));
        }

        [Test()]
        public void RemoveOneTest()
        {
            set.Add(5);
            Assert.IsTrue(set.Remove(5));
        }

        [Test()]
        public void RemoveSeveralTest()
        {
            set.Add(99);
            Assert.IsTrue(set.Remove(99));
            set.Add(9);
            Assert.IsTrue(set.Remove(9));
            set.Add(107);
            Assert.IsTrue(set.Remove(107));
        }

        [Test()]
        public void RemoveNotExistedTest()
        {
            Assert.IsFalse(set.Remove(99));
        }

        [Test()]
        public void interSectTest()
        {
            Set<int> setFirst = new Set<int>();
            setFirst.Add(5);
            setFirst.Add(9);
            setFirst.Add(11);
            Set<int> setSecond = new Set<int>();
            setSecond.Add(5);
            setSecond.Add(11);
            setSecond.Add(1);
            Set<int> result = setFirst.IntersectSets(setSecond);
            Assert.IsTrue(result.IsExists(5));
            Assert.IsTrue(result.IsExists(11));
            Assert.IsFalse(result.IsExists(1));
            Assert.IsFalse(result.IsExists(9));
        }

        [Test()]
        public void associateTest()
        {
            Set<int> setFirst = new Set<int>();
            setFirst.Add(5);
            setFirst.Add(9);
            setFirst.Add(11);
            Set<int> setSecond = new Set<int>();
            setSecond.Add(5);
            setSecond.Add(11);
            setSecond.Add(1);
            Set<int> result = setFirst.AssociationSets(setSecond);
            Assert.IsTrue(result.IsExists(5));
            Assert.IsTrue(result.IsExists(11));
            Assert.IsTrue(result.IsExists(1));
            Assert.IsTrue(result.IsExists(9));
            Assert.IsFalse(result.IsExists(13));
        }

        private Set<int> set;
    }
}

