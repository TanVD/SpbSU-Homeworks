#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "BST.h"
#include "iteratorinterface.h"

class SetTest : public QObject
{
    Q_OBJECT
public:
    explicit SetTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void init()
    {
        tree = new Tree;
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

    void iterationThroughTree()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        IteratorInterface<int>* iter = tree->getEnumerator();
        QCOMPARE(iter->next(), 3);
        QCOMPARE(iter->next(), 7);
        QCOMPARE(iter->next(), 8);
    }

    void enumaretorGetLast()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        IteratorInterface<int>* iter = tree->getEnumerator();
        iter->next();
        iter->next();
        iter->next();
        QVERIFY(iter->isEmpty());
    }

    void enumaratorReset()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        IteratorInterface<int>* iter = tree->getEnumerator();
        iter->next();
        iter->next();
        iter->next();
        iter->reset();
        QCOMPARE(iter->next(), 3);
        QCOMPARE(iter->next(), 7);
        QCOMPARE(iter->next(), 8);
    }

    void enumaretorRemoveOne()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        IteratorInterface<int>* iter = tree->getEnumerator();
        iter->next();
        iter->next();
        iter->remove();
        iter->reset();
        QCOMPARE(iter->next(), 3);
        QCOMPARE(iter->next(), 7);
        QVERIFY(iter->isEmpty());
    }

    void enumeratorRemoveOneAndGoToSecond()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        IteratorInterface<int>* iter = tree->getEnumerator();
        iter->next();
        iter->remove();
        QCOMPARE(iter->next(), 8);
        QVERIFY(iter->isEmpty());
    }

    void enumaretorRemoveTwo()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        IteratorInterface<int>* iter = tree->getEnumerator();
        iter->remove();
        iter->reset();
        iter->remove();
        QCOMPARE(iter->next(), 8);
        QVERIFY(iter->isEmpty());
    }

    void printInorderElements()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        QString answer = "3 7 8 ";
        QCOMPARE(tree->printInorderSet(), answer);
    }

    void printInorderElementsByEnumerator()
    {
        tree->addNodeInSet(8);
        tree->addNodeInSet(3);
        tree->addNodeInSet(7);
        IteratorInterface<int>* iter = tree->getEnumerator();
        QString variant;
        variant += QString::number(iter->next()) + " ";
        variant += QString::number(iter->next()) + " ";
        variant += QString::number(iter->next()) + " ";
        QString answer = "3 7 8 ";
        QCOMPARE(variant, answer);
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
    Tree* tree;
};
