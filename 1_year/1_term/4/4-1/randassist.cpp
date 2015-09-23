#include <time.h>
#include <stdlib.h>

void randomizeRand()
{
    long timeSeed = time(NULL);
    srand(timeSeed);
}
