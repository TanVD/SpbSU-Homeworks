#include "stringATD.h"
#include <stdio.h>
#include <cstring>

struct StringATD
{
    char* string;
    int maxLength;
    int length;
};

char indexElement(StringATD* currentString, int index)
{
    return currentString->string[index];
}

StringATD* cloneString(StringATD* currentString, int cofmaxLength)
{
    StringATD* newString = new StringATD;
    newString->string = new char[currentString->maxLength * cofmaxLength];
    newString->maxLength = currentString->maxLength * cofmaxLength;
    memset(newString->string, '\0', newString->maxLength);
    for (int i = 0; i < currentString->maxLength; i++)
    {
        newString->string[i] = currentString->string[i];
    }
    newString->length = currentString->length;
    return newString;
}

void deleteString(StringATD* string)
{
    delete[] string->string;
    delete string;
}

StringATD* resizeString(StringATD* currentString)
{
    StringATD* newString = cloneString(currentString, 2);
    deleteString(currentString);
    return newString;
}

StringATD* readLine(StringATD* currentString, FILE* file)
{
    char c = getc(file);
    int index = 0;
    while (!feof(file))
    {
        if (c != '\r')
        {
            currentString->string[index] = c;
            if (index + 1 == currentString->maxLength)
            {
                currentString = resizeString(currentString);
            }
            index++;
        }
        c = getc(file);
    }
    currentString->length = index;
    return currentString;
}

StringATD* createStringATD(FILE* file)
{
    StringATD* newString = new StringATD;
    newString->string = new char[2];
    newString->maxLength = 2;
    newString->length = 0;
    memset(newString->string, '\0', newString->maxLength);
    newString = readLine(newString, file);
    return newString;
}

StringATD* createStringATD(int maxLength)
{
    StringATD* newString = new StringATD;
    newString->string = new char[maxLength];
    newString->maxLength = maxLength;
    newString->length = 0;
    for (int i = 0; i < maxLength; i++)
    {
        newString->string[i] = '\0';
    }
    return newString;
}

int lengthOfString(StringATD* currentString)
{
    return currentString->length;
}

StringATD* subString(StringATD* currentString, int indexFirst, int length)
{
    StringATD* newSubString = createStringATD(length);
    for (int i = indexFirst; i < indexFirst + length; i++)
    {
        char c = currentString->string[i];
        newSubString->string[i - indexFirst] = c;
    }
    newSubString->length = length;
    return newSubString;
}

char* transformToChar(StringATD* currentString)
{
    char* newCharArray = new char[currentString->length];
    memset(newCharArray, '\0', currentString->length);
    for (int j = 0; j < currentString->length; j++)
    {
        newCharArray[j] = currentString->string[j];
    }
    return newCharArray;
}
