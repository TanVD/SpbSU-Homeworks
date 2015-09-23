#include <iostream>
#include <string>
#include <stdio.h>
#include "postcalculate.h"

using namespace std;

int main()
{
    const int lengthOfString = 1000;
    printf("This program will calculate your postfix equation.\nEnter the equation: ");
    char expressionPost[lengthOfString];
    char c;
    int j  = 0;
    bool isValid = true;

    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            expressionPost[j] = c;
            j++;
        }

    }

    double x = postCalculate(expressionPost, j, &isValid);
    if (isValid)
    {
        printf("Your result is ");
        cout << x << endl;
    }
    else
    {
        printf("Non-valid arguments.\nAnswer to The Ultimate Question of Life, the Universe, and Everything is 42.\n");
    }

}
