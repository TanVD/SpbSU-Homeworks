#include "modelTicTacToe.h"

ModelTicTacToe::ModelTicTacToe(QPushButton **&arrayOfButtons, int lengthOfField) : arrayOfButtons(arrayOfButtons), move(true), lengthOfField(lengthOfField)
{
}

bool ModelTicTacToe::lineChecking(bool horizontal, int length, int conditionLength)
{
    for (int i = 0; i < length; i++)
    {
        int j = 0;
        int counter = 0;
        QString symbol = "Y";
        while (j < length)
        {
            int z = i;
            int k = j;
            if (!horizontal)
            {
                z = j;
                k = i;
            }
            if (arrayOfButtons[z][k].text() == symbol)
            {
                counter++;
            }
            else
            {
                counter = 1;
                symbol = arrayOfButtons[z][k].text();
            }
            if (counter == conditionLength)
            {
                if (symbol != "")
                return true;
            }
            j++;
        }
    }
    return false;
}

bool ModelTicTacToe::diagonalChecking(bool mainDiagonal, int length, int conditionLength)
{
    for (int i = 0; i < length; i++)
    {
        int j = 0;
        int k = i;
        if (!mainDiagonal)
        {
            k = 0;
            j = i;
        }
        int counter = 0;
        QString symbol = "Y";
        int border = i;
        if (!mainDiagonal)
        {
            border = lengthOfField - 1;
        }
        while (j <= border)
        {
            int z = j;
            int y = k;
            if (!mainDiagonal)
            {
                z = k;
                y = j;
            }
            if (arrayOfButtons[z][y].text() == symbol)
            {
                counter++;
            }
            else
            {
                counter = 1;
                symbol = arrayOfButtons[z][y].text();
            }
            if (counter == conditionLength)
            {
                if (symbol != "")
                return true;
            }
            j++;
            if (mainDiagonal)
            {
                k--;
            }
            else
            {
                k++;
            }
        }
    }
    return false;
}

bool ModelTicTacToe::checkVictory(int conditionLength)
{
    if (lineChecking(true, lengthOfField, conditionLength) || lineChecking(false, lengthOfField, conditionLength))
    {
        return true;
    }

    if (diagonalChecking(true, lengthOfField, conditionLength) || diagonalChecking(false, lengthOfField, conditionLength))
    {
        return true;
    }
    return false;
}

void ModelTicTacToe::newMove(int value)
{
    QString symbol = currentMove();
    arrayOfButtons[value / lengthOfField][value % lengthOfField].setText(symbol);
    arrayOfButtons[value / lengthOfField][value % lengthOfField].setEnabled(false);
    move = !move;
}

QString ModelTicTacToe::currentMove()
{
    if (move)
    {
        return "X";
    }
    else
    {
        return "O";
    }
}

void ModelTicTacToe::makeAllDisabled()
{
    for (int i = 0; i < lengthOfField; i++)
    {
        for (int j = 0; j < lengthOfField; j++)
        {
            arrayOfButtons[i][j].setEnabled(false);
        }
    }
}

