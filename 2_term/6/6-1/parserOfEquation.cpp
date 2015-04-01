#include "parserOfEquation.h"
#include  <fstream>
#include <QFile>
#include <QTextStream>
using namespace std;

AriphTree *ParserOfEquation::ParseFile(QFile *file)
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
            if (tree->IsLeftFree())
            {
                tree->CreateLeftElement(equation[i + 1]);
                tree->DownLeft();
            }
            else
            {
                tree->CreateRightElement(equation[i + 1]);
                tree->DownRight();
            }
        }
        else if (equation[i] == ')')
        {
            tree->Up();
        }
        else if (equation[i].isDigit())
        {
            if (tree->IsLeftFree())
            {
                tree->CreateLeftElement(equation[i]);
            }
            else
            {
                tree->CreateRightElement(equation[i]);
            }
        }
    }
    tree->SetDefault();
    return tree;
}
