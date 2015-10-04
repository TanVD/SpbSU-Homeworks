#include "GameGraphicsItem.h"

GameGraphicsItem::GameGraphicsItem(FramesUpdater *frameUpdater, QGraphicsScene *scene) :
    frameUpdater(frameUpdater), scene(scene)
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
    prepareToUpdate();
    update();
    scene->update();
}

