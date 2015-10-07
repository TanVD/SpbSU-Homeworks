#pragma once
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QNetworkSession>
#include <QDataStream>
#include <AvatarControl.h>
#include "networkinterface.h"


class ServerNetwork : public NetworkGeneral
{
    Q_OBJECT

public:
    explicit ServerNetwork(QWidget *parent = 0);
    ~ServerNetwork();
    QList<QHostAddress> getAddressesAvailable();
    void setOnline(const QHostAddress &address, quint16 port);

signals:
    void sessionOpenedSig();

public slots:
    void sendTextMessage(QString stringToCode) override;

private slots:
    void sessionOpened();
    void readTextMsg();

private:
    QList<QHostAddress> ipAddressesList;
    QTcpServer* tcpServer;
    quint16 blockSize;
    QTcpSocket* clientConnection;
};
