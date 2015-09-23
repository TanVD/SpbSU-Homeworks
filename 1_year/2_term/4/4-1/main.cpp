#include "progressSlider.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProgressSlider w;
    w.show();

    return a.exec();
}
