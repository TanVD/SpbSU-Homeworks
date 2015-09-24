#pragma once
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QVector>

class LanNetwork
{
public:
    LanNetwork(int columns, int rows);
    void createFromStdin();
    void createFromQStringList(QStringList list);
    QVector<int> getConnectedComputers(int idOfComputer);
private:
    bool** networkMatrix;
    int columns;
    int rows;
};

