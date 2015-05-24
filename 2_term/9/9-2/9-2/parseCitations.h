#pragma once
#include <QString>
#include <QStringList>

class ParseCitations
{
public:
    static QStringList parseFromHtmlQuotes(const QString &toParse);
    static int parseFromHtmlCurrentPage(const QString &toParse);
};

