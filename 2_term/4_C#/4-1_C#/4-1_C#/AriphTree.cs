using System;

namespace _C
{
    /// <summary>
    /// Ariph tree class implements binary tree structure.
    /// </summary>
    public class AriphTree
    {
        private AriphTreeElement head = null;
        
        private AriphTreeElement current = null;

        public AriphTree(char value)
        {
            head = new AriphTreeElement(value, null);
            current = head;
        }

        /// <summary>
        /// Сreates the left element of the current node.
        /// </summary>
        /// <param name="value">Value to put in created left element of the left node.</param>
        public void СreateLeftElement(char value)
        {
            current.LeftElement = new AriphTreeElement(value, current);
        }

        /// <summary>
        /// Сreates the right element of the current node.
        /// </summary>
        /// <param name="value">Value to put in created left element of the right node.</param>
        public void СreateRightElement(char value)
        {
            current.RightElement = new AriphTreeElement(value, current);
        }

        /// <summary>
        /// Moves current node to the left child of current now.
        /// </summary>
        public void DownLeft()
        {
            current = current.LeftElement;
        }

        /// <summary>
        /// Moves current node to the right child of current now.
        /// </summary>
        public void DownRight()
        {
            current = current.RightElement;
        }

        /// <summary>
        /// Moves current node to the ancestor of current now.
        /// </summary>
        public void Up()
        {
            current = current.Ancestor;
        }

        /// <summary>
        /// Determines whether left child of current node is free.
        /// </summary>
        /// <returns><c>true</c> if left child of current node is free; otherwise, <c>false</c>.</returns>
        public bool IsLeftFree()
        {
            return current.LeftElement == null;
        }

        /// <summary>
        /// Determines whether right child of current node is free.
        /// </summary>
        /// <returns><c>true</c> if right child of current node is free; otherwise, <c>false</c>.</returns>
        public bool IsRightFree()
        {
            return current.RightElement == null;
        }

        /// <summary>
        /// Sets the current node to head.
        /// </summary>
        public void SetDefault()
        {
            current = head;
        }

        /// <summary>
        /// Calculates the tree.
        /// </summary>
        /// <returns>Int representing value of tree equation.</returns>
        public int CalculateTree()
        {
            return head.Calculate();
        }

        /// <summary>
        /// Returns value of current node.
        /// </summary>
        /// <returns>Value of current node.</returns>
        public int ValueCurrent()
        {
            return current.Value;
        }

        /// <summary>
        /// Creates string representing structure of tree.
        /// </summary>
        /// <returns>string representing structure of tree.</returns>
        public string PrintTree()
        {
            string stringPrint = "";
            head.Print(ref stringPrint);
            return stringPrint;
        }

        private class AriphTreeElement
        {
            public AriphTreeElement(char value, AriphTreeElement ancestor)
            {
                this.Value = value;
                this.Ancestor = ancestor;
            }

            public AriphTreeElement LeftElement{ set; get; }
            public AriphTreeElement RightElement{ set; get; }
            public AriphTreeElement Ancestor{ set; get; }
            public char Value { set; get; }

            public void Print(ref string stringPrint)
            {
                if (LeftElement != null)
                    LeftElement.Print(ref stringPrint);
                stringPrint = stringPrint + Value;
                if (RightElement != null)
                    RightElement.Print(ref stringPrint);

            }

            public int Calculate()
            {
                if (LeftElement == null && RightElement == null)
                {
                    return Value - '0';
                }
                switch (Value)
                {
                    case '+':
                        {
                            return LeftElement.Calculate() + RightElement.Calculate();
                        }
                    case '-':
                        {
                            return LeftElement.Calculate() - RightElement.Calculate();
                        }
                    case '*':
                        {
                            return LeftElement.Calculate() * RightElement.Calculate();
                        }
                    case '/':
                        {
                            return LeftElement.Calculate() / RightElement.Calculate();
                        }
                }
                return 0;
            }
        }
    }
}

