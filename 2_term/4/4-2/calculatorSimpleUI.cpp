#include "calculatorSimpleUI.h"
#include "ui_calculatorSimpleUI.h"
#include "calculatorSimple.h"

CalculatorSimpleUI::CalculatorSimpleUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorSimpleUI),
    calc(new CalculatorSimple())
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(on_arg1_valueChanged(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(on_arg2_valueChanged(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_operation_currentIndexChanged(int)));
}

CalculatorSimpleUI::~CalculatorSimpleUI()
{
    delete calc;
    delete ui;
}

void CalculatorSimpleUI::on_arg1_valueChanged(int arg1)
{
    calc->setFirstArgument(arg1);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

void CalculatorSimpleUI::on_arg2_valueChanged(int arg1)
{
    calc->setSecondArgument(arg1);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

void CalculatorSimpleUI::on_operation_currentIndexChanged(int index)
{
    calc->setOperation(index);
    ui->lineEdit->setText(QVariant(calc->getResult()).toString());
}

