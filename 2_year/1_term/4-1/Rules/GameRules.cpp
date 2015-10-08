#include "GameRules.h"

GameRules::GameRules(QGraphicsScene *scene, FramesUpdater *updater, QObject *parent)
    : QObject(parent), scene(scene), updater(updater)
{
    connect(updater, &FramesUpdater::update, this, &GameRules::update);
}

void GameRules::tankExploded()
{
    QMessageBox box;
    box.setText("End of game");
    box.exec();
}

void GameRules::update()
{
    QGraphicsItem *item;
    foreach(item,  scene->items())
    {
        ExplosionImage *image = dynamic_cast<ExplosionImage *>(item);
        if (image != nullptr)
        {
            QGraphicsItem *itemCollides;
            foreach(itemCollides, scene->items())
            {
                if (itemCollides != item && image->collidesWithItem(itemCollides))
                {
                    if (dynamic_cast<AvatarImage *>(itemCollides) != nullptr)
                    {
                        dynamic_cast<AvatarImage *>(itemCollides)->getAvatar()->hit(
                                    image->getHits(), image->getIdOfExplosion());
                    }
                    else if (dynamic_cast<Bullet50 *>(itemCollides) != nullptr)
                    {
                        dynamic_cast<Bullet50 *>(itemCollides)->explode();
                    }
                }
            }
        }
    }
}

