#include "Avatar.h"


Avatar::Avatar(QObject *parent) : QObject(parent)
{}

Avatar::Avatar(QGraphicsScene *scene, AvatarControl *control, QPoint start,
               FramesUpdater *updater, QObject *parent) :
    QObject(parent), scene(scene), control(control),
    currentPosition(start), degreeOfGun(45), speed(45),
    frameUpdater(updater), hitPoints(40)
{
    image = new AvatarImage(start.x(), start.y(), 10, 10, hitPoints, this, scene, updater);
    trajectory = new TrajectoryImage(degreeOfGun, speed, currentPosition, frameUpdater, this->scene);
    scene->addItem(trajectory);
    scene->addItem(image);
    connect(control, SIGNAL(newCommand(Command, int)), this, SLOT(changePosition(Command, int)));
}

QGraphicsItem *Avatar::getImage()
{
    return image;
}

void Avatar::hit(int hitPoints, int idOfExplosion)
{
    if (explosionsHit.contains(idOfExplosion))
    {
        return;
    }
    explosionsHit.append(idOfExplosion);
    this->hitPoints -= hitPoints;
    image->setHitPoints(this->hitPoints);
    if (this->hitPoints <= 0)
    {
        ExplosionImage *explosion = new ExplosionImage(currentPosition, 100, scene, frameUpdater);
        scene->removeItem(trajectory);
        scene->removeItem(image);
        control->blockControls(true);
        deleteLater();
        emit exploded();
    }
}

void Avatar::updateImage()
{
    image->setPos(currentPosition.x(), currentPosition.y());
    trajectory->setStart(currentPosition);
    trajectory->setDegree(degreeOfGun);
    trajectory->setSpeed(speed);
}

void Avatar::changePosition(Command button, int msec)
{
    switch (button)
    {
    case (Command::leftAvatar):
    {
        currentPosition.setX(currentPosition.x() - 2);
        break;
    }
    case (Command::rightAvatar):
    {
        currentPosition.setX(currentPosition.x()  + 2);
        break;
    }
    case (Command::upGun):
    {
        degreeOfGun += int (double(msec) / 100 ) + 1;
        if (degreeOfGun > 180)
        {
            degreeOfGun = 180;
        }
        break;
    }
    case (Command::downGun):
    {
        degreeOfGun -= int (double(msec) / 100 ) + 1;
        if (degreeOfGun < 0)
        {
            degreeOfGun = 0;
        }
        break;
    }
    case (Command::fasterBullet):
    {
        speed += 1;
        break;
    }
    case (Command::slowerBullet):
    {
        speed -= 1;
        break;
    }
    case (Command::fire):
    {
        BulletImage *bullet = new BulletImage(degreeOfGun, speed, currentPosition, scene, frameUpdater);
        scene->addItem(bullet);
        break;
    }
    }
    updateImage();
}

