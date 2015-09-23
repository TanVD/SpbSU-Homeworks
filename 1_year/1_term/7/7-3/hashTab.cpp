#include "hashTab.h"
#include "stringATD.h"
#include "list.h"
#include <fstream>

const int maxSize = 30000;

using namespace std;

struct HashTab
{
    int maxSize;
    LinkedList** arrayList;
};

int hashFunction(StringATD* myString)
{
    const int factor = 101;
    int result = 0;
    for (int i  = 0; i < lengthOfString(myString); i++)
    {
        result = (result * factor + indexElement(myString, i)) % maxSize;
    }
    return result;
}

HashTab* createHashTable()
{
    HashTab* newHashTable = new HashTab;
    newHashTable->arrayList = new LinkedList*[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        newHashTable->arrayList[i] = createList();
    }
    newHashTable->maxSize = maxSize;
    return newHashTable;
}

void printHashTable(HashTab* hashTable, char* fileLocation)
{
    std::ofstream out(fileLocation);
    int usedCells = 0;
    int maxLength = 0;
    int numberOfWords = 0;
    int numberOfListCells = 0;
    LinkedList* maxList = nullptr;
    for (int i = 0; i < maxSize; i++)
    {
        LinkedList *list = hashTable->arrayList[i];
        ListElement *current = list->head;
        int lengthOfList = 0;
        if (current->next != nullptr)
        {
            usedCells++;
        }
        while (current->next != nullptr)
        {

            current = current->next;
            char* word = transformToChar(current->string);
            out << "Word is: \"" << word << "\" counter is: ";
            delete[] word;
            out << current->counter << endl;
            lengthOfList++;
            numberOfWords = numberOfWords + current->counter;
            numberOfListCells++;
        }
        if (lengthOfList > maxLength)
        {
            maxLength = lengthOfList;
            maxList = list;
        }
    }
    out << endl;
    out << "Empty cells of hash table is " << maxSize - usedCells << endl;
    out << "Load factor is " << (double) numberOfListCells / maxSize << endl;
    out << "Number of words is " << numberOfWords << endl;
    out << "Average length of list is "<< (numberOfListCells / usedCells) << endl;
    out << "Max length of list is " << maxLength << endl;
    out << "It's words is: " << endl;
    ListElement *current = maxList->head;
    while (current->next != nullptr)
    {

        current = current->next;
        char* word = transformToChar(current->string);
        out << "Word is: \"" << word << "\" counter is: ";
        delete[] word;
        out << current->counter << endl;
    }
    out.close();

}

HashTab* addElement(HashTab* hashTable, StringATD* string)
{
    int hash = hashFunction(string);
    addList(string, hashTable->arrayList[hash]);
    return hashTable;
}

void deleteHashTable(HashTab* hashTable)
{
    for (int i = 0; i < maxSize; i++)
    {
        deleteLinkedList(hashTable->arrayList[i]);
    }
    delete[] hashTable->arrayList;
    delete hashTable;
}
