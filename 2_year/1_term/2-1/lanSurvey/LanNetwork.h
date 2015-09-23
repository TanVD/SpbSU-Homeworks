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
    QVector<int> getConnectedComputers(int idOfComputer);
private:
    bool** networkMatrix;
    int columns;
    int rows;
};

