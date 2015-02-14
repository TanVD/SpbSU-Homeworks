#include <stdio.h>
#include <string.h>

void getLetterAmountArray(char myString[], int arrayLetter[], int lengthArray)
{
    for (int i = 0; i < lengthArray; i++)
    {
        arrayLetter[int (myString[i])]++;
    }
}

int main()
{
    printf("This program will tell you if you can get from first string second.\nPrint your first string: ");

    char userString [100] = {0};
    scanf("%s", userString);

    printf("Print your second string: ");
    char subString [100] = {0};
    scanf("%s", subString);

    int arrayLetterUserString [1000] = {0};
    int lengthUserString = strlen(userString);
    getLetterAmountArray(userString, arrayLetterUserString, lengthUserString);

    int arrayLetterSubString [1000] = {0};
    int lengthSubString = strlen(subString);
    getLetterAmountArray(subString,arrayLetterSubString, lengthSubString);

    bool answer = true;
    for (int i = 0; i < 1000; i++)
        if (arrayLetterSubString[i] > arrayLetterUserString[i])
            answer = false;

    if (answer)
        printf("You could");
    else
        printf("You couldn't");

    return 0;
}
