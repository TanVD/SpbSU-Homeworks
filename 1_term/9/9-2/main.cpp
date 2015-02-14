#include <stdio.h>
#include "stringATD.h"
#include <iostream>

const int module = 178997;
const int factor = 101;

int intPow(int x, int y)
{
    int pow = 1;
    for (int i = 0; i < y; i++)
    {
        pow = pow * x % module;
    }
    return pow;
}


int hash(StringATD* myString)
{
    int result = 0;
    for (int i  = 0; i < lengthOfString(myString); i++)
    {
        result = (result * factor + indexElement(myString, i)) % module;
    }
    return result;
}

int hash(StringATD* myString, int recentHash, int power)
{
    //int hashRetry = hash(subString(myString, 1, LengthOfString(myString) - 1)); //TODO To test function
    int result = recentHash;
    result = (result - indexElement(myString, 0) * power) * factor % module + indexElement(myString, lengthOfString(myString) - 1) % module;
    if (result < 0)
        result += module;
    return result;
}

int main()
{
    std::cout << "This program will find all entries of substring in your string.\nEnter the location of file with string and substring: ";
    char* fileLocation = new char[100];
    std::cin >> fileLocation;
    FILE* text = fopen(fileLocation, "r");
    if (text == nullptr)
    {
        delete[] fileLocation;
        return 1;
    }
    StringATD* s = createStringATD(text);
    StringATD* sub = createStringATD(text);
    fclose(text);
    //printf("Enter the string: ");
    //StringATD* s = createStringATD();
    //printf("Enter the substring: ");
    //StringATD* sub = createStringATD();
    bool isSub = true;
    int powerFirstCof = intPow(factor, lengthOfString(sub) - 1);
    int hashResult = hash(sub);
    int hashInt = hash(subString(s, 0, lengthOfString(sub)));
    for (int i = 1; i < lengthOfString(s) - lengthOfString(sub) + 2; i++)
    {
        if (hashInt == hashResult)
        {
            for (int j = 0; j < lengthOfString(sub); j++)
            {
                if (indexElement(sub, j) != indexElement(s, j + i -1))
                {
                    isSub = false;
                    break;
                }
            }
            if (isSub)
            {
                printf("Position %d\n", i);
            }
            else
            {
                isSub = true;
            }
        }
        hashInt = hash(subString(s, i - 1, lengthOfString(sub) + 1), hashInt, powerFirstCof);
    }
    deleteString(s);
    deleteString(sub);
    delete[] fileLocation;
    return 0;
}

