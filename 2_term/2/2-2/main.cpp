#include <iostream>
#include "calculator.h"

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
    cout << "This program will calculate your equation.\nDon't input equations more than 99 symbols.\nInput: ";
    int counter = 0;
    char* equationIn = new char[100];
    getStringConsole(&counter, equationIn);
    calculator calc;
    calc.calculate(equationIn, counter);
    if (calc.isResultValid())
        cout << "Output: " << calc.returnResult() << endl;
    else
        cout << "Not valid" << endl;
    return 0;
}

