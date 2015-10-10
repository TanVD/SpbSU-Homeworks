#include "OSMac.h"

OSMac::OSMac()
{ }

OSName OSMac::getOSName() const
{
    return MacOS;
}

int OSMac::getOSChance() const
{
    return 20;
}

