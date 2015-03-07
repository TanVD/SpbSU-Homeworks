#ifndef CALCULATORSIMPLEUI_H
#define CALCULATORSIMPLEUI_H

#include <QMainWindow>

namespace Ui {
class CalculatorSimpleUI;
}

class CalculatorSimpleUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorSimpleUI(QWidget *parent = 0);
    ~CalculatorSimpleUI();

private:
    Ui::CalculatorSimpleUI *ui;
};

#endif // CALCULATORSIMPLEUI_H
