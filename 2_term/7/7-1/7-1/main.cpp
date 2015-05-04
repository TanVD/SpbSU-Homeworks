#include "exampleClass.h"
#include "myException.h"
#include <iostream>

using namespace std;

int exampleBlock()
{
    ExampleClass object;
    throw MyException("Something bad happened");
    return 1;
}


int main()
{
    try
    {
    exampleBlock();
    }
    catch (MyException)
    {
        cout << "Was caught exception" << endl;
    }
}
