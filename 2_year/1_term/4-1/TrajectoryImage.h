#pragma once
#include <QtGui>
#include <QGraphicsItem>
#include <math.h>


//x=v0*cosα0*t
//y=v0*sinα0*t-g*t2/2

class TrajectoryImage : public QGraphicsItem
{
public:
    TrajectoryImage();

    TrajectoryImage(int degree, int speed, QPoint start);

    void setDegree(int degree);

    void setSpeed(int speed);

    void setStart(QPoint start);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;
private:
    double degree;
    int speed;
    QPoint start;
};
