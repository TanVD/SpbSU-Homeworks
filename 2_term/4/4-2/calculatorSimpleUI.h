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
    /**
     * @brief on_spinBox_valueChanged Sets first argument in calc object if spinbox was changed
     * @param arg1 First argument
     */
    void on_arg1_valueChanged(int arg1);

    /**
     * @brief on_spinBox_2_valueChanged Sets second argument in calc object if spinbox was changed
     * @param arg1 Second argument
     */
    void on_arg2_valueChanged(int arg1);

    /**
     * @brief on_comboBox_currentIndexChanged Sets operation if combo box was changed
     * @param index Index of operation
     */
    void on_operation_currentIndexChanged(int index);

private:
    Ui::CalculatorSimpleUI *ui;
    /**
     * @brief calc
     */
    CalculatorSimple* calc;

};

