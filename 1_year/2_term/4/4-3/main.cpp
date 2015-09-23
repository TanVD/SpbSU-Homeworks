#include "calculatorUberUI.h"
#include <QApplication>
#include <QTest>
#include "testCalc.h"
#include "testStack.h"

int main(int argc, char *argv[])
{
    StackTest test1;
    QTest::qExec(&test1);
    CalcTest test2;
    QTest::qExec(&test2);
    QApplication a(argc, argv);
    CalculatorUberUI w;
    w.show();
    return a.exec();
}
