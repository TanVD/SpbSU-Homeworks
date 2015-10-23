#include "ExplosionImage.h"

int ExplosionImage::idMain = 0;

ExplosionImage::ExplosionImage(QPointF center, double radius, int hits,
                               FramesUpdater *frameUpdater) :
    GameGraphicsItem(frameUpdater),  center(center),
    idOfExplosion(idMain), radius(radius), framesElapsed(0),
    hits(hits)

{
    idMain = idMain + 1;
}

ExplosionImage::~ExplosionImage()
{

}

void ExplosionImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for (int i = 10; i < radius; i += 5)
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

int ExplosionImage::getHits()
{
    return hits;
}

