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
    OS(const OSName &name);
    OS(const QString &name);
    OSName getOSName() const;
    int getOSChance() const;

private:
    int getChance(OSName name) const;
    OSName name;
};
