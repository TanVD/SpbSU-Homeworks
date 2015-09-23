#pragma once
#include "Computer.h"
#include "OS.h"
#include <QStringList>
#include <QString>
#include <QTextStream>
#include <QVector>
#include "LanNetwork.h"

class ComputerList
{
public:
    ComputerList(int numberOfComputers, LanNetwork network);
    void createFromStdin();
    bool infectComputer(int idOfComputer);
    int findNearestAbleToInfect(int idOfComputer);
    void printOutStatus();

private:
    bool isAbleToInfect(int idOfComputer);
    QVector<Computer> archive;
    int numberOfComputers;
    LanNetwork network;

};

