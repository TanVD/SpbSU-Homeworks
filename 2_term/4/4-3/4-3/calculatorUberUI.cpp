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
    buttons->setMapping(ui->number0, '0');
    buttons->setMapping(ui->number1, '1');
    buttons->setMapping(ui->number2, '2');
    buttons->setMapping(ui->number3, '3');
    buttons->setMapping(ui->number4, '4');
    buttons->setMapping(ui->number5, '5');
    buttons->setMapping(ui->number6, '6');
    buttons->setMapping(ui->number7, '7');
    buttons->setMapping(ui->number8, '8');
    buttons->setMapping(ui->number9, '9');
    buttons->setMapping(ui->dot, '.');
    buttons->setMapping(ui->operationDivide, '/');
    buttons->setMapping(ui->operationMultiply, '*');
    buttons->setMapping(ui->operationEqual, '=');
    buttons->setMapping(ui->operationMinus, '-');
    buttons->setMapping(ui->operationPlus, '+');
    connect(ui->number0, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number1, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number2, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number3, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number4, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number5, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number6, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number7, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number8, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->number9, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->dot, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->operationPlus, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->operationMinus, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->operationDivide, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->operationMultiply, SIGNAL(clicked()), buttons, SLOT(map()));
    connect(ui->operationEqual, SIGNAL(clicked()), buttons, SLOT(map()));
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
        ui->lineEdit->setText(QVariant(calc->returnResult()).toString());
        equation = QVariant(calc->returnResult()).toString();
    }
}
