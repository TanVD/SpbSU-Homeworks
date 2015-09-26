#include "OS.h"

OS::OS(const OSName &name) : name(name)
{}

OS::OS(const QString &name)
{
    if (name.toLower() == "linux")
    {
        this->name = Linux;
    }
    else if (name.toLower() ==  "macos")
    {
        this->name = MacOS;
    }
    else if (name.toLower() ==  "windows")
    {
        this->name = Windows;
    }
}

OSName OS::getOSName() const
{
    return name;
}

int OS::getOSChance() const
{
    return getChance(name);
}

int OS::getChance(OSName name) const
{
    int chance = 0;
    switch (name)
    {
        case Linux:
    {
        chance = 10;
        break;
    }
    case MacOS:
    {
        chance = 20;
        break;
    }
    case Windows:
    {
        chance = 35;
        break;
    }
    }
    return chance;
}

