#pragma once
#include "sortInterface.h"
/**
 * @brief The QuickSort class sorting using cormen quick sort algorithm
 */
class QuickSort : public SortInterface
{
public:
    /**
     * @brief QuickSort constructor
     * @param ArrayToSort array which will be sorted by ref
     * @param LengthArrayToSort length of array to sort
     */
    QuickSort(int* arrayToSort, int lengthArrayToSort);
    /**
     * @brief SortArray implementation of virtual interface function of sorting
     * @detailed Quicksort function which uses median random cormen algorithm
     */
    void sortArray();
private:
    int* array;
    int lengthArray;
    void quickSort(int *a, int start, int end);
    int makeParts(int *a, int start, int strongPoint);
};

