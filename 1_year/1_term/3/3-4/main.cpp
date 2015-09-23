#include <stdio.h>
#include <string.h>

int main()
{
    char userNumber[100];
    printf("This program will minimize your number using same digits as in your number.\nEnter your number: ");
    scanf("%s", userNumber);
    int lengthNumber = strlen(userNumber);
    const int numberDigits = 10;
    int digitArray[numberDigits] = {0};

    for (int i = 0; i < lengthNumber; i++)
        digitArray[userNumber[i] - '0']++;

    if (digitArray[0] != 0)
    {
        int i = 1;
        while ((i < numberDigits) && (digitArray[i] == 0))
            i++;
        if (i == numberDigits)
        {
            printf("0");
            return 0;
        }
        printf("%d", i);
        digitArray[i]--;
    }

    int k = 0;
    while (k < numberDigits)
    {
        for (int i = 0; i < digitArray[k]; i++)
            printf("%d", k);
        digitArray[k] = 0;
        k++;
    }

    return 0;
}
