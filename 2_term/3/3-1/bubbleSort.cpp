#include "bubbleSort.h"

BubbleSort::BubbleSort(int* arrayToSort, int lengthArrayToSort)
    : array(arrayToSort), lengthArray(lengthArrayToSort)
{
}

void BubbleSort::sortArray()
{
    for (int i = 0; i < lengthArray - 1; i++)
    {
        for (int j = 0; j < lengthArray - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                mySwap(&array[j], &array[j + 1]);
            }
        }
    }

}

