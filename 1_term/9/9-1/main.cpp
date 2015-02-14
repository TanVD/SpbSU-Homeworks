#include <iostream>
#include <fstream>
#include "stringATD.h"
#include "rabin-carp.h"

int main()
{
    char fileFirstLocation[100];
    char fileSecondLocation[100];
    std::cout << "This program will create file which contain idenctical lines of two chosen files";
    std::cout << "Enter location of first file: ";
    std::cin >> fileFirstLocation;
    std::cout << "Enter location of second file: ";\
    std::cin >> fileSecondLocation;
    FILE* text1 = fopen(fileFirstLocation, "r");
    FILE* text2 = fopen(fileSecondLocation, "r");
    if (text1 == nullptr || text2 == nullptr)
    {
        std::cout << "Didn't find your file";
        return 1;
    }

    StringATD* firstTextString = createStringATD(text1);
    StringATD* secondTextString = createStringATD(text2);
    std::ofstream out("newText.txt");
    int indexFirst = 0;
    for (int i = 0; i < lengthOfString(firstTextString); i++)
    {
        if ((indexElement(firstTextString, i) == '\n') || (i == lengthOfString(firstTextString) - 1))
        {
            int length = i - indexFirst + 1;
            StringATD* stringForSearch = subString(firstTextString, indexFirst,  length);
            if (rabinCarp(secondTextString, stringForSearch))
            {
                char* outArray = transformToChar(stringForSearch);
                for (int i = 0; i < lengthOfString(stringForSearch) - 1; i++)
                {
                    out << outArray[i];
                }
                out << '\n';
                delete[] outArray;
            }
            deleteString(stringForSearch);
            indexFirst = i + 1;
        }
    }
    deleteString(firstTextString);
    deleteString(secondTextString);
    out.close();
    fclose(text1);
    fclose(text2);
    std::cout << "File created";
    return 0;
}
