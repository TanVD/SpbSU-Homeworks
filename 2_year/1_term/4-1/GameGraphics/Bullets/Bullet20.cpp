#include "Bullet20.h"

Bullet20::Bullet20(int degree, int speed, QPoint start,  FramesUpdater *frameUpdater) :
    BulletGeneral(speed, start, degree, 20, 25, frameUpdater)
{ }

Bullet20::~Bullet20()
{

}

void Bullet20::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(currentPosition, 10.0, 6.0);
    painter->drawEllipse(currentPosition, 5.0, 5.0);
    painter->drawEllipse(currentPosition, 3.0, 3.0);
    painter->drawEllipse(currentPosition, 2.0, 2.0);
    painter->drawEllipse(currentPosition, 1.0, 1.0);
}

QRectF Bullet20::boundingRect() const
{
    return QRectF(currentPosition, QSizeF(10.0, 6.0));
}

void Bullet20::explode()
{
    ExplosionImage *explosion = new ExplosionImage(currentPosition, 25, 25, frameUpdater);
    frameUpdater->appendAdding(explosion);
    frameUpdater->appendClearing(this);
}
