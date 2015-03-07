#include "calculatorSimpleUI.h"
#include "ui_calculatorSimpleUI.h"
#include "calculatorSimple.h"

CalculatorSimpleUI::CalculatorSimpleUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorSimpleUI),
    calc(new CalculatorSimple())
{
    ui->setupUi(this);
}

CalculatorSimpleUI::~CalculatorSimpleUI()
{
    delete calc;
    delete ui;
}

void CalculatorSimpleUI::on_spinBox_valueChanged(int arg1)
{
    calc->setFirstArgument(arg1);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

void CalculatorSimpleUI::on_spinBox_2_valueChanged(int arg1)
{
    calc->setSecondArgument(arg1);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

void CalculatorSimpleUI::on_comboBox_currentIndexChanged(int index)
{
    calc->setOperation(index);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

