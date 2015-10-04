#include "AvatarImage.h"

AvatarImage::AvatarImage(int x, int y, int w, int h, int hitPoints,
                         Avatar *avatar, QGraphicsScene *scene, FramesUpdater *updater)
    :GameGraphicsItem(updater, scene), avatar(avatar), x(x), y(y), w(w), h(h), hitPoints(hitPoints)
{ }

void AvatarImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(x, y, w, h);
    painter->drawText(QRectF(x, y + 20, 50, 50), QString::number(hitPoints));
}

QRectF AvatarImage::boundingRect() const
{
    return QRectF(x, y, w, h);
}

void AvatarImage::setPos(qreal x, qreal y)
{
    this->x = x;
    this->y = y;
}

void AvatarImage::setHitPoints(int hp)
{
    hitPoints = hp;
}

Avatar *AvatarImage::getAvatar()
{
    return avatar;
}

void AvatarImage::prepareToUpdate()
{

}

