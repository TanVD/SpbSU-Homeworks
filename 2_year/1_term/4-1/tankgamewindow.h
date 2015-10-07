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
#include "QRadioButton"
#include "QLineEdit"
#include "QVBoxLayout"
#include "QLabel"

#include "QPushButton"

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
    bool isServer;

private slots:
    void getGround(QString ground);
    void sendGround();
    void buttonServerPushed(bool value);
    void buttonClientPushed(bool value);
    void startButtonPushed(bool value);
};

