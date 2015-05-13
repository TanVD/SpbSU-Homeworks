#include "ticTacToeUI.h"
#include "ui_ticTacToeUI.h"
#include <QInputDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

TicTacToeUI::TicTacToeUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToeUI)
{
    ui->setupUi(this);
    QInputDialog inputFromUser(this);
    int lengthOfField = inputFromUser.getInt(this, "Input", "Input length of field");

    arrayOfButtons = new QPushButton*[lengthOfField]();
    for (int j = 0; j < lengthOfField; j++)
    {
        arrayOfButtons[j] = new QPushButton[lengthOfField]();
    }

    model = new ModelTicTacToe(arrayOfButtons, lengthOfField);

    for (int i = 0; i < lengthOfField; i++)
    {
        for (int j = 0; j < lengthOfField; j++)
        {
            arrayOfButtons[i][j].setText("");
            connect(&arrayOfButtons[i][j], SIGNAL(clicked()), &mapButtons, SLOT(map()));
            mapButtons.setMapping(&arrayOfButtons[i][j], i * lengthOfField + j);
            //i - row, j - column
        }
    }
    connect(&mapButtons, SIGNAL(mapped(int)), this, SLOT(mappedButtonAction(int)));

    for (int i = 0; i < lengthOfField; i++)
    {
        for (int j = 0; j < lengthOfField; j++)
        {
            ui->gridLayout->addWidget(&arrayOfButtons[i][j], i, j);
        }
    }

}

TicTacToeUI::~TicTacToeUI()
{
    delete ui;
}

void TicTacToeUI::mappedButtonAction(int value)
{
    QString currentMove = model->currentMove();
    model->newMove(value);
    if (model->checkVictory(3))
    {
        ui->whoWonLabel->setText(currentMove + " won!");
        model->makeAllDisabled();
    }
}
