#include "OSSwitcher.h"

OS *OSSwitcher::getOS(const QString &name)
{
        if (name.toLower() == "linux")
        {
            return new OSLinux;
        }
        else if (name.toLower() ==  "macos")
        {
            return new OSMac;
        }
        else if (name.toLower() ==  "windows")
        {
            return new OSWindows;
        }
}

OS *OSSwitcher::getOS(const OSName &name)
{
    if (name == Linux)
    {
        return new OSLinux;
    }
    else if (name == MacOS)
    {
        return new OSMac;
    }
    else if (name == Windows)
    {
        return new OSWindows;
    }
}

