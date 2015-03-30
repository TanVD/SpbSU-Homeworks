#include "calculatorUberUI.h"
#include "ui_calculatorUberUI.h"
#include <QSignalMapper>
#include "calculator.h"

CalculatorUberUI::CalculatorUberUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorUberUI)
{
    ui->setupUi(this);
    buttons = new QSignalMapper(this);
    QPushButton *pushButtons[16];
    pushButtons[0] = ui->number0;
    pushButtons[1] = ui->number1;
    pushButtons[2] = ui->number2;
    pushButtons[3] = ui->number3;
    pushButtons[4] = ui->number4;
    pushButtons[5] = ui->number5;
    pushButtons[6] = ui->number6;
    pushButtons[7] = ui->number7;
    pushButtons[8] = ui->number8;
    pushButtons[9] = ui->number9;
    pushButtons[10] = ui->dot;
    pushButtons[11] = ui->operationDivide;
    pushButtons[12] = ui->operationEqual;
    pushButtons[13] = ui->operationMinus;
    pushButtons[14] = ui->operationMultiply;
    pushButtons[15] = ui->operationPlus;
    for (int i = 0; i < 10; i++)
    {
        buttons->setMapping(pushButtons[i], '0' + i);
    }
    buttons->setMapping(ui->dot, '.');
    buttons->setMapping(ui->operationDivide, '/');
    buttons->setMapping(ui->operationMultiply, '*');
    buttons->setMapping(ui->operationEqual, '=');
    buttons->setMapping(ui->operationMinus, '-');
    buttons->setMapping(ui->operationPlus, '+');
    for (int i = 0; i < 16; i++)
    {
        connect(pushButtons[i], SIGNAL(clicked()), buttons, SLOT(map()));
    }
    connect(buttons, SIGNAL(mapped(int)), this, SLOT(newChar(int)));
}

CalculatorUberUI::~CalculatorUberUI()
{
    delete ui;
}

void CalculatorUberUI::newChar(int value)
{
    if (value != '=')
    {
        equation.push_back(value);
        ui->lineEdit->setText(equation);
    }
    else
    {
        Calculator* calc = new Calculator();
        calc->calculate(ui->lineEdit->text(), ui->lineEdit->text().length());
        ui->lineEdit->setText(QString::number(calc->returnResult()));
        equation = QString::number(calc->returnResult());
    }
}
