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
    QStringList fortunes;
    QNetworkSession *networkSession;

private slots:
    void sessionOpened();
    void sendTextMessage();
    void readTextMsg();

private:
    Ui::MyServer *ui;
};

