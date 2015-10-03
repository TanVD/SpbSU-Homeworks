#pragma once
#include "RandomGeneratorInterface.h"
#include <time.h>
#include <QtGlobal>
#include <QList>

class RandomGeneratorFake : public RandomGeneratorInterface
{
public:
    RandomGeneratorFake();

    bool tryChance(int percent);

    /**
     * @brief makeFake Makes chance for percent
     * parameter equal to 100% for every call of
     * try chance from now
     * @param percent Percent for fake
     */
    void makeFake(int percent);

    void resetMakeFakeList();


private:
    QList<int> makeFakingList;
};
