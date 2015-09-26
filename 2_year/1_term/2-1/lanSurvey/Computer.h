#include "OS.h"
#include "RandomGenerator.h"
#include <QtGlobal>

/**
 * @brief The Computer class represent computer object which can
 * be infected
 */

class Computer
{
public:
    Computer();

    Computer(OS os);

    /**
     * @brief getOSName Returns OS name of this computer. List of
     * OS names specified in OS.h
     * @return OSName enum
     */
    OSName getOSName() const;

    /**
     * @brief tryToInfect Trying to infect this object
     * paying attention to the chance of infecting
     * @return True if object was infected, false otherwise
     */
    bool tryToInfect();

    /**
     * @brief infectForced Infects this object not paying
     * attention to the chance of infecting
     */
    void infectForced();

    bool isInfected() const;

private:
    OS computerOS;
    bool infectionStatus;
};

