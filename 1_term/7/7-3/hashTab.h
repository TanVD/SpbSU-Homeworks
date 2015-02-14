#pragma once
#include <stringATD.h>

struct HashTab;

HashTab* createHashTable();

HashTab* addElement(HashTab* hashTable, StringATD* string);

HashTab* deleteElement(HashTab* hashTable, int hash, StringATD* string);

void printHashTable(HashTab* hashTable, char* fileLocation);

void deleteHashTable(HashTab* hashTable);
