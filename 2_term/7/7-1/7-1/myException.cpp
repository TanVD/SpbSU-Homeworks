#include "myException.h"
#include "iostream"

MyException::MyException(QString message) : exceptionData(message)
{
    std::cout << "Exception was generated" << std::endl;
}

