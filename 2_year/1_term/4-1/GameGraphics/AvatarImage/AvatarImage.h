#pragma once
#include <QGraphicsItem>
#include "GameGraphicsItem.h"
#include <QPainter>

class Avatar;

class AvatarImage : public GameGraphicsItem
{
public:
    AvatarImage(int x, int y, int w, int h, int hitPoints, int reloading,
                Avatar* avatar, FramesUpdater* updater);
    ~AvatarImage();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void prepareToUpdate() override;

    void setPos(qreal x, qreal y);

    void setHitPoints(int hp);

    void setReloading(int sec);

    Avatar *getAvatar() const;

private:
    Avatar *avatar;

    double x;
    double y;
    int w;
    int h;

    int hitPoints;
    int reloading;


};

