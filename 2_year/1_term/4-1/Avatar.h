#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include "TrajectoryImage.h"
#include <QObject>
#include "GroundImage.h"
#include "BulletImage.h"
#include "FramesUpdater.h"
#include "AvatarControl.h"
#include "ExplosionImage.h"
#include "AvatarImage.h"

const int reloadingConst = 240;

class Avatar : public QObject
{
    Q_OBJECT
public:
    Avatar(QObject *parent = 0);
    Avatar(QGraphicsScene *scene, GroundImage *ground, AvatarControl *control, QPoint start,
           FramesUpdater *frameUpdater, QObject *parent = 0);
    QGraphicsItem *getImage();
    void hit(int hitPoints, int idOfExplosion);


signals:
    void exploded();

private:
    void setOnGround();
    QList<int> explosionsHit;

    QGraphicsScene *scene;

    AvatarControl *control;
    AvatarImage *image;
    QPoint currentPosition;

    TrajectoryImage *trajectory;
    int degreeOfGun;
    int speed;

    FramesUpdater* frameUpdater;

    int hitPoints;
    int reloading;

    GroundImage *ground;


private slots:
    void changePosition(Command button, int msec);
    void updateImage();

};

