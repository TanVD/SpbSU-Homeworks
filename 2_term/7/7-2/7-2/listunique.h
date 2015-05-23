#pragma once
#include "list.h"
#include "addExistedElementException.h"
#include "outofindexes.h"
#include "deleteNonExistedElementException.h"

class ListUnique : public List
{
public:
    /**
     * @brief add Add the specified value to this instance of List. According to unique rule.
     * @param value Value to add.
     */
    void add(int value);

    /**
     * @brief add Add the specified value to this instance of List to the place determined by index. According to unique rule.
     * @param value Value to add.
     * @param index Index.
     */
    void add(int value, int index);

    /**
     * @brief removeValue Removes the value form this instance of List. According to unique rule.
     * @param value Value to remove.
     */
    void  removeValue(int value);

    /**
     * @brief removeIndex Removes the value specified by index. According to unique rule.
     * @param index Index.
     */
    void removeIndex(int index);
};

