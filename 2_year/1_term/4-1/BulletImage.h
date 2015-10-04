#pragma once
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "ExplosionImage.h"
#include <math.h>
#include <QTimer>
#include "GameGraphicsItem.h"

class BulletImage : public GameGraphicsItem
{
public:
    BulletImage(int degree, int speed, QPoint start, QGraphicsScene *scene, FramesUpdater *frameUpdater);

    void setDegree(int degree);

    void setSpeed(int speed);

    void setStart(QPoint start);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;

    void explode();

public slots:
    void prepareToUpdate();

private:
    bool explodedTEST;
    QPointF getPosition();
    QPoint start;
    int msecElapsed;
    QPointF currentPosition;
    double degree;
    int speed;
};

