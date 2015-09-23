#include "OS.h"

OS::OS(OSName name) : name(name)
{}

OS::OS(QString name)
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

OSName OS::getOSName()
{
    return name;
}

int OS::getOSChance()
{
    return getChance(name);
}

int OS::getChance(OSName name)
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

