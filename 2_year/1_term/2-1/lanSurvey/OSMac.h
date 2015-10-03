#pragma once
#include <OS.h>

class OSMac : public OS
{
public:
    OSMac();
    virtual OSName getOSName() const;
    virtual int getOSChance() const;
};

