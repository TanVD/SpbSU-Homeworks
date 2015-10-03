#pragma once
#include <QString>

enum OSName
{
    Linux,
    MacOS,
    Windows
};

class OS
{
public:
    OS() { }
    virtual OSName getOSName() const = 0;
    virtual int getOSChance() const = 0;
};
