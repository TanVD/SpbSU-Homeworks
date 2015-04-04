#pragma once
#include "sortedSet.h"

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedList.h"

class SortedSetTest : public QObject
{
   Q_OBJECT
public:
   explicit SortedSetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        set = new SortedSet;
    }

   void testEmptyStack()
   {
       LinkedList* list1 = new LinkedList;
       list1->add(5);
       list1->add(9);
       LinkedList* list2 = new LinkedList;
       list2->add(5);
       set->add(list1);
       set->add(list2);
       QVERIFY(set->remove(list2));
       QVERIFY(set->remove(list1));
       QVERIFY(!set->remove(list1));
   }
private:
   SortedSet* set;

};
