#include "OS.h"
#include "RandomGenerator.h"
#include <QtGlobal>


class Computer
{
public:
    Computer();
    Computer(OS os);
    OSName getOSName();
    bool tryToInfect();
    void infectForced();
    bool isInfected();
private:
    OS computerOS;
    bool infectionStatus;
};

