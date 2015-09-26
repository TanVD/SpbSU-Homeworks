#include "VirusModel.h"

VirusModel::VirusModel(int numberOfComputers, LanNetwork *network)
    : numberOfComputers(numberOfComputers), network(network)
{}

VirusModel::~VirusModel()
{}

void VirusModel::createFromStdin()
{
    QTextStream consoleInput(stdin);
    for (int i = 0; i < numberOfComputers; i++)
    {
        std::cout << "Enter os of " << i + 1 << " computer:\n";
        QString newInput = consoleInput.readLine();
        archive.append(Computer(OS(newInput)));
    }
    archive[0].infectForced();
}

void VirusModel::createFromQStringList(const QStringList &list)
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
            infectionQueue.append(network->getConnectedComputers(i));
        }
    }
    foreach(int computer, infectionQueue)
    {
        archive[computer].tryToInfect();
    }
}

void VirusModel::printOutStatus() const
{
    for (int i = 0; i < numberOfComputers; i++)
    {
        std::cout << i << " ";
        if (archive[i].isInfected())
        {
            std::cout << "infected";
        }
        else
        {
            std::cout << "not infected";
        }
        std::cout << "\n";
    }
}

bool VirusModel::findIfIsInfected(int idComputer) const
{
    return archive[idComputer].isInfected();
}

bool VirusModel::isAbleToInfect(int idComputer)
{
    if (archive[idComputer].isInfected())
    {
        QVector<int> computersConnected = network->getConnectedComputers(idComputer);
        foreach (int computer, computersConnected)
        {
            if (!archive[computer].isInfected())
            {
                return true;
            }
        }
    }
    return false;
}

