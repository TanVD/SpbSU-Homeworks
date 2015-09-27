#include "Avatar.h"

Avatar::Avatar(QObject *parent) : QObject(parent)
{}

Avatar::Avatar(QGraphicsScene *scene, KeyManager *control, QPoint start, QObject *parent) :
    QObject(parent), scene(scene), control(control),
    currentPosition(start), degreeOfGun(45), speed(45)
{
    image = new QGraphicsRectItem(0, 0, 10, 10);
    trajectory = new TrajectoryImage(degreeOfGun, speed, currentPosition);
    paintYourPosition();
    connect(control, SIGNAL(newButtonPressed(char, int)), this, SLOT(changePosition(char, int)));
}

void Avatar::paintYourPosition()
{
    scene->addItem(trajectory);
    scene->addItem(image);
}

void Avatar::updateImage()
{
    image->setPos(currentPosition.x(), currentPosition.y());
    trajectory->setStart(currentPosition);
    trajectory->setDegree(degreeOfGun);
    trajectory->setSpeed(speed);
    trajectory->update();
    scene->update();
    //paintYourTrajectory

}

void Avatar::changePosition(char button, int msec)
{
    switch (button)
    {
    case 'D':
    {
        currentPosition.setX(currentPosition.x() + int (double(msec) / 10) + 1);
        break;
    }
    case 'A':
    {
        currentPosition.setX(currentPosition.x() - int (double(msec) / 10) + 1);
        break;
    }
    case 'W':
    {
        degreeOfGun += int (double(msec) / 100 ) + 1;
        if (degreeOfGun > 180)
        {
            degreeOfGun = 180;
        }
        break;
    }
    case 'S':
    {
        degreeOfGun -= int (double(msec) / 100 ) + 1;
        if (degreeOfGun < 0)
        {
            degreeOfGun = 0;
        }
        break;
    }
    case 'Q':
    {
        speed += int (double(msec) / 10) + 1;
        break;
    }
    case 'E':
    {
        speed -= int (double(msec) / 10) + 1;
        break;
    }
    case ' ':
    {
        BulletImage *bullet = new BulletImage(degreeOfGun, speed, currentPosition, scene);
        scene->addItem(bullet);
        break;
    }
    }
    updateImage();
}

