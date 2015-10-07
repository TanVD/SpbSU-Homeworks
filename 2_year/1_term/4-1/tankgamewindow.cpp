#include "tankgamewindow.h"
#include "ui_tankgamewindow.h"


TankGameWindow::TankGameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TankGameWindow)
{
    bool isServer = true;
    scene = new QGraphicsScene();
    updater = new FramesUpdater(60, scene);

    if (isServer)
    {
        ServerNetwork *server = new ServerNetwork(this);//port 5555
        network = server;
        ground = new GroundImage(updater);
        connect(server, &ServerNetwork::sessionOpenedSig, this, &TankGameWindow::sendGround);
        loop.exec();
    }
    else
    {
        ClientNetwork *client = new ClientNetwork(this);
        network = client;
        client->connectToServer("localhost", 5555);
        connect(client, &ClientNetwork::newMessage, this, &TankGameWindow::getGround);
        loop.exec();

    }

    ui->setupUi(this);
    KeyControl *keyControl = new KeyControl("ADWSQE 1", this);
    NetworkControl *networkControl = new NetworkControl(network);

    QList<KeyControl *> list;
    list << keyControl;

    KeyManager *manager = new KeyManager(list, updater, ui->graphicsView);


    ui->graphicsView->setScene(scene);
    ui->graphicsView->installEventFilter(manager);

    Avatar *tankFirst;
    Avatar *tankSecond;
    scene->addItem(ground);
    if (isServer)
    {
        tankFirst = new Avatar(scene, ground, keyControl, QPoint(0, 0), updater);
        tankSecond = new Avatar(scene,ground,  networkControl, QPoint(20, 0), updater);
    }
    else
    {
        tankFirst = new Avatar(scene, ground, keyControl, QPoint(20, 0), updater);
        tankSecond = new Avatar(scene,ground,  networkControl, QPoint(0, 0), updater);
    }
    network->setControl(keyControl, tankFirst, updater);


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

void TankGameWindow::getGround(QString ground)
{
    this->ground = new GroundImage(updater, ground);
    ClientNetwork *client = dynamic_cast<ClientNetwork *> (network);
    disconnect(client, &ClientNetwork::newMessage, this, &TankGameWindow::getGround);
    loop.exit();
}

void TankGameWindow::sendGround()
{
    network->sendTextMessage(ground->serializeToString());
    loop.exit();
}
