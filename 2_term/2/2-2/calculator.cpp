#include "calculator.h"
#include "infToPostForm.h"
#include "postCalculate.h"

calculator::calculator() : result(0), valid(true), equation(nullptr)
{
}

calculator::~calculator()
{
    delete[] equation;
}

void calculator::calculate(char *equationIn, int length)
{
    this->equation = equationIn;
    char* equationPost = new char[200];
    int newLength = infToPostform(equationIn, equationPost, length);
    valid = true;
    result = postCalculate(equationPost, newLength, &valid);
    delete[] equationPost;
}

double calculator::returnResult()
{
    return result;
}

bool calculator::isResultValid()
{
    return valid;
}

