#include <QCoreApplication>
#include <QtTest/QTest>
#include "setTest.h"

int main(int argc, char *argv[])
{
    SetTest test;
    QTest::qExec(&test);
}
