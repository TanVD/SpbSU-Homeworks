#include <iostream>
#include <string>
#include <stdio.h>
#include "inftopostform.h"
#include "postcalculate.h"

using namespace std;

int main()
{
    const int lengthOfString = 1000;
    printf("This program will calculate your equation.\nPlease, enter the equation: ");
    char expressionIn[lengthOfString];
    char c;
    int j  = 0;
    bool isValid = true;

    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            expressionIn[j] = c;
            j++;
        }

    }

    char expressionPost[lengthOfString];
    int expressionPostEnd = infToPostform(expressionIn, expressionPost, j);
    double x = postCalculate(expressionPost, expressionPostEnd, &isValid);
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
