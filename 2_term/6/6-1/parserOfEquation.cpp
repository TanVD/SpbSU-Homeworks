#include "parserOfEquation.h"
#include  <fstream>
#include <QFile>
#include <QTextStream>
using namespace std;

AriphTree *ParserOfEquation::parseFile(QFile *file)
{
    file->open(QIODevice::ReadOnly);
    QTextStream in(file);
    QString equation = in.readLine();
    if (!file->exists())
    {
        return nullptr;
    }
    AriphTree *tree = new AriphTree(equation[1]);
    for (unsigned int i = 2; i < equation.length(); i++)
    {
        if (equation[i] == '(')
        {
            if (tree->isLeftFree())
            {
                tree->createLeftElement(equation[i + 1]);
                tree->moveToLeftChild();
            }
            else
            {
                tree->createRightElement(equation[i + 1]);
                tree->moveToRightChild();
            }
        }
        else if (equation[i] == ')')
        {
            tree->up();
        }
        else if (equation[i].isDigit())
        {
            if (tree->isLeftFree())
            {
                tree->createLeftElement(equation[i]);
            }
            else
            {
                tree->createRightElement(equation[i]);
            }
        }
    }
    tree->setDefault();
    return tree;
}
