#include "OSLinux.h"

OSLinux::OSLinux()
{ }

OSName OSLinux::getOSName() const
{
    return Linux;
}

int OSLinux::getOSChance() const
{
    return 10;
}

