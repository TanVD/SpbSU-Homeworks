#include <iostream>
#include <stdio.h>
#include "calculator.h"
#include <QTest>
#include "testStack.h"
#include "testCalc.h"

using namespace std;

char* getStringConsole(int *counter, char* out)
{
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            out[*counter] = c;
            *counter = *counter + 1;
        }
    }
    return out;
}

int main()
{
    StackTest test1;
    QTest::qExec(&test1);
    CalcTest test2;
    QTest::qExec(&test2);
    cout << "This program will calculate your equation.\nDon't input equations more than 99 symbols.\nInput: ";
    int counter = 0;
    char* equationIn = new char[100];
    getStringConsole(&counter, equationIn);
    Calculator calc;
    calc.calculate(equationIn, counter);
    if (calc.isResultValid())
        cout << "Output: " << calc.returnResult() << endl;
    else
        cout << "Not valid" << endl;
    return 0;
}

