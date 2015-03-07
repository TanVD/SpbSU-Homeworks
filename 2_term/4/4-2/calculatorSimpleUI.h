#pragma once

#include <QMainWindow>
#include "calculatorSimple.h"

namespace Ui {
class CalculatorSimpleUI;
}

class CalculatorSimpleUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorSimpleUI(QWidget *parent = 0);
    ~CalculatorSimpleUI();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::CalculatorSimpleUI *ui;
    CalculatorSimple* calc;

};

