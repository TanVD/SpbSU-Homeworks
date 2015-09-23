#include "parseCitations.h"

QStringList ParseCitations::parseFromHtmlQuotes(const QString &toParse)
{
    QString html = toParse;
    QStringList textList;
    QString tagOpen = "<div class=\"text\">";
    QString tagClose = "</div>";
    while (html.contains(tagOpen))
    {
        int posBegin = html.indexOf(tagOpen) + tagOpen.length();
        int posEnd = html.indexOf(tagClose, html.indexOf(tagOpen));
        QString text = html.mid(posBegin, posEnd - posBegin);
        html.remove(posBegin - 1, posEnd - posBegin + 1);
        textList.append(text);
    }
    return textList;
}

int ParseCitations::parseFromHtmlCurrentPage(const QString &toParse)
{
    QString html = toParse;
    QString tagOpen = "value=\"";
    QString tagClose = "\"";
    int locateClass = html.indexOf("<div class=\"pager\">");
    int posBegin = html.indexOf(tagOpen, locateClass) + tagOpen.length();
    int posEnd = html.indexOf(tagClose, posBegin);
    QString number = html.mid(posBegin, posEnd - posBegin);
    int currentPage = number.toInt();
    return currentPage;
}
