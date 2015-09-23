#pragma once
#include <QtCore/QObject>
#include <QtTest>
#include "hashTable.h"
#include <functional>

class HashTableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTest(QObject *parent = 0) : QObject(parent) {}
    static int hashFunction(int value, int module)
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

private slots:
   void init()
   {
       table = new HashTable(100);
   }

   void testPushHashTable()
   {
       table->addValue(5);
       table->addValue(7);
       QVERIFY(table->findValue(5));
       QVERIFY(table->findValue(7));
       QVERIFY(!table->findValue(2));
       table->removeValue(5);
       table->removeValue(7);
   }

   void testRemoveHashTable()
   {
       table->addValue(5);
       QVERIFY(!table->removeValue(2));
       QVERIFY(table->removeValue(5));
       QVERIFY(!table->findValue(5));
   }

   void testChangeModuleHashTable()
   {
       table->addValue(5);
       table->addValue(9);
       table->addValue(5);
       QVERIFY(table->getModule() == 100);
       QVERIFY(table->getLoadFactor() == 2);
       QVERIFY(table->getLargestCollision() == 2);
       table->changeModule(120);
       QVERIFY(table->getModule() == 120);
       QVERIFY(table->findValue(5));
       QVERIFY(table->findValue(9));
       QVERIFY(!table->findValue(7));
       QVERIFY(table->getLoadFactor() == 2);
       QVERIFY(table->getLargestCollision() == 2);
       table->removeValue(5);
       table->removeValue(9);
       table->removeValue(5);
       table->changeModule(100);
   }

   void testChangeHashFunction()
   {
       hashDel = &hashFunction;
       table->changeHashFunction(hashDel);
       testRemoveHashTable();
       testPushHashTable();
       testChangeModuleHashTable();
       testStatsHashTable();
   }

   void testStatsHashTable()
   {
       table->addValue(5);
       QVERIFY(table->getLoadFactor() == 1);
       QVERIFY(table->getLargestCollision() == 1);
       QVERIFY(table->getModule() == 100);
       table->addValue(5);
       table->addValue(7);
       QVERIFY(table->getLoadFactor() == 2);
       QVERIFY(table->getLargestCollision() == 2);
   }

   void cleanup()
   {
       delete table;
   }

private:
   HashTable *table;
   std::function<int(int, int)> hashDel;
};
