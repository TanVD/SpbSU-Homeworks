#include <stdio.h>
#include <string.h>

int main()
{
    char mainString[100] = {'\0'};
    char subString[10] = {'\0'};
    printf("This program will print the number of you substrings in main string.\nDo not use spacebars or tabulations.\nEnter main string.\n");
    fgets(mainString, 100, stdin);
    printf("Enter substring for searching.\n");
    fgets(subString, 10, stdin);
    int numberEntries = 0;
    int mainStringLength = strlen(mainString);;
    int subStringLength = strlen(subString);
    for (int i = 0; i < mainStringLength - subStringLength + 1; i++)
    {
        bool isEntry = true;
        for (int k = 0; k < (subStringLength); k++)
        {
            if (mainString[i + k] != subString[k])
            {
                isEntry = false;
                break;
            }
        }
        if (isEntry)
            numberEntries++;
    }
    printf("The result is %d", numberEntries);
    return 0;
}
