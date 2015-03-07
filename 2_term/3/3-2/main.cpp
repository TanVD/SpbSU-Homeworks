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

    int centerSize = size / 2;
    int radius = 1;
    int* arrayToOut = new int[size * size];
    int counter = 0;
    arrayToOut[counter] = matrix->getByIndex(centerSize, centerSize);
    counter++;
    while (radius <= centerSize)
    {
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            arrayToOut[counter] = matrix->getByIndex(centerSize + radius, centerSize - radius + i);
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            arrayToOut[counter] = matrix->getByIndex(centerSize + radius - i, centerSize + radius);
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            arrayToOut[counter] = matrix->getByIndex(centerSize - radius, centerSize + radius - i);;
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            arrayToOut[counter] = matrix->getByIndex(centerSize - radius + i, centerSize - radius);;
            counter++;
        }
        radius++;
    }
    cout << "Do you want to print to the file or to the console?\n1 - console\n2 - file\nEnter mode: ";
    int mode = 0;
    cin >> mode;
    if (mode == 1)
    {
        OutputInterface* outInt = new ConsoleOut(arrayToOut, counter);
        outInt->out();
        delete outInt;
    }
    else if (mode == 2)
    {
        OutputInterface* outInt = new FileOut(arrayToOut, counter);
        outInt->out();
        delete outInt;
    }
    delete matrix;
    delete[] arrayToOut;
}

