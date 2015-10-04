#pragma once
#include <QGraphicsItem>
#include "GameGraphicsItem.h"
#include <QPainter>

class Avatar;

class AvatarImage : public GameGraphicsItem
{
public:
    AvatarImage(int x, int y, int w, int h, int hitPoints,
                Avatar* avatar, QGraphicsScene* scene, FramesUpdater* updater);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void setPos(qreal x, qreal y);
    void setHitPoints(int hp);
    Avatar *getAvatar();
    void prepareToUpdate();

private:
    Avatar *avatar;
    double x;
    double y;
    int w;
    int h;
    int hitPoints;


};

