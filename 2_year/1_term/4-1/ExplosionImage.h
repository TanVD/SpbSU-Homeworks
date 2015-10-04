#pragma once
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "GameGraphicsItem.h"
#include <QTimer>
#include <QRegion>
#include <QtGui>

const int frameToExplode = 120;

class ExplosionImage : public GameGraphicsItem
{
public:
    ExplosionImage(QPointF center, double radius, QGraphicsScene *scene, FramesUpdater *frameUpdater);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

   bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;

   QList<QGraphicsItem *> myCollidingItems(Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;

   void prepareToUpdate();

   int getIdOfExplosion();

private:
    static int idMain;

    QPointF center;
    int idOfExplosion;
    double radius;
    int framesElapsed;
};

