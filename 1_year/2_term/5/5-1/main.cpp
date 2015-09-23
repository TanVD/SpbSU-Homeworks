#include "hashtableui.h"
#include <QApplication>
#include "QtTest"
#include "hashtabletest.h"

int main(int argc, char *argv[])
{
    HashTableTest test;
    QTest::qExec(&test);
    QApplication a(argc, argv);
    HashTableUI w;
    w.show();
    return a.exec();
}
