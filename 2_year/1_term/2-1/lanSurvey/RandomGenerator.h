#pragma once
#include <time.h>
#include <QtGlobal>

class RandomGenerator
{
public:
    static bool tryChance(int percent);
    static void makeFake(int percent);
private:
    static int makeFakingPercent;
};

