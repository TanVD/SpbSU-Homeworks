#include "calculatorSimpleUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorSimpleUI w;
    w.show();

    return a.exec();
}
