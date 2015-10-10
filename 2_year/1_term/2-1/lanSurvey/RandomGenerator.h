#pragma once
#include <RandomGeneratorInterface.h>
#include <time.h>
#include <QtGlobal>

class RandomGenerator : public RandomGeneratorInterface
{
public:
    RandomGenerator();
    bool tryChance(int percent);
};

