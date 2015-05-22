#include <QCoreApplication>
#include <QTest>
#include "settest.h"

int main(int argc, char *argv[])
{
    SetTest test;
    QTest::qExec(&test);
    QCoreApplication a(argc, argv);

    return a.exec();
}
