#include "Computer.h"

Computer::Computer() : computerOS(OSSwitcher::getOS("Linux")), infectionStatus(false)
{}

Computer::Computer(OS *os, RandomGeneratorInterface *generator)
    : computerOS(os), infectionStatus(false), generator(generator)
{}

Computer::~Computer()
{
}

OSName Computer::getOSName() const
{
    return computerOS->getOSName();
}

bool Computer::tryToInfect()
{
    if (generator->tryChance(computerOS->getOSChance()))
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

