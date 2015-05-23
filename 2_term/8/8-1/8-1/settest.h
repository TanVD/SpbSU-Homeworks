#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT
public:
    explicit SetTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void init()
    {
        tree = new Set;
    }

    void cleanup()
    {
        delete tree;
    }

    void addOneElement()
    {
        tree->addNodeInSet(6);
        QVERIFY(tree->isExistsInSet(6));
    }

    void addTwoElements()
    {
        tree->addNodeInSet(6);
        tree->addNodeInSet(5);
        QVERIFY(tree->isExistsInSet(6));
        QVERIFY(tree->isExistsInSet(5));
    }

    void addSeveralElements()
    {
        tree->addNodeInSet(6);
        tree->addNodeInSet(5);
        tree->addNodeInSet(7);
        tree->addNodeInSet(22);
        QVERIFY(tree->isExistsInSet(6));
        QVERIFY(tree->isExistsInSet(5));
        QVERIFY(tree->isExistsInSet(7));
        QVERIFY(tree->isExistsInSet(22));
    }

    void checkIsExistsNonExisted()
    {
        tree->addNodeInSet(3);
        QVERIFY(!tree->isExistsInSet(5));
    }

    void deleteOneElement()
    {
        tree->addNodeInSet(5);
        QVERIFY(tree->deleteNodeInSet(5));
        QVERIFY(!tree->isExistsInSet(5));
    }

    void deleteTwoElement()
    {
        tree->addNodeInSet(5);
        tree->addNodeInSet(59);
        QVERIFY(tree->deleteNodeInSet(5));
        QVERIFY(!tree->isExistsInSet(5));
        QVERIFY(tree->deleteNodeInSet(59));
        QVERIFY(!tree->isExistsInSet(59));
    }

    void deleteTwoEqualElements()
    {
        tree->addNodeInSet(5);
        tree->addNodeInSet(5);
        QVERIFY(tree->deleteNodeInSet(5));
        QVERIFY(tree->isExistsInSet(5));
        QVERIFY(tree->deleteNodeInSet(5));
        QVERIFY(!tree->isExistsInSet(5));
    }

    void deleteSeveralElement()
    {
        tree->addNodeInSet(5);
        tree->addNodeInSet(59);
        tree->addNodeInSet(-5);
        tree->addNodeInSet(3);
        QVERIFY(tree->deleteNodeInSet(5));
        QVERIFY(!tree->isExistsInSet(5));
        QVERIFY(tree->deleteNodeInSet(59));
        QVERIFY(!tree->isExistsInSet(59));
        QVERIFY(tree->deleteNodeInSet(-5));
        QVERIFY(!tree->isExistsInSet(-5));
        QVERIFY(tree->deleteNodeInSet(3));
        QVERIFY(!tree->isExistsInSet(3));
    }

    void addSeveralEqualElements()
    {
        tree->addNodeInSet(5);
        tree->addNodeInSet(5);
        QVERIFY(tree->isExistsInSet(5));
        tree->deleteNodeInSet(5);
        tree->deleteNodeInSet(5);
        QVERIFY(!tree->isExistsInSet(5));
    }

    void printInorderElements()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        QString answer = "3 7 8 ";
        QCOMPARE(tree->printInorderSet(), answer);
    }

    void printReverseInorderElements()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        QString answer = "8 7 3 ";
        QCOMPARE(tree->printReverseInorderSet(), answer);
    }

    void printStructElements()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        QString answer = "7 (3 (NULL NULL )8 (NULL NULL ))";
        QCOMPARE(tree->printStructOfSet(), answer);
    }

private:
    Set* tree;
};
