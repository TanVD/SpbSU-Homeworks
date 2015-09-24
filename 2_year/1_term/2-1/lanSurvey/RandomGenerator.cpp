#include "RandomGenerator.h"

int RandomGenerator::makeFakingPercent = 0;

bool RandomGenerator::tryChance(int percent)
{
    int randomNumber = qrand() % 100;
    if (randomNumber < percent || percent == makeFakingPercent)
        return true;
    return false;
}

void RandomGenerator::makeFake(int percent)
{
    makeFakingPercent = percent;
}
