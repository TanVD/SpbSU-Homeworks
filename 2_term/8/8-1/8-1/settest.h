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
        tree->addNode(6);
        QVERIFY(tree->isExists(6));
    }

    void addTwoElements()
    {
        tree->addNode(6);
        tree->addNode(5);
        QVERIFY(tree->isExists(6));
        QVERIFY(tree->isExists(5));
    }

    void addSeveralElements()
    {
        tree->addNode(6);
        tree->addNode(5);
        tree->addNode(7);
        tree->addNode(22);
        QVERIFY(tree->isExists(6));
        QVERIFY(tree->isExists(5));
        QVERIFY(tree->isExists(7));
        QVERIFY(tree->isExists(22));
    }

    void checkIsExistsNonExisted()
    {
        tree->addNode(3);
        QVERIFY(!tree->isExists(5));
    }

    void deleteOneElement()
    {
        tree->addNode(5);
        QVERIFY(tree->deleteNode(5));
        QVERIFY(!tree->isExists(5));
    }

    void deleteTwoElement()
    {
        tree->addNode(5);
        tree->addNode(59);
        QVERIFY(tree->deleteNode(5));
        QVERIFY(!tree->isExists(5));
        QVERIFY(tree->deleteNode(59));
        QVERIFY(!tree->isExists(59));
    }

    void deleteTwoEqualElements()
    {
        tree->addNode(5);
        tree->addNode(5);
        QVERIFY(tree->deleteNode(5));
        QVERIFY(tree->isExists(5));
        QVERIFY(tree->deleteNode(5));
        QVERIFY(!tree->isExists(5));
    }

    void deleteSeveralElement()
    {
        tree->addNode(5);
        tree->addNode(59);
        tree->addNode(-5);
        tree->addNode(3);
        QVERIFY(tree->deleteNode(5));
        QVERIFY(!tree->isExists(5));
        QVERIFY(tree->deleteNode(59));
        QVERIFY(!tree->isExists(59));
        QVERIFY(tree->deleteNode(-5));
        QVERIFY(!tree->isExists(-5));
        QVERIFY(tree->deleteNode(3));
        QVERIFY(!tree->isExists(3));
    }

    void addSeveralEqualElements()
    {
        tree->addNode(5);
        tree->addNode(5);
        QVERIFY(tree->isExists(5));
        tree->deleteNode(5);
        tree->deleteNode(5);
        QVERIFY(!tree->isExists(5));
    }

    void printInorderElements()
    {
        tree->addNode(8);
        tree->addNode(3);
        tree->addNode(7);
        QString answer = "3 7 8 ";
        QCOMPARE(tree->printInorderSet(), answer);
    }

    void printReverseInorderElements()
    {
        tree->addNode(8);
        tree->addNode(3);
        tree->addNode(7);
        QString answer = "8 7 3 ";
        QCOMPARE(tree->printReverseInorderSet(), answer);
    }

    void printStructElements()
    {
        tree->addNode(8);
        tree->addNode(3);
        tree->addNode(7);
        QString answer = "7 (3 (NULL NULL )8 (NULL NULL ))";
        QCOMPARE(tree->printStructOfSet(), answer);
    }

private:
    Set* tree;
};
