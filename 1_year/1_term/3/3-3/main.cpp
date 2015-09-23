#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void randomizeRand()
{
    long timeSeed = time(NULL);
    srand(timeSeed);
}


int module(int number)
{
    if (number < 0)
        number = -number;
    return number;
}

int main()
{
    printf("This program will create 2D array, print this array.\nThen it will will print numbers reading by the spiral line (right-down-left-up) from array.\n");
    const int lengthMyArray = 3;
    if (lengthMyArray % 2 == 0)
    {
        printf("Invalid size of array");
        return 1;
    }
    int myArray [lengthMyArray][lengthMyArray];

    /*for (int i = 0; i < lengthMyArray; i++)
        for (int k = 0; k < lengthMyArray; k++)
        {
            scanf("%d", &myArray[i][k]);
        }*/

    randomizeRand();

    for (int  i = 0; i < lengthMyArray; i++)
        for (int  k = 0; k < lengthMyArray; k++)
        {
            myArray[i][k] = rand() % 1000 - 500;
        }
        
    printf("Your array:\n");
    for (int i = 0; i < lengthMyArray; i++)
    {
        for (int k = 0; k < lengthMyArray; k++)
        {
            printf("%d ", myArray[i][k]);
        }
        printf("\n");
    }

    int start = (lengthMyArray - 1) / 2;
    int i = start;
    int k = start;
    int step = 1;
    printf("Spiral:\n");
    printf("%d ", myArray[i][k]);

    while (step < lengthMyArray / 2 + 1)
    {
        while (module(k - start) < step)
        {
            k++;
            printf("%d ", myArray[i][k]);
        }

        while (module(i - start) < step)
        {
            i++;
            printf("%d ", myArray[i][k]);
        }

        k--;
        printf("%d ", myArray[i][k]);
        while (module(k - start) < step)
        {
            k--;
            printf("%d ", myArray[i][k]);
        }

        i--;
        printf("%d ", myArray[i][k]);
        while (module(i - start) < step)
        {
            i--;
            printf("%d ", myArray[i][k]);
        }

        step++;
    }

    while (module(k - start) < step)
        {
            k++;
            printf("%d ", myArray[i][k]);
            if ((i == 0) && (k == lengthMyArray - 1))
                break;
        }

    return 0;
}
