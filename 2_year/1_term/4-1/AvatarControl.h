#pragma once
#include <QObject>
enum Command
{
    rightAvatar,
    leftAvatar,
    upGun,
    downGun,
    fasterBullet,
    slowerBullet,
    fire
};

class AvatarControl : public QObject
{
    Q_OBJECT
public:
    virtual void blockControls(bool blocked) = 0;
signals:
    void newCommand(Command button, int msec);
};
