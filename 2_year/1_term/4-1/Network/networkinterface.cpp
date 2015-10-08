#include "networkinterface.h"


NetworkGeneral::NetworkGeneral() : updation(0)
{

}

void NetworkGeneral::setControl(AvatarControl *control, Avatar *avatar, FramesUpdater *updater)
{
    this->control = control;
    this->avatar = avatar;
    connect(avatar, &Avatar::commandDone, this, &NetworkGeneral::broadcastCommand);
    connect(updater, &FramesUpdater::update, this, &NetworkGeneral::broadcastUpdate);
}

void NetworkGeneral::broadcastCommand(Command command)
{
    QString hp = QString::number(avatar->getHitPoints());
    QString rel = QString::number(avatar->getReloadings());
    QString point = QString::number(avatar->getPosition().x()) + "|" + QString::number(avatar->getPosition().y());
    QString degree = QString::number(avatar->getDegree());
    QString speed = QString::number(avatar->getSpeed());
    QString fire;
    QString bullet = QString::number(avatar->getBullet());
    if (command == Command::fire)
    {
        fire = QString::number(1);
    }
    else
    {
        fire = QString::number(0);
    }

    sendTextMessage(hp + ";" + rel + ";" + point +
                    ";" + degree + ";" + speed + ";" + fire + ";" + bullet);
}

void NetworkGeneral::broadcastUpdate()
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
    QString bullet = QString::number(avatar->getBullet());
    sendTextMessage(hp + ";" + rel + ";" + point +
                    ";" + degree + ";" + speed + ";" + "0" + ";" + bullet);
}
