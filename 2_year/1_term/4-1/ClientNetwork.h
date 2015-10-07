#pragma once
#include <QTcpSocket>
#include "networkinterface.h"

class ClientNetwork : public NetworkGeneral
{
    Q_OBJECT

public:
    explicit ClientNetwork(QWidget *parent = 0);
    void connectToServer(QString ip, quint16 port);
    ~ClientNetwork();

public slots:
    void sendTextMessage(QString stringToCode) override;

private:
    QTcpSocket *serverConnection;
    quint16 blockSize;

private slots:
    void readTextMsg();

    void connected();
    void disconnected();
};
