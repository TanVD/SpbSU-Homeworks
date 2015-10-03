#pragma once
#include <OS.h>

class OSLinux : public OS
{
public:
    OSLinux();
    virtual OSName getOSName() const;
    virtual int getOSChance() const;
};

