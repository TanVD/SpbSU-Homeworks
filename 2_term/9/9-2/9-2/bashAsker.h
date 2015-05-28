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

    /**
     * @brief getPreviousPage Get previous html page with quotes according to current number
     * @return String with html page
     */
    QString getPreviousPage();

    /**
     * @brief getPreviousPage Get main html page with quotes, initializes current number
     * @return String with html page
     */
    QString getMainPage();

    /**
     * @brief getPreviousPage Get next html page with quotes according to current number
     * @return String with html page
     */
    QString getNextPage();

    /**
     * @brief getPreviousPage Get random html page with quotes
     * @return String with html page
     */
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
