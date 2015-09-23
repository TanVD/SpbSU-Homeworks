#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void mySwap(int *a,int *b)
{
    if (*a != *b)
    {
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
    }

}

//Quicksort for use modified for three arrays. ContigData ==  contiguous data
int makeParts(double *a, int *contigData1, int *contigData2, int start, int strongpoint);

void quickSort(double *a, int *contigData1, int *contigData2, int start, int end)
{
    if (start < end)
    {
        int sepPoint;
        sepPoint = makeParts(a, contigData1, contigData2, start, end);
        quickSort(a, contigData1, contigData2, start, sepPoint - 1);
        quickSort(a, contigData1, contigData2, sepPoint + 1, end);
    }
}

void randomizeRand()
{
    long timeSeed = time(NULL);
    srand(timeSeed);
}

int makeParts(double *a, int *contigData1, int *contigData2, int start, int strongPoint)
{
    int myArray[3];
    randomizeRand();
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

    double tmp = 0;
    tmp = a[myArray[2]];
    a[myArray[2]] = a[strongPoint];
    a[strongPoint] = tmp;
    mySwap(&contigData1[myArray[2]], &contigData1[strongPoint]);
    mySwap(&contigData2[myArray[2]], &contigData2[strongPoint]);

    int afterSepElement = start;
    for (int i = start; i < strongPoint; i++)
    {
        if (a[i] <= a[strongPoint])
        {
            tmp = a[afterSepElement];
            a[afterSepElement] = a[i];
            a[i] = tmp;
            mySwap(&contigData1[afterSepElement], &contigData1[i]);
            mySwap(&contigData2[afterSepElement], &contigData2[i]);
            ++afterSepElement;
        }
    }

    tmp = a[afterSepElement];
    a[afterSepElement] = a[strongPoint];
    a[strongPoint] = tmp;
    mySwap(&contigData1[afterSepElement], &contigData1[strongPoint]);
    mySwap(&contigData2[afterSepElement], &contigData2[strongPoint]);

    int result = afterSepElement;
    return result;
}
//Greatest common decrement for use algorithm (gives true if GCD == 1)
int GCD(int x, int y)
{
    if (y == 0)
        return x;
    return GCD(y, (x % y));
}

bool tryGCD(int firstElement, int secondElement)
{
    if (firstElement < secondElement)
        mySwap(&firstElement, &secondElement);
    int result = GCD(firstElement, secondElement);
    if (result == 1)
        return true;
    else
        return false;
}


int main()
{
    const int lengthMyArray = 10000;
    int myNumArray[lengthMyArray] = {0};
    int myDenArray[lengthMyArray] = {0};
    int activeArrayElement = 0;
    printf("This program will print all fractions made of prime denominator and numerator to the selected denominator.\nPlease, enter denominator: ");
    int maxDenominator = 0;
    scanf("%d", &maxDenominator);
    maxDenominator++; // now it is not less denominator, it is less or equal denominator
    for (int i = 1; i < maxDenominator; i++)
        for (int j = 1; j < i; j++)
        {
            if (tryGCD(i, j))
            {
                myNumArray[activeArrayElement] = j;
                myDenArray[activeArrayElement] = i;
                activeArrayElement++;
            }
        }
    //activeArrayElement now is equal to the length of array because of the last increment.
    double myTotalArray [lengthMyArray] = {0};
    for (int i = 0; i < activeArrayElement; i++)
    {
        myTotalArray[i] = double(myNumArray[i]) / myDenArray[i];
    }

    quickSort(myTotalArray, myNumArray, myDenArray, 0, activeArrayElement-1);

    int i = 0;
    while (i < activeArrayElement)
    {
        printf("%d/%d ", myNumArray[i], myDenArray[i]);
        i++;
    }

    return 0;
}
