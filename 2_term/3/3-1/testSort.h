#pragma once
#include "bubbleSort.h"
#include "quickSort.h"
#include "sortInterface.h"
#include <QtTest/QtTest>
#include <QtCore/QObject>
class SortTest : public QObject
{
   Q_OBJECT
public:
   explicit SortTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        array = new int[30];
        for (int i = 0; i < 30; i++)
        {
            array[29 - i] = i;
        }
    }

    void testQuickSort()
    {
        sort = new QuickSort(array, 30);
        sort->sortArray();
        for (int i = 0; i < 30; i++)
        {
            QVERIFY(array[i] == i);
        }
    }

    void testBubbleSort()
    {
        sort = new BubbleSort(array, 30);
        sort->sortArray();
        for (int i = 0; i < 30; i++)
        {
            QVERIFY(array[i] == i);
        }
    }

    void cleanup()
    {
        delete[] array;
        delete sort;
    }

private:
    SortInterface* sort;
    int* array;

};
