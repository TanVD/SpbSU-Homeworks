#pragma once
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "FramesUpdater.h"

/**
 * @brief The GameGraphicsItem class General class of all graphics items
 * on scene. Includes FramesUpdater to update every n msec
 */

class GameGraphicsItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    GameGraphicsItem(FramesUpdater *frameUpdater);
    virtual ~GameGraphicsItem() {}

protected:
    FramesUpdater *frameUpdater;
    virtual void prepareToUpdate() = 0;

private slots:
    void requestedToUpdate();

};

