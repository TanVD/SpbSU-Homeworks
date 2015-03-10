#include "calculatorUberUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorUberUI w;
    w.show();

    return a.exec();
}
