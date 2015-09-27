#pragma once

#include <QMainWindow>
#include <QGraphicsScene>

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

private slots:
    void keyPressed(char button, int msec);
};

