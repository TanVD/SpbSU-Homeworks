#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "VirusModel.h"
#include "LanNetwork.h"
#include "RandomGeneratorFake.h"

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
        model = new VirusModel(4, network, &generator);
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
        generator.makeFake(35);
        model->makeInfectionStep();
        QVERIFY(model->findIfIsInfected(1));
    }

    void testTwoForcedInfections()
    {
        generator.makeFake(35);
        generator.makeFake(20);
        model->makeInfectionStep();
        QVERIFY(model->findIfIsInfected(1));
        model->makeInfectionStep();
        QVERIFY(model->findIfIsInfected(3));
    }

    void cleanup()
    {
        generator.resetMakeFakeList();
        delete model;    
    }

private:
    LanNetwork *network;
    VirusModel *model;
    RandomGeneratorFake generator;
};
