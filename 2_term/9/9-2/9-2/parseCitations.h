#pragma once
#include <QString>
#include <QStringList>

class ParseCitations
{
public:
    /**
     * @brief parseFromHtmlQuotes Parse from html page quotes by class="text"
     * @param toParse htmlpage to parse
     * @return List of strings with quotes
     */
    static QStringList parseFromHtmlQuotes(const QString &toParse);

    /**
     * @brief parseFromHtmlCurrentPage Parse from html page number of current page
     * @param toParse htmlpage to parse
     * @return current page number
     */
    static int parseFromHtmlCurrentPage(const QString &toParse);
};

