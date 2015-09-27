#include "tankgamewindow.h"
#include "ui_tankgamewindow.h"
#include "KeyManager.h"
#include "Avatar.h"
#include <QMessageBox>

TankGameWindow::TankGameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TankGameWindow)
{
    ui->setupUi(this);
    KeyManager *keyManager = new KeyManager(this);//singltone
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->installEventFilter(keyManager);
    Avatar *tankFirst = new Avatar(scene, keyManager, QPoint(0, 0));
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
