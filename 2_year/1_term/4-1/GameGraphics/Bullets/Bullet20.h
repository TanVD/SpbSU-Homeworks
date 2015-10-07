#pragma once
#include "BulletGeneral.h"
#include "ExplosionImage.h"


class Bullet20 : public BulletGeneral
{
public:
    Bullet20(int degree, int speed, QPoint start,  FramesUpdater *frameUpdater);
    ~Bullet20();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;

    void explode();
};

