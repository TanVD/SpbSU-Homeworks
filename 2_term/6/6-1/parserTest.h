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
        tree->CreateLeftElement('+');
        tree->DownLeft();
        tree->CreateLeftElement('1');
        tree->CreateRightElement('2');
        tree->Up();
        tree->CreateRightElement('4');
        QString expected = "1+2-4";
        QCOMPARE(expected, tree->PrintTree());
    }

    void ariphTreeFreeTest()
    {
        tree->CreateLeftElement('1');
        QVERIFY(!tree->IsLeftFree());
        QVERIFY(tree->IsRightFree());
    }

    void moveTreeTest()
    {
        tree->CreateLeftElement('+');
        tree->DownLeft();
        QCOMPARE('+', tree->ValueCurrent().toLatin1());
        tree->CreateLeftElement('1');
        tree->CreateRightElement('2');
        tree->Up();
        QCOMPARE('-', tree->ValueCurrent().toLatin1());
        tree->CreateRightElement('4');
        tree->DownRight();
        QCOMPARE('4', tree->ValueCurrent().toLatin1());
    }

    void parseTreeTest()
    {
        QFile* file = new QFile("bobuk");
        tree = ParserOfEquation::ParseFile(file);
        QString expected = "1+2-4";
        QCOMPARE(expected, tree->PrintTree());
        delete file;
    }

    void calculateTree()
    {
        QFile* file = new QFile("bobuk");
        tree = ParserOfEquation::ParseFile(file);
        QCOMPARE(-1, tree->CalculateTree());
        delete file;
    }
private:
    AriphTree* tree;
};
