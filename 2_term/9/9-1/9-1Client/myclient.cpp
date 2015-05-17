#include "myclient.h"
#include "ui_myclient.h"
#include "transmissionCoder.h"

myclient::myclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myclient),
    blockSize(0)
{
    ui->setupUi(this);
    serverConnection = new QTcpSocket;//TODO
    connect(ui->sendButton, SIGNAL(clicked(bool)), this, SLOT(sendTextMessage()));
    connect(serverConnection, SIGNAL(readyRead()), this, SLOT(readTextMsg()));
    connect(ui->connectButton, SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
}

myclient::~myclient()
{
    delete ui;
}

void myclient::sendTextMessage()
{
    QString stringToCode = ui->sendText->toPlainText();
    QByteArray block = TransmissionCoder::codeForTransmission(stringToCode);
    serverConnection->write(block);
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

void myclient::connectToServer()
{
    blockSize = 0;
    serverConnection->connectToHost(ui->ipText->text(), ui->portText->text().toInt());
    connect(serverConnection, SIGNAL(connected()), this, SLOT(testConnect()));
}

void myclient::testConnect()
{
    ui->connectionLabel->setText("Connected");
}
