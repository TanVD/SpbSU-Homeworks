#include "modelTicTacToe.h"

ModelTicTacToe::ModelTicTacToe(QPushButton **&arrayOfButtons, int lengthOfField) : arrayOfButtons(arrayOfButtons), move(true), lengthOfField(lengthOfField)
{
}

bool ModelTicTacToe::checkVictory(int conditionLength)
{
    for (int i = 0; i < lengthOfField; i++)
    {
        int j = 0;
        int counter = 0;
        QString symbol = "Y";
        while (j < lengthOfField)
        {
            if (arrayOfButtons[i][j].text() == symbol)
            {
                counter++;
            }
            else
            {
                counter = 1;
                symbol = arrayOfButtons[i][j].text();
            }
            if (counter == conditionLength)
            {
                if (symbol != "")
                return true;
            }
            j++;
        }
    }

    for (int i = 0; i < lengthOfField; i++)
    {
        int j = 0;
        int counter = 0;
        QString symbol = "Y";
        while (j < lengthOfField)
        {
            if (arrayOfButtons[j][i].text() == symbol)
            {
                counter++;
            }
            else
            {
                counter = 1;
                symbol = arrayOfButtons[j][i].text();
            }
            if (counter == conditionLength)
            {
                if (symbol != "")
                return true;
            }
            j++;
        }
    }

    for (int i = 0; i < lengthOfField; i++)
    {
        int j = 0;
        int k = i;
        int counter = 0;
        QString symbol = "Y";
        while (j <= i)
        {
            if (arrayOfButtons[j][k].text() == symbol)
            {
                counter++;
            }
            else
            {
                counter = 1;
                symbol = arrayOfButtons[j][k].text();
            }
            if (counter == conditionLength)
            {
                if (symbol != "")
                return true;
            }
            j++;
            k--;
        }
    }

    for (int i = lengthOfField - 1; i >= 0; i--)
    {
        int j = 0;
        int k = i;
        int counter = 0;
        QString symbol = "Y";
        while (k <= lengthOfField - 1)
        {
            if (arrayOfButtons[j][k].text() == symbol)
            {
                counter++;
            }
            else
            {
                counter = 1;
                symbol = arrayOfButtons[j][k].text();
            }
            if (counter == conditionLength)
            {
                if (symbol != "")
                return true;
            }
            j++;
            k++;
        }
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

