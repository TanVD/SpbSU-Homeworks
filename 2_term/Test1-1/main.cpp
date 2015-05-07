#include <QCoreApplication>
#include "queueTest.h"
#include <QtTest/QTest>

int main()
{
    QueueTest test;
    QTest::qExec(&test);
}
