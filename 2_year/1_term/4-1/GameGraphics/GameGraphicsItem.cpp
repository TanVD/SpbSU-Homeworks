#include "GameGraphicsItem.h"

GameGraphicsItem::GameGraphicsItem(FramesUpdater *frameUpdater) :
    frameUpdater(frameUpdater)
{
    connect(frameUpdater, &FramesUpdater::update, this, &GameGraphicsItem::requestedToUpdate);
}

void GameGraphicsItem::requestedToUpdate()
{
    if (scene() == nullptr)
    {
        return;
    }
    prepareToUpdate();
    update();
    scene()->update();
}

