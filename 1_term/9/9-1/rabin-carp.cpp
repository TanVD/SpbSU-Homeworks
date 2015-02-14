#include <stdio.h>
#include <stringATD.h>
#include "rabin-carp.h"

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

int rabinCarp(StringATD* s, StringATD* sub)
{
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
                return true;
            }
            else
            {
                isSub = true;
            }
        }
        hashInt = hash(subString(s, i - 1, lengthOfString(sub) + 1), hashInt, powerFirstCof);
    }
    return false;
}

