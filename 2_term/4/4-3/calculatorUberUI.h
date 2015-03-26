#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QString>

namespace Ui {
class CalculatorUberUI;
}

class CalculatorUberUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorUberUI(QWidget *parent = 0);
    ~CalculatorUberUI();

private:
    Ui::CalculatorUberUI *ui;
    QSignalMapper* buttons;
    QString equation;

private slots:
    void newChar(int value);
};

