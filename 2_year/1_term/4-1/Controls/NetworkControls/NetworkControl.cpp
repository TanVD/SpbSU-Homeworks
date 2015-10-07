#include "NetworkControl.h"

NetworkControl::NetworkControl(NetworkGeneral *network) : network(network), blocked(false)
{
    connect(network, &NetworkGeneral::newMessage, this, &NetworkControl::newMessage);
}

void NetworkControl::blockControls(bool blocked)
{
    this->blocked = blocked;
}

void NetworkControl::newMessage(QString message)
{
    if (blocked)
    {
        return;
    }
    QStringList list = message.split(";");
    int hp = list[0].toInt();
    int rel = list[1].toInt();
    QStringList point = list[2].split("|");
    QPoint currentPosition(point[0].toInt(), point[1].toInt());
    int degree = list[3].toInt();
    int speed = list[4].toInt();
    bool fire = list[5].toInt();
    emit updateAvatarForced(currentPosition, hp, rel, degree, speed, fire);

}

