#include "Bullet50.h"


Bullet50::Bullet50(int degree, int speed, QPoint start, FramesUpdater *frameUpdater) :
    BulletGeneral(speed, start, degree, 10, 10, frameUpdater)
{
}

Bullet50::~Bullet50()
{

}

void Bullet50::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(currentPosition, 5.0, 5.0);
    painter->drawEllipse(currentPosition, 3.0, 4.0);
    painter->drawEllipse(currentPosition, 4.0, 3.0);
}

QRectF Bullet50::boundingRect() const
{
    return QRectF(currentPosition, QSizeF(5.0, 5.0));
}

void Bullet50::explode()
{
    ExplosionImage *explosion = new ExplosionImage(currentPosition, 50, 10, frameUpdater);
    frameUpdater->appendAdding(explosion);
    frameUpdater->appendClearing(this);
}
