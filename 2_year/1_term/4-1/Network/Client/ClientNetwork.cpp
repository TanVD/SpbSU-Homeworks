#include "ClientNetwork.h"
#include "TransmissionCoder.h"

ClientNetwork::ClientNetwork() :
    NetworkGeneral(), serverConnection(new QTcpSocket), blockSize(0)
{
    connect(serverConnection, SIGNAL(readyRead()), this, SLOT(readTextMsg()));
    connect(serverConnection, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(serverConnection, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(disconnected()));
    disconnected();
}

ClientNetwork::~ClientNetwork()
{
    delete serverConnection;
}

void ClientNetwork::sendTextMessage(QString stringToCode)
{
    QByteArray block = TransmissionCoder::codeForTransmission(stringToCode);
    serverConnection->write(block);
}

void ClientNetwork::readTextMsg()
{
    QString newText;
    try
    {
        newText = TransmissionCoder::decodeFromTransmission(serverConnection, blockSize);
        emit newMessage(newText);
    }
    catch (UnreliableTransmission)
    {
        return;
    }
    blockSize = 0;
}

void ClientNetwork::connectToServer(QString ip, quint16 port)
{
    serverConnection->disconnectFromHost();
    blockSize = 0;
    serverConnection->connectToHost(ip, port);
    connect(serverConnection, SIGNAL(connected()), this, SLOT(connected()));
}

void ClientNetwork::connected()
{
   // ui->sendButton->setEnabled(true);
   // ui->connectionLabel->setText("Connected");
}

void ClientNetwork::disconnected()
{
   // ui->sendButton->setEnabled(false);
   // ui->connectionLabel->setText("Disconnected");
}
