#include "listunique.h"

void ListUnique::add(int value)
{
    if (isInList(value))
    {
        throw AddExistedElement();
    }
    List::add(value);
}

void ListUnique::add(int value, int index)
{
    if (!isExistsIndex(index))
    {
        throw OutOfIndexes();
    }
    else if (isInList(value))
    {
        throw AddExistedElement();
    }
    List::add(value, index);
}

void ListUnique::removeValue(int value)
{
    if (!isInList(value))
    {
        throw DeleteNonExistedElement();
    }
    List::removeValue(value);
}

void ListUnique::removeIndex(int index)
{
    if (!isExistsIndex(index + 1))
    {
        throw OutOfIndexes();
    }
    List::removeIndex(index);
}
