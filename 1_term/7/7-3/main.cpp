#include <iostream>
#include "stringATD.h"
#include "hashTab.h"
#include "list.h"

const int maxSize = 30000;

int main()
{
    HashTab* hashTable = createHashTable();
    char fileLocation[100];
    std::cout << "This program will create file which contains frequency dictionary of your text";
    std::cout << "Enter location of text: ";
    std::cin >> fileLocation;
    FILE* text = fopen(fileLocation, "r");
    while (!feof(text))
    {
        StringATD* newString = createStringATD(text, ' ');
        if (lengthOfString(newString) != 0)
            hashTable = addElement(hashTable, newString);
    }
    fclose(text);
    printHashTable(hashTable, "NewText.txt");
    std::cout << "Frequency dictionary was created and named NewText.txt\n";
    deleteHashTable(hashTable);
    return 0;
}

