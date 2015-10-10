#include "BulletGeneral.h"


BulletGeneral::BulletGeneral(int speed, QPoint start, int degree, int hit, int slowingConstant, FramesUpdater *updater) :
    GameGraphicsItem(updater), speed(speed), start(start), degree(double(degree) * 3.14 / 180),
    hit(hit), slowingConstant(slowingConstant), currentPosition(start), msecElapsed(0)
{

}

void BulletGeneral::setDegree(int degree)
{
    this->degree = degree;
}

void BulletGeneral::setSpeed(int speed)
{
    this->speed = speed;
}

void BulletGeneral::setStart(QPoint start)
{
    this->start = start;
}

void BulletGeneral::prepareToUpdate()
{
    if (scene() == nullptr)
    {
        return;
    }
    msecElapsed += oneTimeValue;
    currentPosition = getPosition();
    bool farFromSquare = (qAbs((currentPosition - start).x()) > 10)
            || (qAbs((currentPosition - start).y()) > 10 );
    if (!scene()->collidingItems(this).isEmpty() && farFromSquare)
    {
        explode();
        return;
    }
}

QPointF BulletGeneral::getPosition()
{
    if (scene() == nullptr)
    {
        return start;
    }
    //x=v0*cosα0*t
    //y=v0*sinα0*t-g*t2/2
    double time = double(msecElapsed) / (oneTimeValue * slowingConstant);

    double x = (start.x() + speed * cos(degree) * time);

    double y = (start.y() + speed * time * sin(degree)
             - double (9.8 * time * time) / 2);
    y *= -1;

    foreach (QGraphicsItem* item, this->scene()->items())
    {
        if (this->collidesWithItem(item) && dynamic_cast<GroundImage *>(item) != nullptr)
        {
            explode();
            return QPointF(x, y);
        }
    }

    if (y >= 500 )
    {
        explode();
    }
    return QPointF(x, y);
}
