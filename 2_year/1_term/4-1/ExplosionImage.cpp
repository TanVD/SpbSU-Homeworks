#include "ExplosionImage.h"

int ExplosionImage::idMain = 0;

ExplosionImage::ExplosionImage(QPointF center, double radius, QGraphicsScene *scene,
                               FramesUpdater *frameUpdater) :
    GameGraphicsItem(frameUpdater, scene),  center(center),
    idOfExplosion(idMain), radius(radius), framesElapsed(0)

{
    idMain = idMain + 1;
}

void ExplosionImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for (int i = 0; i < 50; i += 5)
    {
        painter->drawEllipse(center, radius * (framesElapsed % 2) - i, radius * (framesElapsed % 2) - i);
    }

}

QRectF ExplosionImage::boundingRect() const
{
    return QRectF(center, QSizeF(radius * 2, radius * 2));
}

QPainterPath ExplosionImage::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

bool ExplosionImage::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    QRectF otherPath = other->boundingRect();
    QRectF ourPath = this->boundingRect();
    double x = otherPath.x() - ourPath.x();
    double y = otherPath.y() - ourPath.y();
    bool result = (x * x + y * y) < radius * radius;
    return result;
}

QList<QGraphicsItem *> ExplosionImage::myCollidingItems(Qt::ItemSelectionMode mode) const
{
    QList <QGraphicsItem *> list;
    scene->items();
    foreach (QGraphicsItem *item, scene->items())
    {
        if (collidesWithItem(item))
        {
            list.append(item);
        }
    }
    return list;
}

void ExplosionImage::prepareToUpdate()
{
    framesElapsed += 1;
    if (framesElapsed >= frameToExplode)
    {
        frameUpdater->appendClearing(this);
    }
}

int ExplosionImage::getIdOfExplosion()
{
    return idOfExplosion;
}

