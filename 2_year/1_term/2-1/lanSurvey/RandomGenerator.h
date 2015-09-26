#pragma once
#include <time.h>
#include <QtGlobal>

class RandomGenerator
{
public:
    static bool tryChance(int percent);

    /**
     * @brief makeFake Makes chance for percent
     * parameter equal to 100% for every call of
     * try chance from now
     * @param percent Percent for fake
     */
    static void makeFake(int percent);

private:
    static int makeFakingPercent;
};

