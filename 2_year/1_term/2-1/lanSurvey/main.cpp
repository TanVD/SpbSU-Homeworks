#include <QCoreApplication>
#include "VirusModel.h"
#include "LanNetwork.h"
#include <iostream>
#include <time.h>
#include <QtGlobal>
#include <QTextStream>
#include <QTest>
#include "virusmodeltests.h"

int main(int argc, char *argv[])
{
    VirusModelTest test;
    QTest::qExec(&test);
    LanNetwork network(4, 4);
    std::cout << "Enter your network as a connectivity matrix: \n";
    network.createFromStdin();
    VirusModel list(4, network);
    std::cout << "Enter OS names of your computers: \n";
    list.createFromStdin();
    int steps = 5;
    qsrand(time(NULL));
    for (int i = 0; i < steps; i++)
    {
        std::cout << "Step " << i + 1 << " of experiment: \n";
        list.makeInfectionStep();
        list.printOutStatus();
    }
}

