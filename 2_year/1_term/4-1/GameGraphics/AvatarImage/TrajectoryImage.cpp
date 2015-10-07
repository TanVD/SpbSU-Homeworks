#include "TrajectoryImage.h"


TrajectoryImage::TrajectoryImage(int degree, int speed, QPoint start, FramesUpdater *frameUpdater) :
    GameGraphicsItem(frameUpdater), degree(degree * 3.14 / 180), speed(speed), start(start)
{}

TrajectoryImage::~TrajectoryImage()
{

}

void TrajectoryImage::setDegree(int degree)
{
    this->degree = degree * 3.14 / 180;
}

void TrajectoryImage::setSpeed(int speed)
{
    this->speed = speed;
}

void TrajectoryImage::setStart(QPoint start)
{
    this->start = start;
}

QRectF TrajectoryImage::boundingRect() const
{
    return QRectF(start.x(), start.y(), 1, 1);
}

void TrajectoryImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    //x=v0*cosα0*t
    //y=v0*sinα0*t-g*t2/2
    for (int i = 0; i < 500; i++)
    {
        int slowingConstant = 5;
        double time = i / slowingConstant;
        double x = (start.x() + speed * cos(degree) * time);

        double y = (start.y() + speed * (time) * sin(degree)
                 - double (9.8 * time * time ) / 2);
        y *= -1;
        if (y < 100) // why??
            painter->drawEllipse(QPointF(x, y), 4, 4);
    }
}

void TrajectoryImage::prepareToUpdate()
{

}

