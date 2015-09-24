#include "VirusModel.h"

VirusModel::VirusModel(int numberOfComputers, LanNetwork network)
    : numberOfComputers(numberOfComputers), network(network)
{}

void VirusModel::createFromStdin()
{
    for (int i = 0; i < numberOfComputers; i++)
    {
        QTextStream consoleInput(stdin);
        std::cout << "Enter os of " << i + 1 << "computer:\n";
        QString newInput = consoleInput.readLine();
        archive.append(Computer(OS(newInput)));
    }
    archive[0].infectForced();
}

void VirusModel::createFromQStringList(QStringList list)
{
    foreach (QString name, list)
    {
        archive.append(Computer(OS(name)));
    }
    archive[0].infectForced();
}

void VirusModel::makeInfectionStep()
{
    QVector<int> infectionQueue;
    for (int i = 0; i < numberOfComputers ; i++)
    {
        if (isAbleToInfect(i))
        {
            infectionQueue.append(network.getConnectedComputers(i));
        }
    }
    foreach(int computer, infectionQueue)
    {
        archive[computer].tryToInfect();
    }
}

void VirusModel::printOutStatus()
{
    for (int i = 0; i < numberOfComputers; i++)
    {
        std::cout << i << " ";
        if (archive[i].isInfected())
            std::cout << "infected";
        else
            std::cout << "not infected";
        std::cout << "\n";
    }
}

bool VirusModel::findIfIsInfected(int idOfComputer)
{
    return archive[idOfComputer].isInfected();
}

bool VirusModel::isAbleToInfect(int idOfComputer)
{
    if (archive[idOfComputer].isInfected())
    {
        QVector<int> computersConnected = network.getConnectedComputers(idOfComputer);
        foreach (int computer, computersConnected)
        {
            if (!archive[computer].isInfected())
                return true;
        }
    }
    return false;
}

