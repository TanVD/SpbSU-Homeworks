using System;

namespace _C
{
    public class AriphTree
    {
        public AriphTree(char value)
        {
            head = new AriphTreeElement(value, null);
            current = head;
        }

        AriphTreeElement head;

        public void СreateLeftElement(char value)
        {
            current.leftElement = new AriphTreeElement(value, current);
        }

        public void СreateRightElement(char value)
        {
            current.rightElement = new AriphTreeElement(value, current);
        }

        public void DownLeft()
        {
            current = current.leftElement;
        }

        public void DownRight()
        {
            current = current.rightElement;
        }

        public void Up()
        {
            current = current.ancestor;
        }

        public bool IsLeftFree()
        {
            return current.leftElement == null;
        }

        public bool IsRightFree()
        {
            return current.rightElement == null;
        }

        public void SetDefault()
        {
            current = head;
        }

        public int CalculateTree()
        {
            return head.Calculate();
        }

        public int ValueCurrent()
        {
            return current.value;
        }

        public string PrintTree()
        {
            string stringPrint = "";
            head.Print(ref stringPrint);
            return stringPrint;
        }

        private AriphTreeElement current;

        private class AriphTreeElement
        {
            public AriphTreeElement(char value, AriphTreeElement ancestor)
            {
                this.value = value;
                leftElement = null;
                rightElement = null;
                this.ancestor = ancestor;
            }

            public AriphTreeElement leftElement;
            public AriphTreeElement rightElement;
            public AriphTreeElement ancestor;
            public char value;

            public void Print(ref string stringPrint)
            {
                if (leftElement != null)
                    leftElement.Print(ref stringPrint);
                stringPrint = stringPrint + value;
                if (rightElement != null)
                    this.rightElement.Print(ref stringPrint);

            }

            public int Calculate()
            {
                if (leftElement == null && rightElement == null)
                {
                    return value - '0';
                }
                switch (value)
                {
                    case '+':
                        {
                            return leftElement.Calculate() + rightElement.Calculate();
                        }
                    case '-':
                        {
                            return leftElement.Calculate() - rightElement.Calculate();
                        }
                    case '*':
                        {
                            return leftElement.Calculate() * rightElement.Calculate();
                        }
                    case '/':
                        {
                            return leftElement.Calculate() / rightElement.Calculate();
                        }
                }
                return 0;
            }
        }
    }
}

