#pragma once
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QNetworkSession>
#include <QDataStream>


namespace Ui {
class MyServer;
}

class MyServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyServer(QWidget *parent = 0);
    ~MyServer();
    QTcpServer* tcpServer;
    quint16 blockSize;
    QTcpSocket* clientConnection;

private slots:
    void sessionOpened();
    void sendTextMessage();
    void readTextMsg();
    void changeIpAddress(int index);

private:
    Ui::MyServer *ui;
    QList<QHostAddress> ipAddressesList;
};

