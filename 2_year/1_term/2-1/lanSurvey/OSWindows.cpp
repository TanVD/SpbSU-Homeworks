#include "OSWindows.h"

OSWindows::OSWindows()
{ }

OSName OSWindows::getOSName() const
{
    return Windows;
}

int OSWindows::getOSChance() const
{
    return 35;
}

