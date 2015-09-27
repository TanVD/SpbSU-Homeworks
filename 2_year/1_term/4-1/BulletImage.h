#pragma once
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <math.h>
#include <QTimer>

const int msecToExit = 1000;

class BulletImage : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    BulletImage(int degree, int speed, QPoint start, QGraphicsScene *scene);

    void setDegree(int degree);

    void setSpeed(int speed);

    void setStart(QPoint start);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;
public slots:
    void updateImage();

private:
    QPointF getPosition();
    int msecElapsed;
    QTimer timer;
    QPoint start;
    QPointF currentPosition;
    QGraphicsScene* scene;
    double degree;
    int speed;
};

