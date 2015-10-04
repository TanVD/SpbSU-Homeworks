#include "AvatarImage.h"

AvatarImage::AvatarImage(int x, int y, int w, int h, int hitPoints, int reloading,
                         Avatar *avatar, FramesUpdater *updater)
    :GameGraphicsItem(updater), avatar(avatar), x(x), y(y), w(w), h(h), hitPoints(hitPoints),
      reloading(reloading)
{ }

AvatarImage::~AvatarImage()
{

}

void AvatarImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(x, y, w, h);
    painter->fillRect(QRectF(x + 2  , y + 2, w - 2, h - 2), Qt::BrushStyle::SolidPattern);
    painter->drawText(QRectF(x, y + 15, 140, 50), QString::number(hitPoints) + "hp");
    painter->drawRect(QRectF(x, y + 15, 40, 20));
    painter->drawText(QRectF(x, y - 25, 140, 50), QString::number(reloading));
    painter->drawRect(QRectF(x, y - 25, 40, 20));
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

void AvatarImage::setReloading(int sec)
{
    reloading = sec;
}

Avatar *AvatarImage::getAvatar()
{
    return avatar;
}

void AvatarImage::prepareToUpdate()
{

}

