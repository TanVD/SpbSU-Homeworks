#include "ServerNetwork.h"
#include "TransmissionCoder.h"

ServerNetwork::ServerNetwork() : NetworkGeneral(), tcpServer(new QTcpServer(this)),
    blockSize(0), clientConnection(nullptr)

{
    tcpServer->listen(QHostAddress::Any, 5555);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sessionOpened()));

    ipAddressesList = QNetworkInterface::allAddresses();
    QStringList ipList;
    for (int i = 0; i < ipAddressesList.size(); i++)
    {
        ipList.append(ipAddressesList[i].toString());
    }
}

ServerNetwork::~ServerNetwork()
{
    delete tcpServer;
    if (clientConnection != nullptr)
        delete clientConnection;
}

QList<QHostAddress> ServerNetwork::getAddressesAvailable()
{
    return ipAddressesList;
}

void ServerNetwork::sessionOpened()
{
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readTextMsg()));
    emit sessionOpenedSig();
}

void ServerNetwork::sendTextMessage(QString stringToCode)
{
    QByteArray block = TransmissionCoder::codeForTransmission(stringToCode);
    clientConnection->write(block);
}

void ServerNetwork::readTextMsg()
{
    QString newText;
    try
    {
        newText = TransmissionCoder::decodeFromTransmission(clientConnection, blockSize);
        emit newMessage(newText);
    }
    catch (UnreliableTransmission)
    {
        return;
    }
    blockSize = 0;
}

void ServerNetwork::setOnline(const QHostAddress &address, quint16 port)
{
    if (clientConnection != nullptr)
    {
        clientConnection->disconnectFromHost();
        delete clientConnection;
        clientConnection = nullptr;
    }
    tcpServer->close();
    tcpServer->listen(address, port);
  //  ui->portLabel->setText(QString::number(tcpServer->serverPort()));
   // ui->sendButton->setEnabled(false);
}
