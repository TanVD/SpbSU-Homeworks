#pragma once
#include "Computer.h"
#include "OS.h"
#include <QStringList>
#include <QString>
#include <QTextStream>
#include <iostream>
#include <QVector>
#include "LanNetwork.h"

class VirusModel
{
public:
    VirusModel(int numberOfComputers, LanNetwork network);
    void createFromStdin();
    void createFromQStringList(QStringList list);
    void makeInfectionStep();
    void printOutStatus();
    bool findIfIsInfected(int idOfComputer);

private:
    bool isAbleToInfect(int idOfComputer);
    QVector<Computer> archive;
    int numberOfComputers;
    LanNetwork network;

};

