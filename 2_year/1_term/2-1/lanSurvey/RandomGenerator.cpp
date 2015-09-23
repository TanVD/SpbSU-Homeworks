#include "RandomGenerator.h"

bool RandomGenerator::tryChance(int percent)
{
    qsrand(time(NULL));
    int randomNumber = qrand() % 100;
    if (randomNumber < percent)
        return true;
    return false;
}
