#include "fileOut.h"
#include <fstream>

FileOut::FileOut(char *filename, int *array, int lengthArray) : filename(filename),
    array(array), lengthArray(lengthArray)
{
}

void FileOut::out()
{
    std::ofstream output(filename);
    for (int i = 0; i < lengthArray; i++)
    {
        output << array[i] << " ";
    }

}

