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

bool isLetterFromWord (char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') || (c == '\'' || c =='-'));
}

StringATD* readLine(StringATD* currentString, FILE* file, char mode)
{
    char c = getc(file);
    int index = 0;
    while (!feof(file) && (c!= mode) && isLetterFromWord(c)) //Mode to Stop
    {
        currentString->string[index] = c;
        if (index + 1 == currentString->maxLength)
        {
            currentString = doublingTheString(currentString);
        }
        index++;
        c = getc(file);
    }
    if ((currentString->string[0] == '\'') && (currentString->string[1] == '\0'))
    {
        currentString->length = 0;
        return currentString;
    }
    currentString->length = index;
    return currentString;
}

StringATD* createStringATD(FILE* file, char mode)
{
    StringATD* newString = new StringATD;
    newString->string = new char[2];
    newString->maxLength = 2;
    newString->length = 0;
    memset(newString->string, '\0', newString->maxLength);
    newString = readLine(newString, file, mode);
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

bool isEqualString(StringATD* firstString, StringATD* secondString)
{
    if (firstString->length != secondString->length)
    {
        return false;
    }
    for (int i = 0; i < firstString->length; i++)
    {
        if (firstString->string[i] != secondString->string[i])
            return false;
    }
    return true;
}

int lengthOfString(StringATD* currentString)
{
    return currentString->length;
}

char* transformToChar(StringATD* currentString)
{
    char* newCharArray = new char[currentString->length];
    for (int j = 0; j < currentString->length; j++)
    {
        newCharArray[j] = currentString->string[j];
    }
    return newCharArray;
}
