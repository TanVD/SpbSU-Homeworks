#include "hashTable.h"

HashTable::HashTable(int module) : module(module), array(new LinkedList*[module]),
    hashDelegate(&HashTable::hashFunction), largestCollision(0), loadFactor(0)
{
    for (int i = 0; i < module; i++)
    {
        array[i] = new LinkedList();
    }
}

void HashTable::deleteListsArray(LinkedList** array, int size)
{
    for (int i  = 0; i < size; i++)
    {
        delete array[i];
    }
    delete[] array;
}

HashTable::~HashTable()
{
    deleteListsArray(array, module);
}

int HashTable::hashFunction(int value, int module)
{
    int factor = 101;
    int result = 0;
    while (value != 0)
    {
        result = (result * factor + value % 10) % module;
        value = value / 10;
    }
    return result;
}

void HashTable::addValue(int value)
{
    int index = hashDelegate(value, module);
    if (array[index]->isEmpty())
        loadFactor++;
    array[index]->add(value);
    if (array[index]->length() > largestCollision)
        largestCollision = array[index]->length();
}

bool HashTable::removeValue(int value)
{
    int index = hashDelegate(value, module);
    bool result = array[index]->remove(value);
    if (result)
    {
        if (array[index]->isEmpty())
            loadFactor--;
        largestCollision = 0;
        for (int i = 0; i < this->module; i++)
        {
            if (array[i]->length() > largestCollision)
                largestCollision = array[i]->length();
        }
    }
    return result;
}

bool HashTable::findValue(int value)
{
    return array[hashDelegate(value, module)]->isExists(value);
}

void HashTable::changeHashFunction(std::function<int(int, int)>)
{
    this->hashDelegate = hashDelegate;
    LinkedList** newHashTable = new LinkedList*[module];
    for (int i = 0; i < module; i++)
    {
        newHashTable[i] = new LinkedList();
    }
    LinkedList** oldHashTable = array;
    array = newHashTable;
    loadFactor = 0;
    largestCollision = 0;
    for (int i = 0; i < this->module; i++)
    {
        while (!oldHashTable[i]->isEmpty())
        {
            int value = oldHashTable[i]->pop();
            this->addValue(value);
        }
    }
    deleteListsArray(oldHashTable, this->module);
}

void HashTable::changeModule(int module)
{
    int oldModule = this->module;
    this->module = module;
    LinkedList** newHashTable = new LinkedList*[module];
    for (int i = 0; i < module; i++)
    {
        newHashTable[i] = new LinkedList();
    }
    LinkedList** oldHashTable = array;
    array = newHashTable;
    loadFactor = 0;
    largestCollision = 0;
    for (int i = 0; i < oldModule; i++)
    {
        while (!oldHashTable[i]->isEmpty())
        {
            int value = oldHashTable[i]->pop();
            this->addValue(value);
        }
    }
    deleteListsArray(oldHashTable, oldModule);
}

int HashTable::getModule()
{
    return module;
}

int HashTable::getLoadFactor()
{
    return loadFactor;
}

int HashTable::getLargestCollision()
{
    return largestCollision;
}
