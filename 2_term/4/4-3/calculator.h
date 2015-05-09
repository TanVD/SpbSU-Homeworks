#pragma once
#include <QString>

class Calculator
{
public:
    Calculator();
    void calculate(QString equation, int length);
    double returnResult();
    bool isResultValid();

private:
    QString equation;
    double result;
    bool valid;
    static double postCalculate(QString expressionPost, int expressionEnd, bool *isValid);
    static int infToPostform(QString expressionIn, QString &expressionPost, int expressionInEnd);
    static QChar outputOperation(int operationInt);
    static int inputOperation(QChar operationChar);

};

