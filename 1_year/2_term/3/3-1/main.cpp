#include <iostream>
#include "sortInterface.h"
#include "quickSort.h"
#include "bubbleSort.h"
#include "QTest"
#include "testSort.h"

using namespace std;

int main()
{
    SortTest test;
    QTest::qExec(&test);
    cout << "Enter the length of your array: ";
    int length = 0;
    cin >> length;
    int* array = new int[length];
    cout << "Enter the array: ";
    for (int i = 0; i < length; i++)
    {
        int element;
        cin >> element;
        array[i] = element;
    }
    int mode = 0;
    cout << "What way do you want to sort your array?\n1 - QuickSort\n2 - BubbleSort\nChoose mode: ";
    cin >> mode;
    if (mode == 1)
    {
        SortInterface* sort = new QuickSort(array, length);
        sort->sortArray();
        delete sort;
    }
    else if (mode == 2)
    {
        SortInterface* sort = new BubbleSort(array, length);
        sort->sortArray();
        delete sort;
    }
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    delete[] array;
    return 0;
}

