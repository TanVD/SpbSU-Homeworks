#include "ticTacToeUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TicTacToeUI w;
    w.show();

    return a.exec();
}
