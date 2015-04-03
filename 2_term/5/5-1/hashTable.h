#pragma once
#include "linkedList.h"
#include <functional>
/**
 * @brief The HashTable class Class implementing HashTable
 */
class HashTable
{
public:
    HashTable(int module);
    ~HashTable();

    /**
     * @brief addValue Adds value in HashTable
     * @param value Value to add
     */
    void addValue(int value);

    /**
     * @brief removeValue Removes value from HashTable
     * @param value Value to remove
     * @return True if value was succesfully removed, false if not
     */
    bool removeValue(int value);

    /**
     * @brief findValue Find value in HashTable
     * @param value Value to find
     * @return True if value exists in HashTable, false if not
     */
    bool findValue(int value);

    /**
     * @brief changeHashFunction Changes hash function with implemented in client code.
     */
    void changeHashFunction(std::function<int(int, int)> hashDelegate);

    /**
     * @brief changeModule Changes module in HashTable.
     * @param module New module of HashTable
     */
    void changeModule(int module);

    /**
     * @brief getModule Returns module of HashTable. Used for stats.
     * @return Module of HashTable
     */
    int getModule();

    /**
     * @brief getLoadFactor Returns load factor. Used for stats.
     * @return Load factor of HashTable;
     */
    int getLoadFactor();

    /**
     * @brief getLargestCollision Returns length of largest collision.
     * @return Length of largest collision.
     */
    int getLargestCollision();

private:
    int loadFactor;
    int largestCollision;
    LinkedList** array;
    int module;
    int hashFunction(int value);
    std::function<int(int, int)> hashDelegate;
    void deleteArray(LinkedList **array, int size);
};

