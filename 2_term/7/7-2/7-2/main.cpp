#include <QCoreApplication>
#include <QTest>
#include "testlistunique.h"

int main(int argc, char *argv[])
{
    TestListUnique test;
    QTest::qExec(&test);
    QCoreApplication a(argc, argv);

    return a.exec();
}
