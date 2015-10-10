#pragma once
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QVector>

class LanNetwork
{
public:
    LanNetwork(int numberOfComputers);

    ~LanNetwork();

    void createFromStdin();

    void createFromQStringList(const QStringList &list);

    /**
     * @brief getConnectedComputers Returns vector of ids of
     * computers connected to computer with id equal to parameter
     * @param idOfComputer Computer to find connected with
     * @return Vector of ids connected to parameter
     */
    QVector<int> getConnectedComputers(int idOfComputer) const;

private:
    bool **networkMatrix;
    int columns;
    int rows;
};

