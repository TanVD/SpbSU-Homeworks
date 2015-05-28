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
        list3 = new LinkedList;
        list1->add(5);
        list1->add(9);
        list2->add(5);
    }

    void cleanup()
    {
        delete set;
    }

    void testSetAddOneElement()
    {
        set->add(list1);
        QVERIFY(set->isInSet(list1));
    }

    void testSetAddTwoElements()
    {
        set->add(list1);
        set->add(list2);
        QVERIFY(set->isInSet(list1));
        QVERIFY(set->isInSet(list2));
    }

    void testSetAddSeveralElements()
    {
        set->add(list1);
        set->add(list2);
        set->add(list3);
        QVERIFY(set->isInSet(list1));
        QVERIFY(set->isInSet(list2));
        QVERIFY(set->isInSet(list3));
    }

    void testSetRemoveOneElement()
    {
        set->add(list1);
        QVERIFY(set->remove(list1));
    }

    void testSetRemoveTwoElements()
    {
        set->add(list1);
        set->add(list2);
        QVERIFY(set->remove(list2));
        QVERIFY(set->remove(list1));
    }

    void testSetRemoveSeveralElements()
    {
        set->add(list1);
        set->add(list2);
        set->add(list3);
        QVERIFY(set->remove(list2));
        QVERIFY(set->remove(list1));
        QVERIFY(set->remove(list3));
    }

    void testSetRemoveNotExistedElement()
    {
        QVERIFY(!set->remove(list1));
    }

    void testSetCheckRuleOfSet()
    {
        set->add(list1);
        set->add(list2);
        set->add(list3);
        QVERIFY(set->next()->length() == 0);
        QVERIFY(set->next()->length() == 1);
        QVERIFY(set->next()->length() == 2);
    }

private:
    SortedSet* set;
    LinkedList* list1;
    LinkedList* list2;
    LinkedList* list3;
};
