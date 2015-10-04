#include "tankgamewindow.h"
#include "ui_tankgamewindow.h"
#include "KeyControl.h"
#include "KeyManager.h"
#include "Avatar.h"
#include "GameRules.h"
#include <QMessageBox>
#include "GroundImage.h"

TankGameWindow::TankGameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TankGameWindow)
{
    scene = new QGraphicsScene();
    updater = new FramesUpdater(60, scene);

    ui->setupUi(this);
    KeyControl *keyManagerFirst = new KeyControl("ADWSQE ", this);
    KeyControl *keyManagerSecond = new KeyControl("JLIKUO'", this);

    QList<KeyControl *> list;
    list << keyManagerFirst << keyManagerSecond;
    KeyManager *manager = new KeyManager(list, updater, ui->graphicsView);


    ui->graphicsView->setScene(scene);
    ui->graphicsView->installEventFilter(manager);

    GroundImage *ground = new GroundImage(updater);

    scene->addItem(ground);

    Avatar *tankFirst = new Avatar(scene, ground, keyManagerFirst, QPoint(0, 0), updater);
    Avatar *tankSecond = new Avatar(scene,ground,  keyManagerSecond, QPoint(20, 0), updater);



    GameRules *overseer = new GameRules(scene, updater, this);
    connect(tankFirst, &Avatar::exploded, overseer, &GameRules::tankExploded);
    connect(tankSecond, &Avatar::exploded, overseer, &GameRules::tankExploded);

}

TankGameWindow::~TankGameWindow()
{
    delete ui;
}

void TankGameWindow::keyPressed(char button, int msec)
{
    QMessageBox msg(this);
    msg.setDetailedText(QString(button) + " was pressed " + QString::number(msec));
    msg.exec();
}
