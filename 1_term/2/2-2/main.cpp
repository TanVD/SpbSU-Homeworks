#include <stdio.h>

int module(int number)
{
    if (number < 0)
        number = -number;
    return number;
}

int getPower(int number, int power)
{
    if (power % 2 != 0)
    {
        int temp = getPower(number, power / 2);
        return temp * temp * number;
    }
    else if (power == 0)
    {
        return 1;
    }
    else
    {
        int temp = getPower(number, power / 2);
        return temp * temp;
    }
}

int main()
{
    printf("This program will calculate A^n.\nPlease, enter A: ");
    int number = 0;
    scanf("%d", &number);
    printf("Please, enter n: ");
    int power = 0;
    scanf("%d", &power);
    if ((number == 0) && (power <= 0))
    {
        printf("\nInvalid argument");
        return 1;
    }
    if (power < 0)
    {
        double result = 1.0 / getPower(number, module(power));
        printf("\nResult is: %lf", result);
    }

    else
    {
         int result = getPower(number, module(power));
         printf("\nResult is: %d", result);
    }
    return 0;
}
