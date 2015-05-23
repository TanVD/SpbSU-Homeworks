#pragma once
#include <QString>

class MyException
{
public:
    MyException(QString message);
private:
    QString exceptionData;
};
