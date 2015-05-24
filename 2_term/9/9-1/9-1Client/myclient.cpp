#include "myclient.h"
#include "ui_myclient.h"
#include "transmissionCoder.h"

myclient::myclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myclient),
    blockSize(0)
{
    ui->setupUi(this);
    serverConnection = new QTcpSocket;
    connect(ui->sendButton, SIGNAL(clicked(bool)), this, SLOT(sendTextMessage()));
    connect(serverConnection, SIGNAL(readyRead()), this, SLOT(readTextMsg()));
    connect(ui->connectButton, SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
    connect(serverConnection, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(serverConnection, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(disconnected()));
    disconnected();
}

myclient::~myclient()
{
    delete serverConnection;
    delete ui;
}

void myclient::sendTextMessage()
{
    QString stringToCode = ui->sendText->toPlainText();
    QByteArray block = TransmissionCoder::codeForTransmission(stringToCode);
    serverConnection->write(block);
    ui->historyText->append("Я: " + ui->sendText->toPlainText());
    ui->sendText->clear();
}

void myclient::readTextMsg()
{
    QString newText;
    try
    {
        newText = TransmissionCoder::decodeFromTransmission(serverConnection, blockSize);
    }
    catch (UnreliableTransmission)
    {
        return;
    }
    ui->historyText->append("Собеседник: " + newText);
    blockSize = 0;
}

void myclient::connectToServer()
{
    serverConnection->disconnectFromHost();
    blockSize = 0;
    serverConnection->connectToHost(ui->ipText->text(), ui->portText->text().toInt());
    connect(serverConnection, SIGNAL(connected()), this, SLOT(connected()));
}

void myclient::connected()
{
    ui->sendButton->setEnabled(true);
    ui->connectionLabel->setText("Connected");
}

void myclient::disconnected()
{
    ui->sendButton->setEnabled(false);
    ui->connectionLabel->setText("Disconnected");
}
