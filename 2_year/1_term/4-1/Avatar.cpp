#include "Avatar.h"


Avatar::Avatar(QObject *parent) : QObject(parent)
{}

Avatar::Avatar(QGraphicsScene *scene, GroundImage *ground, AvatarControl *control, QPoint start,
               FramesUpdater *updater, QObject *parent) :
    QObject(parent), scene(scene),  ground(ground), control(control),
    currentPosition(start), degreeOfGun(45), speed(45),
    frameUpdater(updater), hitPoints(40), reloading(0)
{
    image = new AvatarImage(start.x(), start.y(), 10, 10, hitPoints, reloading, this, updater);
    trajectory = new TrajectoryImage(degreeOfGun, speed, currentPosition, frameUpdater);
    scene->addItem(trajectory);
    scene->addItem(image);
    connect(control, SIGNAL(newCommand(Command, int)), this, SLOT(changePosition(Command, int)));
    connect(frameUpdater, &FramesUpdater::update, this, &Avatar::updateImage);
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
        ExplosionImage *explosion = new ExplosionImage(currentPosition, 100, frameUpdater);
        scene->removeItem(trajectory);
        scene->removeItem(image);
        control->blockControls(true);
        deleteLater();
        emit exploded();
    }
}

void Avatar::setOnGround()
{
    QList<QPoint> trajectoryGround = ground->getTrajectory();
    QPointF start;
    QPointF finish;
    for (int i = 0; i < trajectoryGround.length() - 1; i++)
    {
        if (trajectoryGround[i].x() < currentPosition.x() &&
                trajectoryGround[i + 1].x() > currentPosition.x())
        {
            start = trajectoryGround[i];
            finish = trajectoryGround[i + 1];
            break;
        }
        else if (trajectoryGround[i].x() == currentPosition.x())
        {
            currentPosition.setY(trajectoryGround[i].y());
            return;
        }
        else if (trajectoryGround[i + 1].x() == currentPosition.x())
        {
            currentPosition.setY(trajectoryGround[i + 1].y());
            return;
        }
    }
    double y = start.y() + (finish.y() - start.y()) * (double(qAbs(currentPosition.x() - start.x()))/
                            double(qAbs(start.x() - finish.x())));
    currentPosition.setY(qRound(y) - 15);
}

void Avatar::updateImage()
{

    setOnGround();

    if (reloading > 0)
    {
        reloading -= 1;
    }
    image->setReloading(reloading);
    image->setPos(currentPosition.x(), currentPosition.y());
    trajectory->setStart(QPoint(currentPosition.x() + 5, -currentPosition.y() + 20));
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
        if (reloading <= 0)
        {
            setOnGround();
            BulletImage *bullet = new BulletImage(degreeOfGun, speed,
                                                  QPoint(currentPosition.x() + 5, -currentPosition.y() + 20), frameUpdater);
            frameUpdater->appendAdding(bullet);
            reloading = reloadingConst;
        }
        break;

    }
    }
    updateImage();
}
