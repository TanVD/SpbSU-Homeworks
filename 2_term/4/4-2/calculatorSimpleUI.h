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
    void onArg1ValueChanged(int arg1);

    /**
     * @brief on_spinBox_2_valueChanged Sets second argument in calc object if spinbox was changed
     * @param arg1 Second argument
     */
    void onArg2ValueChanged(int arg1);

    /**
     * @brief on_comboBox_currentIndexChanged Sets operation if combo box was changed
     * @param index Index of operation
     */
    void onOperationCurrentIndexChanged(int index);

private:
    Ui::CalculatorSimpleUI *ui;
    /**
     * @brief calc
     */
    CalculatorSimple* calc;

};

