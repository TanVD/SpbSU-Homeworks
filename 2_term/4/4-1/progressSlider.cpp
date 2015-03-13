#include "progressSlider.h"
#include "ui_progressSlider.h"

ProgressSlider::ProgressSlider(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProgressSlider)
{
    ui->setupUi(this);
}

ProgressSlider::~ProgressSlider()
{
    delete ui;
}

void ProgressSlider::on_horizontalSlider_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}
