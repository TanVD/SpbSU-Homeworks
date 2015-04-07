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
        list1 = new LinkedList;
        list2 = new LinkedList;
        list1->add(5);
        list1->add(9);
        list2->add(5);
        set->add(list1);
        set->add(list2);
    }

    void testAddRemoveSet()
    {
        QVERIFY(set->remove(list2));
        QVERIFY(set->remove(list1));
        QVERIFY(!set->remove(list1));
    }

    void testSortRuleOfSet()
    {
        QVERIFY(set->next()->length() == 1);
        QVERIFY(set->next()->length() == 2);
    }

    void cleanup()
    {
        delete set;
    }

private:
    SortedSet* set;
    LinkedList* list1;
    LinkedList* list2;
};
