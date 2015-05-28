#include "outputInterface.h"
#include "matrix.h"
OutputInterface::OutputInterface() : array(nullptr), lengthArray(0)
{
}

int *OutputInterface::returnBypass()
{
    return array;
}

void OutputInterface::bypassMatrix(Matrix* matrix)
{
    int centerSize = matrix->getSize() / 2;
    int radius = 1;
    array =  new int[matrix->getSize() * matrix->getSize()];
    int counter = 0;
    array[counter] = matrix->getByIndex(centerSize, centerSize);
    counter++;
    while (radius <= centerSize)
    {
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            array[counter] = matrix->getByIndex(centerSize + radius, centerSize - radius + i);
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            array[counter] = matrix->getByIndex(centerSize + radius - i, centerSize + radius);
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            array[counter] = matrix->getByIndex(centerSize - radius, centerSize + radius - i);;
            counter++;
        }
        for (int i = 1; i < radius * 2 + 1; i++)
        {
            array[counter] = matrix->getByIndex(centerSize - radius + i, centerSize - radius);;
            counter++;
        }
        radius++;
    }
    lengthArray = matrix->getSize() * matrix->getSize();
}
