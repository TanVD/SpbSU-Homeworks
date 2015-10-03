#pragma once
#include <OS.h>


class OSWindows : public OS
{
public:
    OSWindows();
    virtual OSName getOSName() const;
    virtual int getOSChance() const;
};

