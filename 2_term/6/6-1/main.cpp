#include "ariphTree.h"
#include "parserOfEquation.h"
#include <iostream>
#include <string>
#include <QTextStream>
#include "parserTest.h"

using namespace std;

int main()
{
    ParserTest test;
    QTest::qExec(&test);
    cout << "This program will calculate your equation tree.\nEnter the name of file: ";
    QTextStream str(stdin);
    QString filename = str.readLine();
    QFile *file = new QFile(filename);
    if (!file->exists())
    {
        cout << "Oops... Didn't found!";
        return 1;
    }
    AriphTree* tree = ParserOfEquation::parseFile(file);
    cout << "Your answer is " << tree->calculateTree() << endl;
    delete file;
    delete tree;
}
