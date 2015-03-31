using System;
using System.IO;

namespace _C
{
    /// <summary>
    /// Class ParserOfEquation implements simple parsing mechanism for text equation into binary tree
    /// </summary>
    public class ParserOfEquation
    {
        private static StreamReader sw;

        /// <summary>
        /// Parses the file to ariph tree.
        /// </summary>
        /// <returns>Ariph tree which is result of parsing</returns>
        /// <param name="filename">Name of file to parse.</param>
        public static AriphTree ParseFile(string filename)
        {
            sw = new StreamReader(filename);
            string equation = sw.ReadToEnd();
            AriphTree tree = new AriphTree(equation[1]);
            for (int i = 2; i < equation.Length; i++)
            {
                if (equation[i] == '(')
                {
                    if (tree.IsLeftFree())
                    {
                        tree.СreateLeftElement(equation[i + 1]);
                        tree.DownLeft();
                    }
                    else
                    {
                        tree.СreateRightElement(equation[i + 1]);
                        tree.DownRight();
                    }
                }
                else if (equation[i] == ')')
                {
                    tree.Up();
                }
                else if (Char.IsDigit(equation[i]))
                {
                    if (tree.IsLeftFree())
                    {
                        tree.СreateLeftElement(equation[i]);
                    }
                    else
                    {
                        tree.СreateRightElement(equation[i]);
                    }
                }
            }
            tree.SetDefault();
            return tree;
        }
    }
}

