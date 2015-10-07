#pragma once
#include <QObject>
#include <QPoint>

enum Command
{
    rightAvatar,
    leftAvatar,
    upGun,
    downGun,
    fasterBullet,
    slowerBullet,
    fire,
    changeBullet
};

class AvatarControl : public QObject
{
    Q_OBJECT

public:
    virtual void blockControls(bool blocked) = 0;

signals:
    void newCommand(Command button, int msec);
    void updateAvatarForced(QPoint currentPosition, int hp, int rel,
                               int degree, int speed, bool fire);
};
