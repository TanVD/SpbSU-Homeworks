#include "hashtableui.h"
#include "ui_hashtableui.h"
#include "QString"
#include "QMessageBox"

HashTableUI::HashTableUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HashTableUI),
    table(new HashTable(10000))
{
    ui->setupUi(this);
}

HashTableUI::~HashTableUI()
{
    delete table;
    delete ui;
}

void HashTableUI::on_moduleButton_clicked()
{
    table->changeModule(ui->moduleSpinBox->text().toInt());
}


void HashTableUI::on_statisticButton_clicked()
{
    QMessageBox* box = new QMessageBox(this);
    QString string = ("Total cells: " + QString::number(table->getModule()) + "\nLoad factor: " + QString::number(table->getLoadFactor()) +
                      "\nLargest collision: " + QString::number(table->getLargestCollision()));
    box->setText(string);
    box->setWindowTitle("Statistic");
    box->setIcon(QMessageBox::Information);
    box->show();
}

void HashTableUI::on_executeButton_clicked()
{
    int index = ui->comboBox->currentIndex();
    switch (index)
    {
    case 1:
    {
         table->addValue(ui->valueLineEdit->text().toInt());
         break;
    }
    case 2:
    {
        if (!table->removeValue(ui->valueLineEdit->text().toInt()))
        {
            QMessageBox* box = new QMessageBox(this);
            box->setText("Not found digit");
            box->setWindowTitle("Warning");
            box->setIcon(QMessageBox::Warning);
            box->show();
        }
        break;
    }
    case 3:
    {
        if (table->findValue(ui->valueLineEdit->text().toInt()))
        {
            QMessageBox* box = new QMessageBox(this);
            box->setText("This value exists in hashtable");
            box->setWindowTitle("Information");
            box->setIcon(QMessageBox::Information);
            box->show();
        }
        else
        {
            QMessageBox* box = new QMessageBox(this);
            box->setText("This value doesn't exist in hashtable");
            box->setWindowTitle("Information");
            box->setIcon(QMessageBox::Information);
            box->show();
        }
        break;
    }
    }







}
