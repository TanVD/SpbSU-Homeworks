#include "myclient.h"
#include <QApplication>
#include <QTest>
#include <tictactoetest.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    myclient w;
    w.show();

    return a.exec();
}
