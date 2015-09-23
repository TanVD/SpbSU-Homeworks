#pragma once
#include "ariphTree.h"
#include <string>
#include <QFile>

/**
 * @brief The ParserOfEquation class implements simple mechanism of parsint text file with equation to binary tree.
 */
class ParserOfEquation
{
public:
    /**
     * @brief ParseFile Parsing file in equation tree from prefix equation
     * @param filename Name of file to parse
     * @return QString parsed from file
     */
    static AriphTree* parseFile(QFile* file);
};
