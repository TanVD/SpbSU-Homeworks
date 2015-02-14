#include <stdio.h>



int main()
{
    printf("Программа расчёта значения формулы x^4+x^3+x^2+x. \n Введите х: ");
    int number;
    scanf("%d",&number);
    int square = number * number;
    int result = square * (square + number) + square + number;;
    printf("\n Результат: %d", result);
    return 0;
}
