#pragma once
#include <QtGui>
#include <QGraphicsItem>
#include <math.h>
#include "FramesUpdater.h"
#include "GameGraphicsItem.h"
#include <QGraphicsScene>


//x=v0*cosα0*t
//y=v0*sinα0*t-g*t2/2

class TrajectoryImage : public GameGraphicsItem
{
    Q_INTERFACES(QGraphicsItem)
public:

    TrajectoryImage(int degree, int speed, QPoint start, FramesUpdater *frameUpdater);
    ~TrajectoryImage();

    void setDegree(int degree);

    void setSpeed(int speed);

    void setStart(QPoint start);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void prepareToUpdate();

    QRectF boundingRect() const override;
private:
    double degree;
    int speed;
    QPoint start;
};
