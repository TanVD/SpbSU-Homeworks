#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{ }

bool RandomGenerator::tryChance(int percent)
{
    int randomNumber = qrand() % 100;
    return (randomNumber < percent);
}
