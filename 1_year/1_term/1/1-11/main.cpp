//Random Qsort inspired by Cormen "Algorithms Unlocked"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makeParts(int *a, int s, int end);

void mySwap(int *a, int *b)
{
    if (*a != *b)
    {
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
    }

}

void quickSort(int *a, int start, int end)
{
    if (start < end)
    {
        int sepPoint;
        sepPoint = makeParts(a, start, end);
        quickSort(a, start, sepPoint - 1);
        quickSort(a, sepPoint + 1, end);
    }
}

void randomizeRand()
{
    long timeSeed = time(NULL);
    srand(timeSeed);
}

int makeParts(int *a, int start, int strongPoint)
{
    int myArray[3];
    randomizeRand();
     //Changing random element and strong point. (Random qsort from Cormen)
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

int main()
{
    const int lengthArray = 10;
    printf("This program will sort your array. Enter elements of the array.\n");
    int myArray[lengthArray];
    for (int i = 0; i < lengthArray; i++)
    {
        scanf("%d", &myArray[i]);
    }

    quickSort(myArray, 0, lengthArray - 1);

    printf("Sorted array: ");
    for (int i = 0; i < lengthArray; i++)
    {
        printf("%d ", myArray[i]);
    }
    return 0;
}
