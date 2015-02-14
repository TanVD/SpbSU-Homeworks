#include <stdio.h>

int main()
{
    char myString[101] = {0};
    printf("Enter the string. This program will check positions of brackets.\nTotal length of the string should be less then 100 symbols.\nDo not use spacebar at your equation.\n");
    scanf("%s", myString); // It works only without spacebar and tabulation at a string.
    int openBracket = 0;
    int closeBracket = 0;
    int i = 0;
    bool answer = true;
    while (myString[i] != 0)
    {
        if (closeBracket > openBracket)
            answer = false;
        if (myString[i] == '(')
            openBracket++;
        else if (myString[i] ==')')
            closeBracket++;
        i++;
    }
    if ((closeBracket == openBracket) && answer)
        printf("All brackets are at you service");
    else
        printf("Something went wrong with brackets");
    return 0;
}
