#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include "KeyManager.h"
#include "TrajectoryImage.h"
#include <QObject>
#include "BulletImage.h"

class Avatar : public QObject
{
    Q_OBJECT
public:
    Avatar(QObject *parent = 0);
    Avatar(QGraphicsScene *scene, KeyManager *control, QPoint start,
           QObject *parent = 0);

private:
    void paintYourPosition();
    QGraphicsScene *scene;
    KeyManager *control;
    QPoint currentPosition;
    QGraphicsItem *image;
    TrajectoryImage *trajectory;
    void updateImage();
    int degreeOfGun;
    int speed;

private slots:
    void changePosition(char button, int msec);

};

