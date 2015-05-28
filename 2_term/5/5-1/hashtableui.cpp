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
    connect(ui->moduleButton, SIGNAL(clicked()), this, SLOT(onModuleButtonClicked()));
    connect(ui->statisticButton, SIGNAL(clicked()), this, SLOT(onStatisticButtonClicked()));
    connect(ui->executeButton, SIGNAL(clicked()), this, SLOT(onExecuteButtonClicked()));
}

HashTableUI::~HashTableUI()
{
    delete table;
    delete ui;
}

void HashTableUI::onModuleButtonClicked()
{
    table->changeModule(ui->moduleSpinBox->text().toInt());
}


void HashTableUI::onStatisticButtonClicked()
{
    QMessageBox* box = new QMessageBox(this);
    QString string = ("Total cells: " + QString::number(table->getModule()) + "\nLoad factor: " + QString::number(table->getLoadFactor()) +
                      "\nLargest collision: " + QString::number(table->getLargestCollision()));
    box->setText(string);
    box->setWindowTitle("Statistic");
    box->setIcon(QMessageBox::Information);
    box->show();
}

enum commands
{
    addCommand = 1,
    removeCommand = 2,
    findCommand = 3
};

void HashTableUI::onExecuteButtonClicked()
{
    int command = ui->comboBox->currentIndex();
    switch (command)
    {
    case addCommand:
    {
        table->addValue(ui->valueLineEdit->text().toInt());
        break;
    }
    case removeCommand:
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
    case findCommand:
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
