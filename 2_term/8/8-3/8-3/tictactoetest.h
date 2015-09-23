#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <modelTicTacToe.h>
#include <QPushButton>

class TicTacToeTest : public QObject
{
    Q_OBJECT
public:
    explicit TicTacToeTest(QObject *parent = 0) : QObject(parent)
    {}

private slots:
    void init()
    {
        arrayOfButtons3 = new QPushButton*[3]();
        for (int j = 0; j < 3; j++)
        {
            arrayOfButtons3[j] = new QPushButton[3]();
        }
        model3 = new ModelTicTacToe(arrayOfButtons3, 3);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arrayOfButtons3[i][j].setText("");
            }
        }
        arrayOfButtons2 = new QPushButton*[2]();
        for (int j = 0; j < 2; j++)
        {
            arrayOfButtons2[j] = new QPushButton[2]();
        }
        model2 = new ModelTicTacToe(arrayOfButtons2, 2);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arrayOfButtons2[i][j].setText("");
            }
        }

    }

    void testVerticalOWin()
    {
        arrayOfButtons3[0][0].setText("O");
        arrayOfButtons3[0][1].setText("O");
        arrayOfButtons3[0][2].setText("O");
        QVERIFY(model3->checkVictory(3));
        arrayOfButtons2[0][0].setText("O");
        arrayOfButtons2[0][1].setText("O");
        QVERIFY(model2->checkVictory(2));
    }

    void testHorizontalOWin()
    {
        arrayOfButtons3[0][0].setText("O");
        arrayOfButtons3[1][0].setText("O");
        arrayOfButtons3[2][0].setText("O");
        QVERIFY(model3->checkVictory(3));
        arrayOfButtons2[0][0].setText("O");
        arrayOfButtons2[1][0].setText("O");
        QVERIFY(model2->checkVictory(2));
    }

    void testVerticalXWin()
    {
        arrayOfButtons3[0][0].setText("X");
        arrayOfButtons3[0][1].setText("X");
        arrayOfButtons3[0][2].setText("X");
        QVERIFY(model3->checkVictory(3));
        arrayOfButtons2[0][0].setText("X");
        arrayOfButtons2[0][1].setText("X");
        QVERIFY(model2->checkVictory(2));
    }

    void testHorizontalXWin()
    {
        arrayOfButtons3[0][0].setText("X");
        arrayOfButtons3[1][0].setText("X");
        arrayOfButtons3[2][0].setText("X");
        QVERIFY(model3->checkVictory(3));
        arrayOfButtons2[0][0].setText("X");
        arrayOfButtons2[1][0].setText("X");
        QVERIFY(model2->checkVictory(2));
    }

    void testDiagonalOWin()
    {
        arrayOfButtons3[0][0].setText("O");
        arrayOfButtons3[1][1].setText("O");
        arrayOfButtons3[2][2].setText("O");
        QVERIFY(model3->checkVictory(3));
        arrayOfButtons2[0][0].setText("O");
        arrayOfButtons2[1][1].setText("O");
        QVERIFY(model2->checkVictory(2));
    }

    void testOtherDiagonalOWin()
    {
        arrayOfButtons3[0][2].setText("O");
        arrayOfButtons3[1][1].setText("O");
        arrayOfButtons3[2][0].setText("O");
        QVERIFY(model3->checkVictory(3));
        arrayOfButtons2[0][1].setText("O");
        arrayOfButtons2[1][0].setText("O");
        QVERIFY(model2->checkVictory(2));
    }

    void testDiagonalXWin()
    {
        arrayOfButtons3[0][0].setText("X");
        arrayOfButtons3[1][1].setText("X");
        arrayOfButtons3[2][2].setText("X");
        QVERIFY(model3->checkVictory(3));
        arrayOfButtons2[0][0].setText("X");
        arrayOfButtons2[1][1].setText("X");
        QVERIFY(model2->checkVictory(2));
    }

    void testOtherDiagonalXWin()
    {
        arrayOfButtons3[0][2].setText("X");
        arrayOfButtons3[1][1].setText("X");
        arrayOfButtons3[2][0].setText("X");
        QVERIFY(model3->checkVictory(3));
        arrayOfButtons2[0][1].setText("X");
        arrayOfButtons2[1][0].setText("X");
        QVERIFY(model2->checkVictory(2));
    }

    void testMakeMove()
    {
        model3->newMove(0);
        QString answer3 = "X";
        QCOMPARE(arrayOfButtons3[0][0].text(), answer3);
        model2->newMove(0);
        QString answer2 = "X";
        QCOMPARE(arrayOfButtons2[0][0].text(), answer2);
    }

    void testGetCurrentMove()
    {
        QString answer3 = "X";
        QCOMPARE(model3->currentMove(), answer3);
        QString answer2 = "X";
        QCOMPARE(model3->currentMove(), answer2);
    }


    void cleanup()
    {
        delete model3;
        for (int i = 0; i < 3; i++)
        {
            delete[] arrayOfButtons3[i];
        }
        delete[] arrayOfButtons3;
        delete model2;
        for (int i = 0; i < 2; i++)
        {
            delete[] arrayOfButtons2[i];
        }
        delete[] arrayOfButtons2;
    }
private:
    ModelTicTacToe* model3;
    QPushButton** arrayOfButtons3;
    ModelTicTacToe* model2;
    QPushButton** arrayOfButtons2;
};
