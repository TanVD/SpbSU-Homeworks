#include "testlist.h"
#include <QtTest/QtTest>

int main()
{
    ListTest test;
    QTest::qExec(&test);
    return 0;
}

