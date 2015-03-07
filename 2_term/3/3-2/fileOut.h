#pragma once
#include "outputInterface.h"
/**
 * @brief The FileOut class Class of outputing in file
 */
class FileOut : public OutputInterface
{
public:
    /**
     * @brief FileOut Constructor which gets all necessary information about file and array
     * @param array Array to be written
     * @param lengthArray Length of array to be written
     */
    FileOut(int* array, int lengthArray);
    /**
     * @brief out The function of outputing into file. Implementation of interface function.
     */
    void out();
private:
    int* array;
    int lengthArray;
};

