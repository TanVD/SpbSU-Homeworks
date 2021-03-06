#pragma once
#include "GameGraphicsItem.h"
#include "FramesUpdater.h"
#include "GroundImage.h"

/**
 * @brief oneTimeValue General class for bullets. Responsible for
 * working with frames updater
 */

const int oneTimeValue = 17;

class BulletGeneral : public GameGraphicsItem
{

public:
    BulletGeneral(int speed, QPoint start, int degree, int hit, int slowingConstant, FramesUpdater *updater);

    virtual void setDegree(int degree);

    virtual void setSpeed(int speed);

    virtual void setStart(QPoint start);

    virtual void explode() = 0;

    void prepareToUpdate();

protected:
    int speed;
    QPoint start;
    double degree;

    int hit;
    int slowingConstant;

    QPointF currentPosition;
    QPointF getPosition();

    int msecElapsed;
};
