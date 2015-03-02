#include "consoleOut.h"
#include <iostream>

ConsoleOut::ConsoleOut(int *array, int lengthArray) : array(array), lengthArray(lengthArray)
{
}

void ConsoleOut::out()
{
    for (int i = 0; i < lengthArray; i++)
    {
        std::cout << array[i] << " ";
    }

}


