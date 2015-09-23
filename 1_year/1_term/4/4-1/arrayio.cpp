#include <stdio.h>
#include "randassist.h"
#include <stdlib.h>

void fillArray(int myArray[], int lengthArray, int lastRandNumber, bool withMinus)
{
    randomizeRand();
    if (withMinus)
    {
        for (int i = 1; i < lengthArray; i++)
        {
            myArray[i] = rand() % (2 * lastRandNumber + 1) - lastRandNumber;
        }
    }
    else
    {
        for (int i = 1; i < lengthArray; i++)
        {
            myArray[i] = rand() % (lastRandNumber + 1);
        }
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
