#pragma once
/**
 * @brief Interface for sorting arrays
 */
class SortInterface
{
public:
    /**
     * @mainpage SortInterface makes easier to work with bubblesort and quicksort implemenatations
     * @brief SortArray virtual function of Interface which make child to implement sort of array
     */
    virtual void sortArray() = 0 ;

    virtual ~SortInterface() {};
protected:
    /**
     * @brief mySwap Common for sorting swap function
     * @param a First param to swap
     * @param b Second param to swap
     */
    void mySwap(int *a, int *b);
};
