#include <QCoreApplication>
#include <nVector.h>
#include "nvectortest.h"
#include <QTest>

int main(int argc, char *argv[])
{
    NVectorTest test;
    QTest::qExec(&test);
}
