#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include <QtTest/QTest>
#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT
public:
    SetTest(QObject *parent = 0)
        : QObject(parent)
    {
    }
private slots:
    void addExistsTest()
    {
        QVERIFY(set->isExists(5));
        QVERIFY(!set->isExists(7));
        QVERIFY(set->isExists(11));
        QVERIFY(set->isExists(11));
        QVERIFY(set->length() == 3);
    }

    void removeTest()
    {
        QVERIFY(!set->remove(13));
        set->remove(9);
        QVERIFY(set->remove(5));
        QVERIFY(set->isExists(11));
        QVERIFY(!set->isExists(5));
        QVERIFY(!set->isExists(9));
    }

    void interSectTest()
    {
        Set<int> *setSecond = new Set<int>();
        setSecond->add(5);
        setSecond->add(11);
        setSecond->add(1);
        Set<int> *result = set->intersectSets(setSecond);
        QVERIFY(result->isExists(5));
        QVERIFY(result->isExists(11));
        QVERIFY(!result->isExists(1));
        QVERIFY(!result->isExists(9));
        QVERIFY(result->length() == 2);
        delete setSecond;
        delete result;
    }

    void associateTest()
    {
        Set<int> *setSecond = new Set<int>();
        setSecond->add(5);
        setSecond->add(11);
        setSecond->add(1);
        Set<int> *result = set->associationSets(setSecond);
        QVERIFY(result->isExists(5));
        QVERIFY(result->isExists(11));
        QVERIFY(result->isExists(1));
        QVERIFY(result->isExists(9));
        QVERIFY(!result->isExists(13));
        QVERIFY(result->length() == 4);
        delete setSecond;
        delete result;
    }

    void init()
    {
        set = new Set<int>();
        set->add(5);
        set->add(9);
        set->add(11);
        set->add(5);
    }

    void cleanup()
    {
        delete set;
    }

private:
    Set<int>* set;
};
