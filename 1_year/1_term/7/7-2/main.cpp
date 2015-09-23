#include "stringATD.h"

int main()
{
    StringATD* myString = createStringATD();
    StringATD* myString1 = createStringATD();
    StringATD* myConcutString = concutString(myString, myString1);
    StringATD* mySubString = subString(myString, 1, 2);
    int length = lengthOfString(myConcutString);
    deleteString(myString);
    deleteString(myString1);
    deleteString(myConcutString);
    deleteString(mySubString);
}

