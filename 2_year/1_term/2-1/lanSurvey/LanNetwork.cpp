#include "LanNetwork.h"


LanNetwork::LanNetwork(int columns, int rows) :
    columns(columns), rows(rows)
{
    networkMatrix =  new bool*[rows];
    for (int i = 0; i < columns; i++)
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

QVector<int> LanNetwork::getConnectedComputers(int idOfComputer)
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
    for (int i = 0; i < rows; i++)
    {
        QTextStream consoleInput(stdin);
        QString newInput = consoleInput.readLine();
        QStringList numbers = newInput.split(" ");
        for (int j = 0; j < numbers.length(); j++)
        {
            networkMatrix[i][j] = numbers[j].toInt();
        }
    }
}

