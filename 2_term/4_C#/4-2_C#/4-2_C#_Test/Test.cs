using NUnit.Framework;
using System;
using _C;

namespace _C_Test
{
    [TestFixture()]
    public class Test
    {
        [Test()]
        public void TestListUniqueAdd()
        {
            ListUnique list = new ListUnique();
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsExists(5));
            Assert.IsTrue(list.IsExists(7));
            Assert.IsFalse(list.IsExists(10));
        }

        [Test()]
        public void TestListUniqueRemove()
        {
            ListUnique list = new ListUnique();
            list.Add(5);
            list.Add(7);
            Assert.IsTrue(list.IsExists(5));
            list.Remove(5);
            try
            {
                list.Remove(7);
            }
            catch (DeleteNonExistedElement)
            {
                Assert.Fail();
            }
            Assert.IsFalse(list.IsExists(5));
            try
            {
                list.Remove(7);
                Assert.Fail();
            }
            catch (DeleteNonExistedElement)
            {
            }
            try
            {
                list.Remove(8);
                Assert.Fail();
            }
            catch (DeleteNonExistedElement)
            {
            }
        }

        [Test()]
        [ExpectedException("_C.AddExistedElementException")]
        public void TestListUniqueExecptionAdd()
        {
            ListUnique list = new ListUnique();
            list.Add(5);
            list.Add(7);
            list.Add(5);
        }

        [Test()]
        [ExpectedException("_C.DeleteNonExistedElement")]
        public void TestListUniqueExecptionRemove()
        {
            ListUnique list = new ListUnique();
            list.Remove(8);
        }
    }
}

