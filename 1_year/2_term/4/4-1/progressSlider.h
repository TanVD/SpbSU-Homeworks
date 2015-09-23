#ifndef PROGRESSSLIDER_H
#define PROGRESSSLIDER_H

#include <QMainWindow>

namespace Ui {
class ProgressSlider;
}

class ProgressSlider : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProgressSlider(QWidget *parent = 0);
    ~ProgressSlider();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::ProgressSlider *ui;
};

#endif // PROGRESSSLIDER_H
