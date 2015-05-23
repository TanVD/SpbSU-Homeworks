#pragma once
#include "sortInterface.h"
/**
 * @brief The BubbleSort class sorting using bubble sort algorithm
 */
class BubbleSort : public SortInterface
{
public:
    /**
     * @brief BubbleSort constructor
     * @param ArrayToSort array which will be sorted by ref
     * @param LengthArrayToSort length of array to sort
     */
    BubbleSort(int* arrayToSort, int lengthArrayToSort);

    /**
     * @brief SortArray implementation of virtual interface function of sorting
     * @detailed Implementation uses trivial bubble sort algorithm
     */
    void sortArray();

private:
    int* array;
    int lengthArray;
};

