#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

enum conditions
{
    start,
    digitAfterSign,
    digit,
    firstDigitAfterDot,
    digitAfterDot,
    e,
    signAfterE,
    digitAfterE,
    other,
    otherTrue
};

bool isDigit(char c)
{
    return (c >='0' && c <= '9');
}

bool isZero(char c)
{
    return (c == '0');
}

bool isSign(char c)
{
    return (c == '-' || c == '+');
}

bool isDot(char c)
{
    return (c == '.');
}

bool isE(char c)
{
    return (c == 'E');
}

bool isTerminal(char c)
{
    return (c == '\0');
}

int main()
{
    //char fileLocation[100];
    //memset(fileLocation, '\0', 100);
    //cout << "Enter the file with your number to check if it is correct: ";
    //cin >> fileLocation;
    //ifstream in (fileLocation);
    //in >> equation;
    //in.close()
    char equation[1000];
    memset(equation, '\0', 1000);
    cout << "Enter your number to check if it is correct: ";
    cin >> equation;
    int state = start;
    int i = 0;
    while (true)
    {
        switch (state)
        {
            case start:
            {
                if (isDigit(equation[i]) && !isZero(equation[i]))
                {
                    state = digit;
                }
                else if (isSign(equation[i]))
                {
                    state = digitAfterSign;
                }
                else if (isZero(equation[i]))
                {
                    i++;
                    if (isDot(equation[i]))
                        state = firstDigitAfterDot;
                    else if (isTerminal(equation[i]))
                        state = otherTrue;
                    else
                        state = other;
                }
                else
                {
                    state = other;
                }
                i++;
                break;
            }
            case digitAfterSign:
            {
                if (isDigit(equation[i]) && !isZero(equation[i]))
                {
                    state = digit;
                }
                else if (isZero(equation[i]))
                {
                    i++;
                    if (isDot(equation[i]))
                        state = firstDigitAfterDot;
                    else if (isTerminal(equation[i]))
                        state = otherTrue;
                    else
                        state = other;
                }
                else
                {
                    state = other;
                }
                i++;
                break;
            }
            case digit:
            {
                if (isDigit(equation[i]))
                {
                   i++;
                }
                else if (isDot(equation[i]))
                {
                   state = firstDigitAfterDot;
                   i++;
                }
                else if (isE(equation[i]))
                {
                    state = e;
                    i++;
                }
                else
                {
                    state = otherTrue;
                }
                break;
            }
            case firstDigitAfterDot:
            {
                if (isDigit(equation[i]))
                {
                   state = digitAfterDot;
                }
                else
                {
                    state = other;
                }
                i++;
                break;
            }
            case digitAfterDot:
            {
                if (isDigit(equation[i]))
                {
                   i++;
                }
                else if (isE(equation[i]))
                {
                   state = e;
                   i++;
                }
                else
                {
                    state = otherTrue;
                }
                break;
            }
            case e:
            {
                if (isDigit(equation[i]) && !isZero(equation[i]))
                {
                    state = digitAfterE;
                }
                else if (isSign(equation[i]))
                {
                    state = signAfterE;
                }
                else
                {
                    state = other;
                }
                i++;
                break;
            }
            case signAfterE:
            {
                if (isDigit(equation[i]) && !isZero(equation[i]))
                {
                    state = digitAfterE;
                }
                else
                {
                    state = other;
                }
                i++;
                break;
            }
            case digitAfterE:
            {
                if (isDigit(equation[i]))
                {
                   i++;
                }
                else
                {
                    state = otherTrue;
                }
                break;
            }
            case other:
            {
                cout << "Wrong\n";
                return 0;
            }
            case otherTrue:
            {
                if (equation[i] == '\0')
                {
                    cout << "Ok\n";
                }
                else
                {
                    cout << "Wrong\n";
                }
                return 0;
            }
        }
    }
    return 0;
}
