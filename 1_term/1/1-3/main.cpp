#include <stdio.h>

void mySwap(int *a, int *b)
{
    if (*a != *b)
    {
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
    }

}

void reverseMyArray(int myArray[], int start, int end)
{
    int i;
    int lengthMyArray = end - start +1;
    for (i = start; i < ((lengthMyArray)/2 + start); i++)
    {
        mySwap(&myArray[i], &myArray[2*start + lengthMyArray - i - 1]);
    }
}



int main()
{
    int myArray[100];
    printf("Enter the length of array: ");
    int lengthArray;
    scanf("%d", &lengthArray);
    printf("One by one enter the elements of array\n");
    int i;
    for (i = 0; i < lengthArray; i++ )
    {
        printf("%d element: ", i + 1); // Cause array must start with element number 1 (from task)
        scanf("%d", &myArray[i]);
    }
    printf("Please, enter the number of element m to separate array.\nThe array will be separated to [0..m] and [m+1..n-1] parts.\nEnter m: ");
    int sepElement;
    scanf("%d", &sepElement);
    reverseMyArray(myArray, 0, sepElement - 1);
    reverseMyArray(myArray, sepElement, lengthArray - 1);
    reverseMyArray(myArray, 0, lengthArray - 1);
    printf("New array:");
    for (i = 0; i < lengthArray; i++ )
    {
        printf("%d ", myArray[i]);
    }
    return 0;
}
