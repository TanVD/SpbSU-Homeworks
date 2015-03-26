#include "calculatorSimpleUI.h"
#include "ui_calculatorSimpleUI.h"
#include "calculatorSimple.h"

CalculatorSimpleUI::CalculatorSimpleUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorSimpleUI),
    calc(new CalculatorSimple())
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(onArg1ValueChanged(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(onArg2ValueChanged(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onOperationCurrentIndexChanged(int)));
}

CalculatorSimpleUI::~CalculatorSimpleUI()
{
    delete calc;
    delete ui;
}

void CalculatorSimpleUI::onArg1ValueChanged(int arg1)
{
    calc->setFirstArgument(arg1);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

void CalculatorSimpleUI::onArg2ValueChanged(int arg1)
{
    calc->setSecondArgument(arg1);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

void CalculatorSimpleUI::onOperationCurrentIndexChanged(int index)
{
    calc->setOperation(index);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

