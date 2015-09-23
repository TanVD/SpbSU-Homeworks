#include <iostream>
#include <string>
#include <stdio.h>
#include "inftopostform.h"

using namespace std;

int main()
{

    const int lengthOfString = 1000;
    printf("This program will convert infix notation of you equation into postfix.\nEnter the equation: ");
    char expressionIn[lengthOfString];
    char c;
    int j  = 0;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            expressionIn[j] = c;
            j++;
        }

    }

    char expressionPost[lengthOfString];
    int expressionPostEnd = infToPostForm(expressionIn, expressionPost, j);
    printf("Your postfix equation is ");
    for (j = 0; j < expressionPostEnd; j++)
    {
        cout << expressionPost[j];
    }
    cout << endl;
}
