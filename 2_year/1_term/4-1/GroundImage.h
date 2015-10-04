#pragma once
#include "GameGraphicsItem.h"
#include "FramesUpdater.h"
#include <time.h>
#include <QtCore>
#include <QPainter>

class GroundImage : public GameGraphicsItem
{
public:
    GroundImage(FramesUpdater *updater);
    void prepareToUpdate();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;

    QList<QPoint> getTrajectory();

    QPainterPath shape() const override;

private:
    QList<QPoint> trajectory;
};

