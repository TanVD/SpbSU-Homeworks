#pragma once
#include "listunique.h"
#include "list.h"
#include "addExistedElementException.h"
#include "deleteNonExistedElementException.h"
#include "outofindexes.h"
#include <QtTest/QtTest>
#include <QtCore/QObject>

class TestListUnique : public QObject
{
    Q_OBJECT

public:
    explicit TestListUnique(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        list = new ListUnique();
    }

    void TestListUniqueAddValue()
    {
        list->add(5);
        list->add(7);
        QVERIFY(list->isInList(5));
        QVERIFY(list->isInList(7));
        QVERIFY(!list->isInList(10));
    }

    void TestListUniqueAddIndex()
    {
        list->add(5, 0);
        list->add(7, 0);
        QVERIFY(list->isInList(5));
        QVERIFY(list->isInList(7));
        QVERIFY(!list->isInList(10));
    }

    void TestListUniqueRemoveValue()
    {
        list->add(5);
        list->add(7);
        QVERIFY(list->isInList(5));
        list->removeValue(5);
        QVERIFY(!list->isInList(5));
    }

    void TestListUniqueRemoveValueException()
    {
        list->add(5);
        list->add(7);
        QVERIFY_EXCEPTION_THROWN(list->removeValue(6), DeleteNonExistedElement);
    }

    void TestListUniqueRemoveIndex()
    {
        list->add(5);
        list->add(7);
        QVERIFY(list->isInList(5));
        list->removeIndex(1);
        QVERIFY(!list->isInList(5));
    }

    void TestListUniqueRemoveIndexException()
    {
        list->add(5);
        list->add(7);
        QVERIFY_EXCEPTION_THROWN(list->removeIndex(9), OutOfIndexes);
    }

    void TestListUniqueExceptionAddIndex()
    {
        list->add(5, 0);
        list->add(7, 1);
        QVERIFY_EXCEPTION_THROWN(list->add(5, 1), AddExistedElement);
    }

    void TestAddOutOfIndex()
    {
        QVERIFY_EXCEPTION_THROWN(list->add(0, 3), OutOfIndexes);
    }

    void TestListUniqueExceptionAddValue()
    {
        list->add(5);
        list->add(7);
        QVERIFY_EXCEPTION_THROWN(list->add(5);, AddExistedElement);
    }

    void cleanup()
    {
        delete list;
    }

private:
    ListUnique* list;
};
