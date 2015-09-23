#include "sortInterface.h"

void SortInterface::mySwap(int *a, int *b)
{
    if (*a != *b)
    {
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
    }

}
