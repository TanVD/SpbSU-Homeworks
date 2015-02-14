#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <time.h>

using namespace std;

void randomizeRand()
{
    long timeSeed = time(NULL);
    srand(timeSeed);
}

void fillArray(int myArray[], int lengthArray)
{
    for (int i = 1; i < lengthArray; i++)
    {
        myArray[i] = rand() % 1000000000 - 500;
    }
}

void inputArray(int myArray[], int lengthArray)
{
    for (int i = 1; i < lengthArray; i++)
    {
        scanf("%d", &myArray[i]);
    }
}

void outputArray(int myArray[], int lengthArray)
{
    for (int i = 1; i < lengthArray; i++)
    {
        printf("%d ", myArray[i]);
    }
    printf("\n");
}

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

void pyramidalSort (int myArray[], int end)
{
    if (end > 1)
    {
        siftDown(myArray, end);
        pyramidalSort(myArray, end - 1);
    }
}

int main()
{
    randomizeRand();
    const int lengthArray = 2500 + (1);
    int myArray[lengthArray];
    printf("This program will sort your array. Please enter numbers.\n");
    //inputArray(myArray, lengthArray);
    fillArray(myArray, lengthArray);
    //outputArray(myArray, lengthArray);
    pyramidalSort(myArray, lengthArray - 1);
    outputArray(myArray, lengthArray);
    return 0;
}
