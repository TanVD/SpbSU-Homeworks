#pragma once

class RandomGeneratorInterface
{
public:
    virtual bool tryChance(int percent) = 0;
};

