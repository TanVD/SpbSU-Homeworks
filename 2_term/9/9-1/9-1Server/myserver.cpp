#include "myserver.h"
#include "ui_myserver.h"
#include "transmissionCoder.h"

MyServer::MyServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyServer),
    blockSize(0),
    clientConnection(nullptr)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    tcpServer->listen();
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sessionOpened()));
    connect(ui->sendButton, SIGNAL(clicked(bool)), this, SLOT(sendTextMessage()));
    connect(ui->ipComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeIpAddress(int)));

    ipAddressesList = QNetworkInterface::allAddresses();
    QStringList ipList;
    for (int i = 0; i < ipAddressesList.size(); i++)
    {
        ipList.append(ipAddressesList[i].toString());
    }
    ui->ipComboBox->addItems(ipList);
    ui->portLabel->setText(QString::number(tcpServer->serverPort()));
    ui->sendButton->setEnabled(false);
}

MyServer::~MyServer()
{
    delete tcpServer;
    if (clientConnection != nullptr)
        delete clientConnection;
    delete ui;
}

void MyServer::sessionOpened()
{
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readTextMsg()));
    ui->sendButton->setEnabled(true);
}

void MyServer::sendTextMessage()
{
    QString stringToCode = ui->sendText->toPlainText();
    QByteArray block = TransmissionCoder::codeForTransmission(stringToCode);
    clientConnection->write(block);
    ui->historyText->append("Я: " + ui->sendText->toPlainText());
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
    ui->historyText->append("Собеседник: " + newText);
    blockSize = 0;
}

void MyServer::changeIpAddress(int index)
{
    if (clientConnection != nullptr)
    {
        clientConnection->disconnectFromHost();
        delete clientConnection;
        clientConnection = nullptr;
    }
    tcpServer->close();
    tcpServer->listen(ipAddressesList[index]);
    ui->portLabel->setText(QString::number(tcpServer->serverPort()));
    ui->sendButton->setEnabled(false);
}
