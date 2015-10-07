#include "GameGraphicsItem.h"

GameGraphicsItem::GameGraphicsItem(FramesUpdater *frameUpdater) :
    frameUpdater(frameUpdater)
{
    connect(frameUpdater, &FramesUpdater::update, this, &GameGraphicsItem::requestedToUpdate);
}
/**
void GameGraphicsItem::explode()
{
    ExplosionImage *explosion = new ExplosionImage(currentPosition, 100,
                                                   scene, frameUpdater);
    scene->removeItem(this);
}
**/
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

