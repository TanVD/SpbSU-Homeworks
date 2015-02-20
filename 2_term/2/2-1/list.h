#pragma once

class List
{
public:
    void virtual add(int value) = 0;
    bool virtual remove(int value) = 0;
    virtual ~List() {}
    void virtual print() = 0;

};

