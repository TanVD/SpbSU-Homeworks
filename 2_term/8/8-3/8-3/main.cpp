#include "ticTacToeUI.h"
#include <QApplication>
#include <QTest>
#include <tictactoetest.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    TicTacToeTest test;
    QTest::qExec(&test);
    TicTacToeUI w;
    w.show();

    return a.exec();
}
