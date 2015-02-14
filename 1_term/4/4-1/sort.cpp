#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void siftUp(int myArray[], int i, int end)
{
    if (i >= 1)
    {
        int evenBranch = i * 2;
        int oddBranch = i * 2 + 1;
        if ((evenBranch <= end) && (myArray[i] < myArray[evenBranch]))
        {
             swap(myArray[i], myArray[evenBranch]);
             siftUp(myArray, i / 2, end);
        }
        if ((oddBranch <= end) && (myArray[i] < myArray[oddBranch]))
        {
             swap(myArray[i], myArray[oddBranch]);
             siftUp(myArray, i / 2, end);
        }

    }
}

void siftDown(int myArray[], int end)
{
    for (int i = 1; i < (end / 2 + 1); i++)
    {
        siftUp(myArray, i, end);
    }
    swap(myArray[1], myArray[end]);
}

void pyramidalSort(int myArray[], int end)
{
    if (end > 1)
    {
        siftDown(myArray, end);
        pyramidalSort(myArray, end - 1);
    }
}
