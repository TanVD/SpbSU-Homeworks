#include "parseCitations.h"

QStringList ParseCitations::parseFromHtmlQuotes(const QString &toParse)
{
    QString html = toParse;
    QStringList textList;
    while (html.contains("<div class=\"text\">"))
    {
        int posBegin = html.indexOf("<div class=\"text\">") + 18;
        int posEnd = html.indexOf("</div>", html.indexOf("<div class=\"text\">"));
        QString text = html.mid(posBegin, posEnd - posBegin);
        html.remove(posBegin - 1, posEnd - posBegin + 1);
        textList.append(text);
    }
    return textList;
}

int ParseCitations::parseFromHtmlCurrentPage(const QString &toParse)
{
    QString html = toParse;
    int locateClass = html.indexOf("<div class=\"pager\">");
    int posBegin = html.indexOf("value=\"", locateClass) + 7;
    int posEnd = html.indexOf("\"", posBegin);
    QString number = html.mid(posBegin, posEnd - posBegin);
    int currentPage = number.toInt();
    return currentPage;
}
