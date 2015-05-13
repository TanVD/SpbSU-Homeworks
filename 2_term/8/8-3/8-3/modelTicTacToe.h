#pragma once
#include <QPushButton>
#include <QSignalMapper>

/**
 * @brief The ModelTicTacToe class Incapsulate busniess logic
 */
class ModelTicTacToe
{
public:
    ModelTicTacToe(QPushButton **&arrayOfButtons, int lengthOfField);
    /**
     * @brief checkVictory Checks if model contains line of one symbol length of conditionLength
     * @param conditionLength Length of line to win
     * @return True if model contains line of one symbol length of conditionLength; otherwise false
     */
    bool checkVictory(int conditionLength);

    /**
     * @brief newMove Makes new move in cell according to value
     * @param value Value containing row and column
     */
    void newMove(int value);

    /**
     * @brief currentMove Returns symbol of new move
     * @return QString representing symbol of new move
     */
    QString currentMove();

    /**
     * @brief makeAllDisabled Makes all models pushbuttons disabled
     */
    void makeAllDisabled();

private:
    QPushButton** arrayOfButtons;
    bool move;
    int lengthOfField;

};

