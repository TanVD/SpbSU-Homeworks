#include <QCoreApplication>
#include <QtTest/QtTest>
#include "mySharedPtrTests.h"

int main(int argc, char *argv[])
{
    MySharedPtrTests test;
    QTest::qExec(&test);
}
