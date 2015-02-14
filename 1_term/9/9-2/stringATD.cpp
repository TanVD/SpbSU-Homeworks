#include "stringATD.h"
#include <stdio.h>
#include <cstring>

struct StringATD
{
    char* string;
    int maxLength;
    int length;
};

StringATD* cloneString(StringATD* currentString)
{
    StringATD* newString = new StringATD;
    newString->string = new char[currentString->length];
    newString->maxLength = currentString->maxLength;
    memset(newString->string, '\0', newString->maxLength);
    for (int i = 0; i < currentString->maxLength; i++)
    {
        newString->string[i] = currentString->string[i];
    }
    newString->length = currentString->length;
    return newString;
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

StringATD* doublingTheString(StringATD* currentString)
{
    StringATD* newString = cloneString(currentString, 2);
    deleteString(currentString);
    return newString;
}

StringATD* readLine(StringATD* currentString)
{
    char c = '\0';
    int index = 0;
    while ((c = getchar()) != '\n')
    {
        currentString->string[index] = c;
        if (index + 1 == currentString->maxLength)
        {
            currentString = doublingTheString(currentString);
        }
        index++;
    }
    currentString->length = index;
    return currentString;
}

StringATD* readLine(StringATD* currentString, FILE* file)
{
    char c = getc(file);
    int index = 0;
    while (!feof(file) && (c != '\n'))
    {
        currentString->string[index] = c;
        if (index + 1 == currentString->maxLength)
        {
            currentString = doublingTheString(currentString);
        }
        index++;
        c = getc(file);
    }
    currentString->length = index;
    if (currentString->string[index - 1] == '\r')
    {
        currentString->string[index - 1] = '\0';
        currentString->length--;
    }
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

StringATD* createStringATD()
{
    StringATD* newString = new StringATD;
    newString->string = new char[2];
    newString->maxLength = 2;
    newString->length = 0;
    memset(newString->string, '\0', newString->maxLength);
    newString = readLine(newString);
    return newString;
}

StringATD* createStringATD(int maxLength)
{
    StringATD* newString = new StringATD;
    newString->string = new char[maxLength];
    newString->maxLength = maxLength;
    newString->length = 0;
    memset(newString->string, '\0', newString->maxLength);
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

char indexElement(StringATD* string, int index)
{
    return string->string[index];
}
