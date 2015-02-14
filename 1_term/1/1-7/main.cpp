#include <stdio.h>
#include <math.h>

int main()
{
    printf("This program will print all prime numbers from 2 to number M ");
    int number = 0;
    scanf("%d", &number);
    int i = 2;
    int j = 2;
    bool primeAnswer = true;
    for (i = 2; i < number + 1; i++)
    {
        primeAnswer = true;
        for (j = 2; j < sqrt(i + 1); j++)
        {
            if  (i % j == 0)
            {
                primeAnswer = false;
            }
        }
        if (primeAnswer)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
