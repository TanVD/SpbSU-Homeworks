#include <QCoreApplication>
#include "ComputerList.h"
#include "LanNetwork.h"
#include <time.h>
#include <QtGlobal>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QTextStream consoleOutput(stdout); // перехватывает поток?
    LanNetwork network(4, 4);
    consoleOutput << "Enter your network as a connectivity matrix: \n";
    network.createFromStdin();
    ComputerList list(4, network);
    consoleOutput << "Enter OS names of your computers: \n";
    list.createFromStdin();
    int steps = 5;
    qsrand(time(NULL));
    for (int i = 0; i < steps; i++)
    {
        consoleOutput << "Step" << steps << "of experiment: \n";
        int computerToInfect = qrand() % 4;
        int nearestAbleToInfect = list.findNearestAbleToInfect(computerToInfect);
        if (nearestAbleToInfect == -1)
        {
            consoleOutput << "Every computer is infected \n";
            break;
        }
        list.infectComputer(nearestAbleToInfect);
        list.printOutStatus();

    }
}

