#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include <QtTest/QTest>
#include "parserTest.h"
#include "ariphTree.h"
#include "parserOfEquation.h"

class ParserTest : public QObject
{
    Q_OBJECT
public:
    ParserTest(QObject *parent = 0)
        : QObject(parent)
    {
    }
private slots:
    void init()
    {
        tree = new AriphTree('-');
    }

    void cleanup()
    {
        delete tree;
    }

    void ariphTreeCreatingTest()
    {
        tree->createLeftElement('+');
        tree->moveToLeftChild();
        tree->createLeftElement('1');
        tree->createRightElement('2');
        tree->up();
        tree->createRightElement('4');
        QString expected = "1+2-4";
        QCOMPARE(expected, tree->printTree());
    }

    void ariphTreeFreeTest()
    {
        tree->createLeftElement('1');
        QVERIFY(!tree->isLeftFree());
        QVERIFY(tree->isRightFree());
    }

    void moveTreeTest()
    {
        tree->createLeftElement('+');
        tree->moveToLeftChild();
        QCOMPARE('+', tree->valueCurrent().toLatin1());
        tree->createLeftElement('1');
        tree->createRightElement('2');
        tree->up();
        QCOMPARE('-', tree->valueCurrent().toLatin1());
        tree->createRightElement('4');
        tree->moveToRightChild();
        QCOMPARE('4', tree->valueCurrent().toLatin1());
    }

    void parseTreeTest()
    {
        QFile* file = new QFile("bobuk");
        tree = ParserOfEquation::parseFile(file);
        QString expected = "1+2-4";
        QCOMPARE(expected, tree->printTree());
        delete file;
    }

    void calculateTree()
    {
        QFile* file = new QFile("bobuk");
        tree = ParserOfEquation::parseFile(file);
        QCOMPARE(-1, tree->calculateTree());
        delete file;
    }
private:
    AriphTree* tree;
};
