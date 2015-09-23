#include <stdio.h>
#include "randassist.h"
#include "arrayio.h"
#include "sort.h"

using namespace std;

int main()
{
    const int lengthArray = 10;
    int myArray[lengthArray] = {0};
    printf("This program will calculate the biggest repeating element of sequence.\nSequence will be created automaticly\n");
    fillArray(myArray, lengthArray, 10, true);
    //printf("This program will calculate the biggest repeating element of sequence.\nEnter the sequence:\n");
    //inputArray(myArray, lengthArray);
    pyramidalSort(myArray, lengthArray - 1); //n*log(n)
    bool isMaxNotFilled = true;
    int max = 0;
    for (int i = 0; i < lengthArray - 1; i++)
    {
        if (myArray[i] == myArray[i + 1])
            if (isMaxNotFilled || (myArray[i] > max))
            {
                max = myArray[i];
                if (isMaxNotFilled)
                    isMaxNotFilled = false;
            }

    }

    if ((max == 0) && (isMaxNotFilled))
    {
      //outputArray(myArray, lengthArray);
        printf("This sequence have no repeating elements\n");
        return 0;
    }

    printf("%d max\n", max);
    //outputArray(myArray, lengthArray);
    return 0;
}

