#include <QtTest/QTest>
#include <QtCore/QObject>
#include "testBypassMatrix.h"
#include <iostream>
#include "fileOut.h"

int main()
{
    BypassMatrixTest test;
    QTest::qExec(&test);
    std::cout << "This program will print your matrix spiral way.\nEnter size of matrix: ";
    int size = 0;
    std::cin >> size;
    Matrix *matrix = new Matrix(size);
    std::cout << "Do you want to print to the file or to the console?\n1 - console\n2 - file\nEnter mode: ";
    int mode = 0;
    std::cin >> mode;
    if (mode == 1)
    {
        OutputInterface* outInt = new ConsoleOut(matrix);
        outInt->out();
        delete outInt;
    }
    else if (mode == 2)
    {
        OutputInterface* outInt = new FileOut(matrix);
        outInt->out();
        delete outInt;
    }
    delete matrix;
}

