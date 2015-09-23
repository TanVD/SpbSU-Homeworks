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
    OS(OSName name);
    OS(QString name);
    OSName getOSName();
    int getOSChance();

private:
    int getChance(OSName name);
    OSName name;
};
