using NUnit.Framework;
using System;
using TDD;

namespace TDDTest
{
    [TestFixture()]
    public class Test
    {
        [Test()]
        public void PushPopTest()
        {
            Stack stack = new Stack();
            stack.Push(1);
            stack.Push(2);
            int first = stack.Pop();
            int second = stack.Pop();
            Assert.AreEqual(2, first);
            Assert.AreEqual(1, second);
        }

        [Test()]
        public void IsEmptyTest()
        {
            Stack stack = new Stack();
            bool first = stack.IsEmpty();
            stack.Push(1);
            bool second = stack.IsEmpty();
            stack.Push(2);
            stack.Pop();
            stack.Pop();
            bool third = stack.IsEmpty();
            Assert.IsFalse(!first);
            Assert.IsFalse(second);
            Assert.IsFalse(!third);
        }

        [Test()]
        public void SizeTest()
        {
            Stack stack = new Stack();
            int first = stack.Size();
            stack.Push(1);
            int second = stack.Size();
            stack.Push(2);
            int third = stack.Size();
            stack.Pop();
            stack.Pop();
            int fourth = stack.Size();
            Assert.AreEqual(0, first);
            Assert.AreEqual(1, second);
            Assert.AreEqual(2, third);
            Assert.AreEqual(0 ,fourth);
        }
    }
}

