#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include "TrajectoryImage.h"
#include <QObject>
#include "GroundImage.h"
#include "BulletGeneral.h"
#include "Bullet50.h"
#include "Bullet20.h"
#include "FramesUpdater.h"
#include "AvatarControl.h"
#include "ExplosionImage.h"
#include "AvatarImage.h"



const int reloadingConst = 240;

/**
 * @brief The Avatar class This class represents tank on a game field
 */

class Avatar : public QObject
{
    Q_OBJECT
public:
    Avatar(QObject *parent = 0);
    Avatar(QGraphicsScene *scene, GroundImage *ground, AvatarControl *control, QPoint start,
           FramesUpdater *frameUpdater, QObject *parent = 0);
    QGraphicsItem *getImage();

    void hit(int hitPointsToRemove, int idOfExplosion);

    QPoint getPosition();
    int getHitPoints();
    int getReloadings();
    int getDegree();
    int getSpeed();
    int getBullet();


signals:
    void exploded();
    /**
     * @brief commandDone Emitted when avatar has fulfilled all commands
     * and new state can be broadcasted
     * @param command Command which was Done. Only fire will be percieved by network,
     * every else command will be ignored.
     */
    void commandDone(Command command);

private:

    QList<int> explosionsHit;

    QGraphicsScene *scene;
    GroundImage *ground;
    AvatarControl *control;

    QPoint currentPosition;
    int degreeOfGun;
    int speed;

    FramesUpdater* frameUpdater;

    int hitPoints;
    int reloading;
    int bulletToLoad;

    TrajectoryImage *trajectory;
    AvatarImage *image;

    void setOnGround();

private slots:
    /**
     * @brief updateAvatarForced Used to update Avatar by
     * network
     */
    void updateAvatarForced(QPoint currentPosition, int hp, int rel,
                         int degree, int speed, bool fire, int bullet);
    void changePosition(Command button, int msec);
    void updateImage();

};

