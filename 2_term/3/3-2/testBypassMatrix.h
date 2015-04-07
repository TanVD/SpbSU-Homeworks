#pragma once
#include "outputInterface.h"
#include "consoleOut.h"
#include "matrix.h"
#include <QtCore/QObject>
#include <QtTest/QtTest>

class BypassMatrixTest : public QObject
{
   Q_OBJECT
public:
    explicit BypassMatrixTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        int** newMatrix = new int*[3];
        for (int i = 0; i < 3; i++)
        {
            newMatrix[i] = new int[3];
            for (int j = 1; j < 4; j++)
            {
                newMatrix[i][j - 1] = i * 3 + j;
            }
        }
        matrix = new Matrix(newMatrix, 3);
        out = new ConsoleOut(matrix);
    }

    void testBypass()
    {
        int* str = new int[9] {5, 8, 9, 6, 3, 2, 1, 4, 7};
        for (int i = 0; i < 9; i++)
        {
            QVERIFY(out->returnBypass()[i] == str[i]);
        }
    }

private:
    OutputInterface* out;
    Matrix* matrix;
};
