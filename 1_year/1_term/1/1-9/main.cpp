#include <stdio.h>

int main()
{
    int number = 0;
    int degree = 0;
    printf("This program will calculate A^n.\nPlease enter A: ");
    scanf("%d", &number);
    printf("Please, enter n: ");
    scanf("%d", &degree);
    int i;
    if ((degree <= 0) && (number == 0))
    {
        printf("Invalid operation");
        return 0;
    }
    if (degree >= 0)
    {
        int result = 1;
        for (i = degree; i > 0; i--)
            {
                result *= number;
            }
        printf("The result is %d", result);
    }
    else
    {
        double result = 1.0;
        for (i = degree; i < 0; i++)
        {
            result /= number;
        }
        printf("The result is %f", result);
    }

    return 0;
}
