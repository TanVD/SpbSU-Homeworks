#pragma once
#include <QObject>
#include <QPoint>

/**
 * @brief The Command enum Interface for avatar controls
 */

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
    /**
     * @brief blockControls Used to blockcontrols if one
     * of tanks exploded
     */
    virtual void blockControls(bool blocked) = 0;

signals:
    /**
     * @brief newCommand Used to send new command from
     * controls to Avatar
     */
    void newCommand(Command button, int msec);

    /**
     * @brief updateAvatarForced Used in network to update
     * state of Avatar
     */
    void updateAvatarForced(QPoint currentPosition, int hp, int rel,
                               int degree, int speed, bool fire, int bullet);
};
