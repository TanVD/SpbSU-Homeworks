#include <QCoreApplication>
#include <QtTest/QTest>
#include "setTest.h"

int main()
{
    SetTest test;
    QTest::qExec(&test);
}
