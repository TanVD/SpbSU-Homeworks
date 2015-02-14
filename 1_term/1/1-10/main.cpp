#include <stdio.h>

int lenStringFunc(char myString[])
{
    int length = 0;
    while (myString[length] != 0)
    {
        length++;
    }
    return length;
}

int main()
{
    char myString[101] = {0};
    printf("Hello, this program will check your string and print is it palindrome or not.\nDo not use spacebars and tabulations.");
    printf("\nPrint you string: ");
    int length = 0;
    scanf("%s", myString); // It works only without spacebar and tabulation at a string.
    length = lenStringFunc(myString);
    int i = 0;
    bool answer = true;
    for (i = 0; i < (length / 2 + 1); i++)
    {
        if (myString[i] != myString[length - 1 - i])
        {
            answer = false;
            break;
        }
    }
    if (answer)
        printf("It is a palindrome");
    else
        printf("It is not a palindrome");
    return 0;
}
