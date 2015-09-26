#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "VirusModel.h"
#include "LanNetwork.h"
#include "RandomGenerator.h"

class VirusModelTest : public QObject
{
    Q_OBJECT
public:
   explicit VirusModelTest(QObject *parent = 0) : QObject(parent)
    {}

private slots:
    void init()
    {
        network = new LanNetwork(4);
        model = new VirusModel(4, network);
        QStringList networkList;
        networkList.append("1 1 0 0");
        networkList.append("1 1 1 1");
        networkList.append("0 1 1 1");
        networkList.append("0 1 1 1");
        network->createFromQStringList(networkList);
        QStringList computers;
        computers.append("Linux");
        computers.append("Windows");
        computers.append("Windows");
        computers.append("MacOS");
        model->createFromQStringList(computers);
    }

    void testForcedInfection()
    {
        RandomGenerator::makeFake(35);
        model->makeInfectionStep();
        QVERIFY(model->findIfIsInfected(1));

    }

    void testTwoForcedInfections()
    {
        RandomGenerator::makeFake(35);
        model->makeInfectionStep();
        QVERIFY(model->findIfIsInfected(1));
        RandomGenerator::makeFake(20);
        model->makeInfectionStep();
        QVERIFY(model->findIfIsInfected(3));
    }

    void cleanup()
    {
        RandomGenerator::makeFake(0);
        delete model;    
    }

private:
    LanNetwork *network;
    VirusModel *model;
};
