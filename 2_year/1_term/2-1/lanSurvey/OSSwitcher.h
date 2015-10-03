#pragma once
#include "OS.h"
#include "OSLinux.h"
#include "OSMac.h"
#include "OSWindows.h"

class OSSwitcher
{
public:
    static OS *getOS(const QString &name);
    static OS *getOS(const OSName &name);
};
