#include <iostream>
#include "outputInterface.h"
#include "fileOut.h"
#include "consoleOut.h"

using namespace std;

int main()
{
    cout << "This program will print your matrix spiral way.\nEnter size of matrix: ";
    int size = 0;
    cin >> size;
    cout << "Enter matrix: " << endl;
    int **matrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int element;
            cin >> element;
            matrix[i][j] = element;

        }
    }
    int centerSize = size / 2;
    int radius = 1;
    int* arrayToOut = new int[size * size];
    int counter = 0;
    arrayToOut[counter] = matrix[centerSize][centerSize];
    counter++;
    while (radius <= centerSize)
    {
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            arrayToOut[counter] = matrix[centerSize + radius][centerSize - radius + i];
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            arrayToOut[counter] = matrix[centerSize + radius - i][centerSize + radius];
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            arrayToOut[counter] = matrix[centerSize - radius][centerSize + radius - i];
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            arrayToOut[counter] = matrix[centerSize - radius + i][centerSize - radius];
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
        cout << "Enter the name of file: ";
        char* filename = new char[200];
        for (int i = 0; i < 200; i++)
            filename[i] = '\0';
        cin >> filename;
        OutputInterface* outInt = new FileOut(filename, arrayToOut, counter);
        outInt->out();
        delete[] filename;
        delete outInt;
    }
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] arrayToOut;
}

