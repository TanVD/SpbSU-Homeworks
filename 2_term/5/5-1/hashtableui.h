#pragma once
#include "hashTable.h"

#include <QMainWindow>

namespace Ui {
class HashTableUI;
}

class HashTableUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit HashTableUI(QWidget *parent = 0);
    ~HashTableUI();

private slots:
    void on_moduleButton_clicked();

    void on_statisticButton_clicked();

    void on_executeButton_clicked();

private:
    Ui::HashTableUI *ui;
    HashTable* table;
};
