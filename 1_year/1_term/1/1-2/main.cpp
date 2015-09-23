#include <stdio.h>

int module(int number)
{
    if (number < 0)
        number = -number;
    return number;
}

int main()
{
    printf("Please, enter numerator and denominator. The program will calculate quotient \n");
    int numerator;
    int denominator;
    printf("Numerator:");
    scanf("%d", &numerator);
    printf("Denominator:");
    scanf("%d", &denominator);
    if (!denominator)
    {
        printf("Not correct");
        return 1;
    }
    bool character = (denominator * numerator < 0);
    denominator = module(denominator);
    numerator = module(numerator);
    int result = 0;
    while (numerator >= denominator)
    {
        numerator = numerator - denominator;
        result++;
    }
    if (character)
        result = -result;
    printf("The quotient is %d",result);
    return 0;
}
