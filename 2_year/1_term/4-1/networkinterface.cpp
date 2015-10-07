#include "networkinterface.h"

int NetworkGeneral::updation = 0;

void NetworkGeneral::setControl(AvatarControl *control, Avatar *avatar, FramesUpdater *updater)
{
    this->control = control;
    this->avatar = avatar;
    connect(avatar, &Avatar::commandDone, this, &NetworkGeneral::commandToBroadcast);
    connect(updater, &FramesUpdater::update, this, &NetworkGeneral::updateByBroadcast);
}

void NetworkGeneral::commandToBroadcast(Command command)
{
    QString hp = QString::number(avatar->getHitPoints());
    QString rel = QString::number(avatar->getReloadings());
    QString point = QString::number(avatar->getPosition().x()) + "|" + QString::number(avatar->getPosition().y());
    QString degree = QString::number(avatar->getDegree());
    QString speed = QString::number(avatar->getSpeed());
    QString fire;
    if (command == Command::fire)
    {
        fire = QString::number(1);
    }
    else
    {
        fire = QString::number(0);
    }

    sendTextMessage(hp + ";" + rel + ";" + point +
                    ";" + degree + ";" + speed + ";" + fire);
}

void NetworkGeneral::updateByBroadcast()
{
    updation = updation + 1;
    if (updation % 5 != 0)
    {
        return;
    }
    QString hp = QString::number(avatar->getHitPoints());
    QString rel = QString::number(avatar->getReloadings());
    QString point = QString::number(avatar->getPosition().x()) + "|" + QString::number(avatar->getPosition().y());
    QString degree = QString::number(avatar->getDegree());
    QString speed = QString::number(avatar->getSpeed());
    sendTextMessage(hp + ";" + rel + ";" + point +
                    ";" + degree + ";" + speed + ";" + "0");
}
