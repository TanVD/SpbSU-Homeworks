#include "Computer.h"

Computer::Computer() : computerOS(OS(Linux)), infectionStatus(false)
{}

Computer::Computer(OS os) : computerOS(os), infectionStatus(false)
{}

OSName Computer::getOSName() const
{
    return computerOS.getOSName();
}

bool Computer::tryToInfect()
{
    if (RandomGenerator::tryChance(computerOS.getOSChance()))
    {
        infectionStatus = true;
    }
    return infectionStatus;
}

void Computer::infectForced()
{
    infectionStatus = true;
}

bool Computer::isInfected() const
{
    return infectionStatus;
}

