#include "fileOut.h"
#include <fstream>
#include <iostream>

FileOut::FileOut(int *array, int lengthArray) : array(array), lengthArray(lengthArray)
{
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

}

