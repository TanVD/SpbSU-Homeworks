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
        QPushButton x;
        arrayOfButtons = new QPushButton*[3]();
        for (int j = 0; j < 3; j++)
        {
            arrayOfButtons[j] = new QPushButton[3]();
        }
        model = new ModelTicTacToe(arrayOfButtons, 3);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arrayOfButtons[i][j].setText("");
            }
        }
    }

    void testVerticalOWin()
    {
        arrayOfButtons[0][0].setText("O");
        arrayOfButtons[0][1].setText("O");
        arrayOfButtons[0][2].setText("O");
        QVERIFY(model->checkVictory(3));
    }

    void testHorizontalOWin()
    {
        arrayOfButtons[0][0].setText("O");
        arrayOfButtons[1][0].setText("O");
        arrayOfButtons[2][0].setText("O");
        QVERIFY(model->checkVictory(3));
    }

    void testVerticalXWin()
    {
        arrayOfButtons[0][0].setText("X");
        arrayOfButtons[0][1].setText("X");
        arrayOfButtons[0][2].setText("X");
        QVERIFY(model->checkVictory(3));
    }

    void testHorizontalXWin()
    {
        arrayOfButtons[0][0].setText("X");
        arrayOfButtons[1][0].setText("X");
        arrayOfButtons[2][0].setText("X");
        QVERIFY(model->checkVictory(3));
    }

    void testDiagonalOWin()
    {
        arrayOfButtons[0][0].setText("O");
        arrayOfButtons[1][1].setText("O");
        arrayOfButtons[2][2].setText("O");
        QVERIFY(model->checkVictory(3));
    }

    void testOtherDiagonalOWin()
    {
        arrayOfButtons[0][2].setText("O");
        arrayOfButtons[1][1].setText("O");
        arrayOfButtons[2][0].setText("O");
        QVERIFY(model->checkVictory(3));
    }

    void testDiagonalXWin()
    {
        arrayOfButtons[0][0].setText("X");
        arrayOfButtons[1][1].setText("X");
        arrayOfButtons[2][2].setText("X");
        QVERIFY(model->checkVictory(3));
    }

    void testOtherDiagonalXWin()
    {
        arrayOfButtons[0][2].setText("X");
        arrayOfButtons[1][1].setText("X");
        arrayOfButtons[2][0].setText("X");
        QVERIFY(model->checkVictory(3));
    }

    void testMakeMove()
    {
        model->newMove(0);
        QString answer = "X";
        QCOMPARE(arrayOfButtons[0][0].text(), answer);
    }

    void testGetCurrentMove()
    {
        QString answer = "X";
        QCOMPARE(model->currentMove(), answer);
    }

    void cleanup()
    {
        delete model;
        for (int i = 0; i < 3; i++)
        {
            delete[] arrayOfButtons[i];
        }
        delete[] arrayOfButtons;
    }
private:
    ModelTicTacToe* model;
    QPushButton** arrayOfButtons;
};
