#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "FramesUpdater.h"
#include "QEventLoop"
#include "KeyControl.h"
#include "KeyManager.h"
#include "Avatar.h"
#include "GameRules.h"
#include <QMessageBox>
#include "GroundImage.h"
#include "networkinterface.h"
#include "NetworkControl.h"
#include "ServerNetwork.h"
#include "ClientNetwork.h"

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
    QEventLoop loop;
    GroundImage *ground;
    NetworkGeneral *network;

private slots:
    void keyPressed(char button, int msec);
    void getGround(QString ground);
    void sendGround();

};

