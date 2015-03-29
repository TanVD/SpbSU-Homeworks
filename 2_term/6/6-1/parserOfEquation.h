#pragma once
#include "ariphTree.h"
#include <string>
#include <QFile>

class ParserOfEquation
{
public:
    /**
     * @brief ParseFile Parsing file in equation tree from prefix equation
     * @param filename Name of file to parse
     * @return QString parsed from file
     */
    static AriphTree* ParseFile(QFile* file);
};
