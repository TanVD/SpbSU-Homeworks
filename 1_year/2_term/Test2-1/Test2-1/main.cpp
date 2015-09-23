#include <QCoreApplication>
#include <QTest>
#include "treetest.h"

int main(int argc, char *argv[])
{
    SetTest test;
    QTest::qExec(&test);
    QCoreApplication a(argc, argv);

    return a.exec();
}
