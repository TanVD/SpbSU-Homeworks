#include "myserver.h"
#include "ui_myserver.h"
#include "transmissionCoder.h"

MyServer::MyServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyServer),
    blockSize(0)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    tcpServer->listen();
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sessionOpened()));
    connect(ui->sendButton, SIGNAL(clicked(bool)), this, SLOT(sendTextMessage()));

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    ui->IpLabel->setText(ipAddress);
    ui->portLabel->setText(QString::number(tcpServer->serverPort()));
}

MyServer::~MyServer()
{
    delete ui;
}

void MyServer::sessionOpened()
{
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readTextMsg()));
}

void MyServer::sendTextMessage()
{
    QString stringToCode = ui->sendText->toPlainText();
    QByteArray block = TransmissionCoder::codeForTransmission(stringToCode);
    clientConnection->write(block);
    QString addingInf;
    if (ui->historyText->toPlainText() == "")
    {
        addingInf = "Я: ";
    }
    else
    {
         addingInf = "\nЯ: ";
    }
    ui->historyText->setText(ui->historyText->toPlainText() + addingInf + ui->sendText->toPlainText());
    ui->sendText->clear();

}

void MyServer::readTextMsg()
{
    QString newText;
    try
    {
        newText = TransmissionCoder::decodeFromTransmission(clientConnection, blockSize);
    }
    catch (UnreliableTransmission)
    {
        return;
    }

    QString addingInf;
    if (ui->historyText->toPlainText() == "")
    {
        addingInf = "Собеседник: ";
    }
    else
    {
         addingInf = "\nСобеседник: ";
    }
    ui->historyText->setText(ui->historyText->toPlainText() + addingInf + newText);
    blockSize = 0;
}
