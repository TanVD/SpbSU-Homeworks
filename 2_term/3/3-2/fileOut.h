#pragma once
#include "outputInterface.h"
#include "matrix.h"
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
    FileOut(Matrix *matrix);
    /**
     * @brief out The function of outputing into file. Implementation of interface function.
     */
    void out();

    ~FileOut();
};

