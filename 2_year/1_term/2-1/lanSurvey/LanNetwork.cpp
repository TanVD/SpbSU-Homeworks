#include "LanNetwork.h"


LanNetwork::LanNetwork(int numberOfComputers) :
    columns(numberOfComputers), rows(numberOfComputers)
{
    networkMatrix =  new bool*[rows];
    for (int i = 0; i < rows; i++)
    {
        networkMatrix[i] = new bool[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            networkMatrix[i][j] = false;
        }
    }
}

LanNetwork::~LanNetwork()
{
    for (int i = 0; i < columns; i++)
    {
        delete[] networkMatrix[i];
    }
    delete[] networkMatrix;
}

QVector<int> LanNetwork::getConnectedComputers(int idOfComputer) const
{
    QVector<int> connectedComputers;
    for (int i = 0; i < rows; i++)
    {
        if (networkMatrix[i][idOfComputer])
        {
            connectedComputers.append(i);
        }
    }
    return connectedComputers;
}

void LanNetwork::createFromStdin()
{
    QTextStream consoleInput(stdin);
    for (int i = 0; i < rows; i++)
    {
        QString newInput = consoleInput.readLine();
        QStringList numbers = newInput.split(" ");
        for (int j = 0; j < numbers.length(); j++)
        {
            networkMatrix[i][j] = numbers[j].toInt();
        }
    }
}

void LanNetwork::createFromQStringList(const QStringList &list)
{
    for (int i = 0; i < rows; i++)
    {
        QString newInput = list[i];
        QStringList numbers = newInput.split(" ");
        for (int j = 0; j < numbers.length(); j++)
        {
            networkMatrix[i][j] = numbers[j].toInt();
        }
    }
}

