#pragma once
#include <QtTest/QtTest>
#include <QtCore/QObject>
#include "calculator.h"
class CalcTest : public QObject
{
   Q_OBJECT
public:
   explicit CalcTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        calc = new Calculator();
    }

    void testCalc()
    {
        calc->calculate("1+1", 3);
        QVERIFY(calc->returnResult() == 2);
        QVERIFY(calc->isResultValid());
        calc->calculate("1/0", 3);
        QVERIFY(!calc->isResultValid());
    }

    void cleanup()
    {
        delete calc;
    }

private:
    Calculator *calc;
};
