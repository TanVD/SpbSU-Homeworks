#include <iostream>
#include <limits.h>
#include <iostream>
#include <iomanip>

using namespace std;

long long int getIntfromBin(int array[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum = sum * 2 + array[i];
    }
    sum = sum - 1023;
    return sum;
}

double getDoublefromBin(int array[], int start, int end)
{
    double sum = 0;
    for (int i = end; i >= start; i--)
    {
        sum = sum / 2 + array[i];
    }
    sum = sum / 2 + 1;
    return sum;
}

int main()
{
    int const bitSize = 64;
    cout << "Enter number: ";
    double number = 0;
    cin >> number;
    long long int bits = *((long long int*) &number);

    unsigned long long int bit = 1;
    bit <<= 63;

    int bitNumber[bitSize];

    for (int i = 0; i < 64; i++)
    {
        if ((bit & bits) != 0)
        {
            bitNumber[i] = 1;
        }
        else
        {
            bitNumber[i] = 0;
        }
        bit >>= 1;
    }

    char mark = '+';
    if (bitNumber[0] == 1)
        mark = '-';

    int exponent = getIntfromBin(bitNumber, 1, 11);

    double mantissa = getDoublefromBin(bitNumber, 12, 63);

    cout << "Your exponential form is " << mark << setprecision(10) << mantissa << "*2^(" << exponent << ")" << endl;

    return 0;
}

