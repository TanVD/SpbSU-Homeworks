using NUnit.Framework;
using System;
using _C;

namespace _C_Test
{
    [TestFixture()]
    public class Test
    {
        [Test()]
        public void ariphTreeCreatingTest()
        {
            AriphTree tree = new AriphTree('-');
            tree.СreateLeftElement('+');
            tree.DownLeft();
            tree.СreateLeftElement('1');
            tree.СreateRightElement('2');
            tree.Up();
            tree.СreateRightElement('4');
            Assert.AreEqual("1+2-4", tree.PrintTree());
         }
        [Test()]
        public void ariphTreeFreeTest()
        {
            AriphTree tree = new AriphTree('-');
            tree.СreateLeftElement('1');
            Assert.IsFalse(tree.IsLeftFree());
            Assert.IsFalse(!tree.IsRightFree());
        }
        [Test()]
        public void moveTreeTest()
        {
            AriphTree tree = new AriphTree('-');
            tree.СreateLeftElement('+');
            tree.DownLeft();
            Assert.AreEqual('+', tree.ValueCurrent());
            tree.СreateLeftElement('1');
            tree.СreateRightElement('2');
            tree.Up();
            Assert.AreEqual('-', tree.ValueCurrent());
            tree.СreateRightElement('4');
            tree.DownRight();
            Assert.AreEqual('4', tree.ValueCurrent());
        }
        [Test()]
        public void parseTreeTest()
        {
            AriphTree tree = ParserOfEquation.ParseFile("bobuk");
            Assert.AreEqual("1+2-4", tree.PrintTree());
        }
        [Test()]
        public void calculateTree()
        {
            AriphTree tree = ParserOfEquation.ParseFile("bobuk");//Не уверен что правильно так закладываться на предыдущий тест
            Assert.AreEqual(-1, tree.CalculateTree());
        }
    }
}

