#pragma once
#include "Computer.h"
#include "OS.h"
#include "OSSwitcher.h"
#include <QStringList>
#include <QString>
#include <QTextStream>
#include <iostream>
#include <QVector>
#include "LanNetwork.h"
#include "RandomGeneratorInterface.h"


/**
 * @brief The VirusModel class Model representing virus attack in lan network
 */
class VirusModel
{
public:
    VirusModel(int numberOfComputers, LanNetwork *network, RandomGeneratorInterface *generator);

    ~VirusModel();

    void createFromStdin();

    void createFromQStringList(const QStringList &list);

    /**
     * @brief makeInfectionStep All infected computer will try to infect
     * connected computers
     */
    void makeInfectionStep();

    void printOutStatus() const;

    bool findIfIsInfected(int idComputer) const;

private:
    bool isAbleToInfect(int idComputer);
    QVector<Computer> archive;
    int numberOfComputers;
    LanNetwork *network;
    RandomGeneratorInterface *generator;
};

