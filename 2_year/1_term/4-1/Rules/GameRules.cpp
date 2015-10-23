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
                    AvatarImage *avatarCasted = dynamic_cast<AvatarImage *>(itemCollides);
                    BulletGeneral *bulletCasted = dynamic_cast<BulletGeneral *>(itemCollides);
                    if (avatarCasted != nullptr)
                    {
                        avatarCasted->getAvatar()->hit(
                                    image->getHits(), image->getIdOfExplosion());
                    }
                    else if (bulletCasted != nullptr)
                    {
                        bulletCasted->explode();
                    }
                }
            }
        }
    }
}

