#pragma once
#include "outputInterface.h"
#include "matrix.h"
/**
 * @brief The ConsoleOut class Class of outputing in console
 */
class ConsoleOut : public OutputInterface
{
public:
    /**
     * @brief ConsoleOut Constructot which gets all necessary information about array
     * @param array Array to be written
     * @param lengthArray Length of array to be written
     */
    ConsoleOut(Matrix* matrix);

    /**
     * @brief out The function of outputing to console. Implementation of interface function.
     */
    void out();

    ~ConsoleOut();
};

