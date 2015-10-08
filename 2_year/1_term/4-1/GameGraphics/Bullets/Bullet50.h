#pragma once
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "ExplosionImage.h"
#include <math.h>
#include <QTimer>
#include "GameGraphicsItem.h"
#include "GroundImage.h"
#include "BulletGeneral.h"

/**
 * @brief The Bullet50 class One kind of bullet (radius 50 of
 * explosion)
 */

class Bullet50 : public BulletGeneral
{
public:
    Bullet50(int degree, int speed, QPoint start,  FramesUpdater *frameUpdater);
    ~Bullet50();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;

    void explode();
};

