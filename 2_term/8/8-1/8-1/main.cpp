#include <iostream>
#include "BST.h"
#include <QTest>
#include "settest.h"

using namespace std;

int main()
{
    SetTest test;
    QTest::qExec(&test);
    return 0;
}

