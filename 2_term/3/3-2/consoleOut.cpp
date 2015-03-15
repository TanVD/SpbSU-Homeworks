#include "consoleOut.h"
#include <iostream>

ConsoleOut::ConsoleOut(Matrix *matrix)
{
    bypassMatrix(matrix);
}

void ConsoleOut::out()
{
    for (int i = 0; i < lengthArray; i++)
    {
        std::cout << array[i] << " ";
    }

}

ConsoleOut::~ConsoleOut()
{
    if (array != nullptr)
        delete[] array;
}


