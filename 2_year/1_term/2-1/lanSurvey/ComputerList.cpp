#include "ComputerList.h"

ComputerList::ComputerList(int numberOfComputers, LanNetwork network)
    : numberOfComputers(numberOfComputers), network(network)
{}

void ComputerList::createFromStdin()
{

    for (int i = 0; i < numberOfComputers; i++)
    {
        QTextStream consoleInput(stdin);
        QTextStream consoleOutput(stdout);
        consoleOutput << "Enter os of " << i + 1 << "computer:\n";
        QString newInput = consoleInput.readLine();
        archive.append(Computer(OS(newInput)));
    }
    archive[0].infectForced();
}

bool ComputerList::infectComputer(int idOfComputer)
{
    return archive[idOfComputer].tryToInfect();
}

int ComputerList::findNearestAbleToInfect(int idOfComputer)
{
    for (int i = 0; i < numberOfComputers / 2 + 1; i++)
    {
        int firstTry = ( idOfComputer + i + 4) % numberOfComputers;
        if (isAbleToInfect(firstTry))
            return firstTry;

        int secondTry = (idOfComputer - i + 4) % numberOfComputers;
        if (isAbleToInfect(secondTry))
            return secondTry;
    }
    return -1;
}

void ComputerList::printOutStatus()
{
    QTextStream consoleOutput(stdout);
    for (int i = 0; i < numberOfComputers; i++)
    {
        consoleOutput << i << " ";
        if (archive[i].isInfected())
            consoleOutput << "infected";
        else
            consoleOutput << "not infected";
        consoleOutput << "\n";
    }
}

bool ComputerList::isAbleToInfect(int idOfComputer)
{
    if (!archive[idOfComputer].isInfected())
    {
        QVector<int> computersConnected = network.getConnectedComputers(idOfComputer);
        for (int j = 0; j < computersConnected.length(); j++)
        {
            if (archive[computersConnected[j]].isInfected())
                return true;
        }
    }
    return false;
}

