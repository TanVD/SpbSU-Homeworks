#include "listunique.h"
#include "addexistedelementexception.h"
#include "outofindexes.h"
#include "deletenonexistedelementexception.h"

void ListUnique::add(int value)
{
    if (isInList(value))
    {
        throw AddExistedElement();
    }
    else
    {
        List::add(value);
    }
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
    else
    {
        List::add(value, index);
    }
}

void ListUnique::removeValue(int value)
{
    if (!isInList(value))
    {
        throw DeleteNonExistedElement();
    }
    else
    {
        List::removeValue(value);
    }
}

void ListUnique::removeIndex(int index)
{
    if (!isExistsIndex(index + 1))
    {
        throw OutOfIndexes();
    }
    else
    {
        List::removeIndex(index);
    }
}
