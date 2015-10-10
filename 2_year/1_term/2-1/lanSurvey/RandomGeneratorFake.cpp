#include "RandomGeneratorFake.h"

RandomGeneratorFake::RandomGeneratorFake()
{ }

bool RandomGeneratorFake::tryChance(int percent)
{
    int randomNumber = qrand() % 100;
    return (randomNumber < percent) || (makeFakingList.contains(percent));
}

void RandomGeneratorFake::makeFake(int percent)
{
    makeFakingList.append(percent);
}

void RandomGeneratorFake::resetMakeFakeList()
{
    makeFakingList.clear();
}
