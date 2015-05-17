#pragma once
#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class myclient;
}

class myclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit myclient(QWidget *parent = 0);
    ~myclient();
private:
    QTcpSocket *serverConnection;
    quint16 blockSize;
private slots:
    void sendTextMessage();
    void readTextMsg();
    void connectToServer();
    void testConnect();

private:
    Ui::myclient *ui;
};

