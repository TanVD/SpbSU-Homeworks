#include "BulletImage.h"


BulletImage::BulletImage(int degree, int speed, QPoint start, QGraphicsScene *scene) :
    start(start), msecElapsed(0), currentPosition(start),
    scene(scene), degree(degree * 3.14 / 180), speed(speed)
{
    timer.setInterval(17);
    timer.start();
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateImage()));
}

void BulletImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(currentPosition, 5.0, 5.0);
    painter->drawEllipse(currentPosition, 3.0, 4.0);
    painter->drawEllipse(currentPosition, 4.0, 3.0);
}

QRectF BulletImage::boundingRect() const
{}

void BulletImage::updateImage()
{
    msecElapsed += 17;
    if (msecElapsed >= msecToExit)
    {
        timer.stop();
    }
    timer.start();
    currentPosition = getPosition();
    update();
    scene->update();
}

QPointF BulletImage::getPosition()
{
    //x=v0*cosα0*t
    //y=v0*sinα0*t-g*t2/2
    int slowingConstant = msecToExit / 10;
    double time = double(msecElapsed) / (17 * slowingConstant);

    double x = (start.x() + speed * cos(degree) * time);

    double y = (start.y() + speed * time * sin(degree)
             - double (9.8 * time * time) / 2);
    y *= -1;
    if (y <= 0)
        return QPointF(x, y);
    else
        timer.stop();
    return QPointF(x, 0);
}

