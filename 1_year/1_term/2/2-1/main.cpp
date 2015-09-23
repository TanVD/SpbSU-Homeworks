#include <stdio.h>

int recursiveFibbonachi(int number)
{
    if (number < 1)
        return 0;
    if (number == 1)
        return 1;
    return recursiveFibbonachi(number - 1) + recursiveFibbonachi(number - 2);
}

int iterativeFibbonachi(int number)
{
   int num1Fib = 1;
   int num2Fib = 0;
   int result = 0;
   for (int i = 1; i < number + 1; i++)
   {
       result = num2Fib + num1Fib;
       num1Fib = num2Fib;
       num2Fib = result;
   }
   return num2Fib;
}

int main()
{
    printf("Print the last number of sequence: ");
    int number = 0;
    scanf("%d", &number);
    printf("Iterative algorithm give %d\n", iterativeFibbonachi(number));
    printf("Recursive algorithm give %d", recursiveFibbonachi(number));
    return 0;
}
