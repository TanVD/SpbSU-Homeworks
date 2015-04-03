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
    void onModuleButtonClicked();

    void onStatisticButtonClicked();

    void onExecuteButtonClicked();

private:
    Ui::HashTableUI *ui;
    HashTable* table;
};
