#pragma once
#include "outputInterface.h"
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
    ConsoleOut(int* array, int lengthArray);
    /**
     * @brief out The function of outputing to console. Implementation of interface function.
     */
    void out();
private:
    int* array;
    int lengthArray;
};

