#pragma once
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QEventLoop>

class BashAsker : public QObject
{
    Q_OBJECT
public:
    BashAsker();

    QString getPreviousPage();
    QString getMainPage();
    QString getNextPage();
    QString getRandomPage();
private slots:
    QString passQueryToServer();
    void finishedSlot(QNetworkReply *replyOnPost);
private:
    QNetworkAccessManager accAPI;
    int currentPage;
    int maxPage;
    QString reply;
    QEventLoop loop;
    QString url;
};
