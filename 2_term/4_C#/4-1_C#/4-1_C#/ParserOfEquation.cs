using System;
using System.IO;

namespace _C
{
    public class ParserOfEquation
    {
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
                else if (equation[i] >= '0' && equation[i] <= '9')
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

        private static StreamReader sw;
    }
}

