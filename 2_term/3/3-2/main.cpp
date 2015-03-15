#include <iostream>
#include "outputInterface.h"
#include "fileOut.h"
#include "consoleOut.h"
#include "matrix.h"
using namespace std;

int main()
{
    cout << "This program will print your matrix spiral way.\nEnter size of matrix: ";
    int size = 0;
    cin >> size;
    Matrix *matrix = new Matrix(size);
    cout << "Do you want to print to the file or to the console?\n1 - console\n2 - file\nEnter mode: ";
    int mode = 0;
    cin >> mode;
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

