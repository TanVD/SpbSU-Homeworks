#pragma once
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QSignalMapper>
#include "modelTicTacToe.h"

namespace Ui {
class TicTacToeUI;
}

class TicTacToeUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToeUI(QWidget *parent = 0);
    ~TicTacToeUI();

private:
    Ui::TicTacToeUI *ui;
    QSignalMapper mapButtons;
    ModelTicTacToe* model;
    QPushButton** arrayOfButtons;
private slots:
    void mappedButtonAction(int);
};

