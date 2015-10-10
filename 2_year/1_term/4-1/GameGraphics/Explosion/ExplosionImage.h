#pragma once
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "GameGraphicsItem.h"
#include <QTimer>
#include <QRegion>
#include <QtGui>

/**
 * @brief frameToExplode Class responsible for generating
 * explosion and its image.
 */

const int frameToExplode = 120;

class ExplosionImage : public GameGraphicsItem
{
public:
    ExplosionImage(QPointF center, double radius, int hits, FramesUpdater *frameUpdater);
    ~ExplosionImage();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;

    /**
     * @brief getIdOfExplosion Ids of explosion used to
     * prevent hitting avatar by one explosion more than one time
     */
    int getIdOfExplosion();

    /**
     * @brief getHits Returns number which will
     * be subtracted from avatar
     */
    int getHits();

public slots:
    void prepareToUpdate() override;

private:
    static int idMain;

    QPointF center;
    int idOfExplosion;
    double radius;
    int framesElapsed;
    int hits;
};

