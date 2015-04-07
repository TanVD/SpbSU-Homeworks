#pragma once
#include "matrix.h"
/**
  * @mainpage OutputInterface makes it easier to work with output in file and console
  */

/**
 * @brief The OutputInterface class Is the interface of outputing int arrays in file or console
 */
class OutputInterface
{
public:
    OutputInterface();
    /**
     * @brief ~OutputInterface Virtual destructor
     */
    virtual ~OutputInterface() {};
    /**
     * @brief out Virtual method of outputing int arrays which makes childs of interface implement outputing
     */
    virtual void out() = 0;
    /**
     * @brief returnBypass Returns result of matrix spiral bypass as int array
     * @return Int array length of size*size
     */
    int* returnBypass();
protected:
    /**
     * @brief bypassMatrix Create int array from matrix passing spiral way
     * @param matrix Matrix to pass
     */
    void bypassMatrix(Matrix* matrix);
    int *array;
    int lengthArray;
};

