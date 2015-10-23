#pragma once
#include "GameGraphicsItem.h"
#include "FramesUpdater.h"
#include <time.h>
#include <QString>
#include <QStringList>
#include <QtCore>
#include <QPainter>

/**
 * @brief The GroundImage class Class responsible for creating Ground
 * and representing its shape and image. Can be serialized to qstring for
 * broadcasting
 */

class GroundImage : public GameGraphicsItem
{
public:
    GroundImage(FramesUpdater *updater);

    GroundImage(FramesUpdater *updater, QString trajectorySerialized);

    void prepareToUpdate();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;

    /**
     * @brief getTrajectory Returns list of points which used to
     * create ground
     */
    QList<QPoint> getTrajectory();

    QPainterPath shape() const override;

    QString serializeToString();

private:
    QList<QPoint> trajectory;
};

