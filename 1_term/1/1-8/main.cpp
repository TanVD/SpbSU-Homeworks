#include <stdio.h>

int factRecursive(int a)
{
   if (a > 1)
        a = a * factRecursive(a - 1);
    return a;
}

int factIterative(int a)
{
    int result = 1;
    while (a > 1)
    {
        result *= a;
        a--;
    }
    return result;
}

int main()
{
    printf("Please, enter the number and this program will calculate factorial of it.");
    printf("\nEnter the number: ");
    int number;
    scanf("%d", &number);
    printf("Recursive factorial is: %d\n", factRecursive(number));
    printf("Iterative factorial is: %d\n", factIterative(number));
    return 0;
}
