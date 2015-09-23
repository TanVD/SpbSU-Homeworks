#include "fileOut.h"
#include "matrix.h"
#include <fstream>
#include <iostream>

FileOut::FileOut(Matrix* matrix)
{
    bypassMatrix(matrix);
}

void FileOut::out()
{
    std::cout << "Enter the name of file: ";
    char* filename = new char[200];
    for (int i = 0; i < 200; i++)
        filename[i] = '\0';
    std::cin >> filename;
    std::ofstream output(filename);
    for (int i = 0; i < lengthArray; i++)
    {
        output << array[i] << " ";
    }
    delete[] filename;
    output.close();
}

FileOut::~FileOut()
{
    if (array != nullptr)
        delete[] array;
}

