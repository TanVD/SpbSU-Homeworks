#include "VirusModel.h"

VirusModel::VirusModel(int numberOfComputers, LanNetwork *network, RandomGeneratorInterface *generator)
    : numberOfComputers(numberOfComputers), network(network), generator(generator)
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
        archive.append(Computer(OSSwitcher::getOS(newInput), generator));
    }
    archive[0].infectForced();
}

void VirusModel::createFromQStringList(const QStringList &list)
{
    foreach (const QString &name, list)
    {
        archive.append(Computer(OSSwitcher::getOS(name), generator));
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

