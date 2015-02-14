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

void deleteString(StringATD* string)
{
    delete[] string->string;
    delete string;
}

StringATD* doublingTheString(StringATD* currentString)
{
    char* lastString = currentString->string;
    currentString->string = new char[currentString->maxLength * 2];
    memset(currentString->string, '\0', currentString->maxLength * 2);
    for (int i = 0; i < currentString->maxLength; i++)
    {
        currentString->string[i] = lastString[i];
    }
    currentString->maxLength = currentString->maxLength * 2;
    delete[] lastString;
    return currentString;
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

StringATD* concutString(StringATD* firstString, StringATD* secondString)
{
    int firstStringLength = firstString->length;
    int secondStringLength = secondString->length;
    int sum = firstStringLength + secondStringLength;
    StringATD* resultString = createStringATD(sum + 1);
    for (int j = 0; j < firstStringLength; j++)
    {
        resultString->string[j] = firstString->string[j];
    }
    for (int j = firstStringLength; j < sum; j++)
    {
        resultString->string[j] = secondString->string[j - firstStringLength];
    }
    resultString->length = sum;
    return resultString;
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

bool isEmptyString(StringATD* currentString)
{
    return currentString->length == 0;
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
    for (int j = 0; j < currentString->length; j++)
    {
        newCharArray[j] = currentString->string[j];
    }
    return newCharArray;
}
