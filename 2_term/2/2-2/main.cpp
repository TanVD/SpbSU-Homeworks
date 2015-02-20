#include <iostream>
#include <infToPostForm.h>
#include <postCalculate.h>

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
    char* equationPost = new char[200];
    int newLength = infToPostform(equationIn, equationPost, counter);
    bool isValid = true;
    double result = postCalculate(equationPost, newLength, &isValid);
    if (isValid)
        cout << "Output: " << result << endl;
    else
        cout << "Not valid" << endl;
    delete[] equationIn;
    delete[] equationPost;
    return 0;
}

