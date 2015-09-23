using NUnit.Framework;
using System;
using TDD;

namespace TDDTest
{
    public class Test
    {
        private Stack stack;

        [SetUp()]
        public void Initialize()
        {
            stack = new Stack();
        }

        [Test()]
        public void PushPopTest()
        {
            stack.Push(1);
            stack.Push(2);
            Assert.AreEqual(2, stack.Pop());
            Assert.AreEqual(1, stack.Pop());
        }

        [Test()]
        public void IsEmptyTest()
        {
            Assert.IsTrue(stack.IsEmpty());
            stack.Push(1);
            Assert.IsFalse(stack.IsEmpty());
            stack.Push(2);
            stack.Pop();
            stack.Pop();
            Assert.IsTrue(stack.IsEmpty());
        }

        [Test()]
        public void SizeTest()
        {
            Assert.AreEqual(0, stack.Size());
            stack.Push(1);
            Assert.AreEqual(1, stack.Size());
            stack.Push(2);
            Assert.AreEqual(2, stack.Size());
            stack.Pop();
            stack.Pop();
            Assert.AreEqual(0 ,stack.Size());
        }
    }
}

