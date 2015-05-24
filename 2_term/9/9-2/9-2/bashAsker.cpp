#include "bashAsker.h"
#include <QTextCodec>
#include "parseCitations.h"

BashAsker::BashAsker() : currentPage(1)
{
    connect(&accAPI, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
}

void BashAsker::finishedSlot(QNetworkReply *replyOnPost)
{
    if (replyOnPost->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = replyOnPost->readAll();
        QTextCodec* myCodec = QTextCodec::codecForHtml(bytes);
        reply = myCodec->toUnicode(bytes);
    }
    else
    {
        reply = "";
    }
    delete replyOnPost;

    loop.exit();
}

QString BashAsker::passQueryToServer()
{
    accAPI.get(QNetworkRequest(url));
    loop.exec();
    return reply;
}

QString BashAsker::getPreviousPage()
{
    QString server = "bash.im";
    url = "http://"+ server;
    if (currentPage != 1)
    {
        url += "/index/" + QString::number(currentPage - 1);
        currentPage--;
    }
    passQueryToServer();
    return reply;
}

QString BashAsker::getMainPage()
{
    QString server = "bash.im";
    url = "http://"+ server;
    passQueryToServer();
    QString tmp = reply;
    maxPage = ParseCitations::parseFromHtmlCurrentPage(tmp);
    currentPage = maxPage;
    return reply;
}

QString BashAsker::getNextPage()
{
    QString server = "bash.im";
    url = "http://"+ server;
    if (currentPage < maxPage)
    {
        url += "/index/" + QString::number(currentPage + 1);
        currentPage++;
    }
    passQueryToServer();
    return reply;
}

QString BashAsker::getRandomPage()
{
    QString server = "bash.im";
    url = "http://"+ server;
    url += "/random";
    currentPage++;
    passQueryToServer();
    return reply;
}

