using NUnit.Framework;
using System;
using Application;

namespace Test
{
    public class StackTest
    {
        private Stack<int> stack;

        [SetUp()]
        public void Initialize()
        {
            stack = new Stack<int>();
        }

        [Test()]
        public void IsEmptyTestInit()
        {
            Assert.IsTrue(stack.IsEmpty());
        }

        [Test()]
        public void IsEmptyTestFilled()
        {
            stack.Push(1);
            Assert.IsFalse(stack.IsEmpty());
        }

        [Test()]
        public void SizeTestInit()
        {
            Assert.AreEqual(0, stack.Size());
        }

        [Test()]
        public void SizeTestIncrement()
        {
            stack.Push(1);
            Assert.AreEqual(1, stack.Size());
        }

        [Test()]
        public void SizeTestDecrement()
        {
            stack.Push(1);
            stack.Pop();
            Assert.AreEqual(0, stack.Size());
        }

        [Test()]
        public void PushTest()
        {
            stack.Push(1);
            stack.Push(2);
            Assert.AreEqual(2, stack.Size());
        }

        [Test()]
        public void PopTest()
        {
            stack.Push(1);
            stack.Push(2);
            Assert.AreEqual(2, stack.Pop());
            Assert.AreEqual(1, stack.Pop());
        }
    }
}


