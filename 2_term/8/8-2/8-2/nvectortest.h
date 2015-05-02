#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "nVector.h"


class NVectorTest : public QObject
{
    Q_OBJECT
public:
    explicit NVectorTest(QObject *parent = 0) : QObject(parent) {}
private slots:
    void nVectorFirstTest()
    {
        NVector<int> vector;
        vector.append(8);
        vector.append(9);
        QCOMPARE(vector[0], 8);
        QCOMPARE(vector[1], 9);
        QVERIFY(!vector.isNull());
    }

    void nVectorSumOneTest()
    {
        NVector<int> vectorFirst;
        for (int i = 1; i < 4; i++)
        {
            vectorFirst.append(i);
        }
        NVector<int> vectorSecond;
        for (int i = 5; i < 8; i++)
        {
            vectorSecond.append(i);
        }


        NVector<int> result = vectorFirst + vectorSecond;
        QCOMPARE(result[0], 6);
        QCOMPARE(result[1], 8);
        QCOMPARE(result[2], 10);
    }

    void nVectorMinOneTest()
    {
        NVector<int> vectorFirst;
        for (int i = 1; i < 4; i++)
        {
            vectorFirst.append(i);
        }
        NVector<int> vectorSecond;
        for (int i = 5; i < 8; i++)
        {
            vectorSecond.append(i);
        }
        NVector<int> result = vectorFirst - vectorSecond;
        QCOMPARE(result[0], -4);
        QCOMPARE(result[1], -4);
        QCOMPARE(result[2], -4);
    }

    void nVectorMultOneTest()
    {
        NVector<int> vectorFirst;
        for (int i = 1; i < 4; i++)
        {
            vectorFirst.append(i);
        }

        NVector<int> result = vectorFirst * 2;
        QCOMPARE(result[0], 2);
        QCOMPARE(result[1], 4);
        QCOMPARE(result[2], 6);
    }

    void nMetricVectorSumTest()
    {
        NVector<int> vectorFirstRow1;
        for (int i = 1; i < 4; i++)
        {
            vectorFirstRow1.append(i);
        }
        NVector<int> vectorSecondRow1;
        for (int i = 5; i < 8; i++)
        {
            vectorSecondRow1.append(i);
        }
        NVector<int> vectorFirstRow2;
        for (int i = 1; i < 4; i++)
        {
            vectorFirstRow2.append(i);
        }
        NVector<int> vectorSecondRow2;
        for (int i = 5; i < 8; i++)
        {
            vectorSecondRow2.append(i);
        }
        NVector<NVector<int> > firstRow;
        firstRow.append(vectorFirstRow1);
        firstRow.append(vectorSecondRow1);
        NVector<NVector<int> > secondRow;
        secondRow.append(vectorFirstRow2);
        secondRow.append(vectorSecondRow2);
        NVector<NVector <int> > result = firstRow + secondRow;
        QCOMPARE(result[0][0], 2);
        QCOMPARE(result[0][1], 4);
        QCOMPARE(result[0][2], 6);
        QCOMPARE(result[1][0], 10);
        QCOMPARE(result[1][1], 12);
        QCOMPARE(result[1][2], 14);
    }

    void nMetricVectorMinusTest()
    {
        NVector<int> vectorFirstRow1;
        for (int i = 1; i < 4; i++)
        {
            vectorFirstRow1.append(i);
        }
        NVector<int> vectorSecondRow1;
        for (int i = 5; i < 8; i++)
        {
            vectorSecondRow1.append(i);
        }
        NVector<int> vectorFirstRow2;
        for (int i = 1; i < 4; i++)
        {
            vectorFirstRow2.append(i);
        }
        NVector<int> vectorSecondRow2;
        for (int i = 5; i < 8; i++)
        {
            vectorSecondRow2.append(i);
        }
        NVector<NVector<int> > firstRow;
        firstRow.append(vectorFirstRow1);
        firstRow.append(vectorSecondRow1);
        NVector<NVector<int> > secondRow;
        secondRow.append(vectorFirstRow2);
        secondRow.append(vectorSecondRow2);
        NVector<NVector <int> > result = firstRow - secondRow;
        QCOMPARE(result[0][0], 0);
        QCOMPARE(result[0][1], 0);
        QCOMPARE(result[0][2], 0);
        QCOMPARE(result[1][0], 0);
        QCOMPARE(result[1][1], 0);
        QCOMPARE(result[1][2], 0);
    }

    void nMetricVectorMultiplyTest()
    {
        NVector<int> vectorFirstRow1;
        for (int i = 1; i < 4; i++)
        {
            vectorFirstRow1.append(i);
        }
        NVector<int> vectorSecondRow1;
        for (int i = 5; i < 8; i++)
        {
            vectorSecondRow1.append(i);
        }
        NVector<NVector<int> > firstRow;
        firstRow.append(vectorFirstRow1);
        firstRow.append(vectorSecondRow1);
        NVector<NVector <int> > result = firstRow * 2;
        QCOMPARE(result[0][0], 2);
        QCOMPARE(result[0][1], 4);
        QCOMPARE(result[0][2], 6);
        QCOMPARE(result[1][0], 10);
        QCOMPARE(result[1][1], 12);
        QCOMPARE(result[1][2], 14);
    }

    void nVectorNullTest()
    {
        NVector<int> vector;
        vector.append(0);
        QVERIFY(vector.isNull());
        vector.append(2);
        QVERIFY(!vector.isNull());
    }

    void nVectorCopyTest()
    {
        NVector<int> firstVector;
        firstVector.append(2);
        firstVector.append(5);
        NVector<int> secondVector(firstVector);
        QCOMPARE(secondVector[0], 2);
        QCOMPARE(secondVector[1], 5);
    }

};
