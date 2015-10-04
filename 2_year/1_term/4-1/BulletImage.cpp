#include "BulletImage.h"


BulletImage::BulletImage(int degree, int speed, QPoint start, QGraphicsScene *scene, FramesUpdater *frameUpdater) :
    GameGraphicsItem(frameUpdater, scene), start(start), msecElapsed(0),
    currentPosition(start), degree(degree * 3.14 / 180),
    speed(speed)
{
    explodedTEST = false;
}

void BulletImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(currentPosition, 5.0, 5.0);
    painter->drawEllipse(currentPosition, 3.0, 4.0);
    painter->drawEllipse(currentPosition, 4.0, 3.0);
}

QRectF BulletImage::boundingRect() const
{
    return QRectF(currentPosition, QSizeF(5.0, 5.0));
}

void BulletImage::prepareToUpdate()
{
    msecElapsed += 17;
    currentPosition = getPosition();
    bool farFromSquare = (qAbs((currentPosition - start).x()) > 10)
            || (qAbs((currentPosition - start).y()) > 10 );
    if (!scene->collidingItems(this).isEmpty() && farFromSquare)
    {
        explode();
        return;
    }
}

void BulletImage::explode()
{
    if (explodedTEST)
    {
        return;
    }
    ExplosionImage *explosion = new ExplosionImage(currentPosition, 50, scene, frameUpdater);
    scene->addItem(explosion);
    frameUpdater->appendClearing(this);
    explodedTEST = true;
}

QPointF BulletImage::getPosition()
{
    //x=v0*cosα0*t
    //y=v0*sinα0*t-g*t2/2
    int slowingConstant = 10;
    double time = double(msecElapsed) / (17 * slowingConstant);

    double x = (start.x() + speed * cos(degree) * time);

    double y = (start.y() + speed * time * sin(degree)
             - double (9.8 * time * time) / 2);
    y *= -1;
    if (y <= 7 )
    {
        return QPointF(x, y);
    }
    else if (!explodedTEST)
    {
        explode();
    }
    return QPointF(x, 0);
}

