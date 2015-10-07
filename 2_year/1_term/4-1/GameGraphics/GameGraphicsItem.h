#pragma once
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "FramesUpdater.h"

class GameGraphicsItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    GameGraphicsItem(FramesUpdater *frameUpdater);
    virtual ~GameGraphicsItem() {}
    //void explode();

protected:
    FramesUpdater *frameUpdater;
    virtual void prepareToUpdate() = 0;

private slots:
    void requestedToUpdate();

};

