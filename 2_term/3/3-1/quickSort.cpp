#include "quickSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


QuickSort::QuickSort(int* arrayToSort, int lengthArrayToSort) :
    array(arrayToSort), lengthArray(lengthArrayToSort)
{
}

int QuickSort::makeParts(int *a, int start, int strongPoint)
{
    int myArray[3];
    long timeSeed = time(NULL);
    srand(timeSeed);
    myArray[0] = rand() % (strongPoint - start + 1) + start;
    myArray[1] = rand() % (strongPoint - start + 1) + start;
    myArray[2] = rand() % (strongPoint - start + 1) + start;
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k < (2-i); k++)
        {
            if (a[myArray[k]] > a[myArray[k + 1]])
            {
                mySwap(&myArray[k], &myArray[k + 1]);
            }
        }
    }
    mySwap(&a[myArray[2]], &a[strongPoint]);

    int afterSepElement = start;
    for (int i = start; i < strongPoint; i++)
    {
        if (a[i] <= a[strongPoint])
        {
            mySwap(&a[afterSepElement], &a[i]);
            ++afterSepElement;
        }
    }
    mySwap(&a[afterSepElement], &a[strongPoint]);
    int result = afterSepElement;
    return result;
}

void QuickSort::quickSort(int *a, int start, int end)
{
    if (start < end)
    {
        int sepPoint;
        sepPoint = makeParts(a, start, end);
        quickSort(a, start, sepPoint - 1);
        quickSort(a, sepPoint + 1, end);
    }
}

void QuickSort::sortArray()
{
    quickSort(array, 0, lengthArray - 1);
}
