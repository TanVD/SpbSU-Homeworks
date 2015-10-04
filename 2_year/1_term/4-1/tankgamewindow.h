#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "FramesUpdater.h"

namespace Ui {
class TankGameWindow;
}

class TankGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TankGameWindow(QWidget *parent = 0);
    ~TankGameWindow();

private:
    Ui::TankGameWindow *ui;
    QGraphicsScene *scene;
    FramesUpdater *updater;

private slots:
    void keyPressed(char button, int msec);
};

