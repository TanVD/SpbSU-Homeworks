#include "FramesUpdater.h"

FramesUpdater::FramesUpdater(int fps, QGraphicsScene *scene)
    : scene(scene)
{
    int msecToUpdate = 1000 / fps;
    timer.setInterval(msecToUpdate);
    timer.start();
    connect(&timer, &QTimer::timeout, this, &FramesUpdater::update);
    connect(&timer, &QTimer::timeout, this, &FramesUpdater::clear);
}

void FramesUpdater::appendClearing(QGraphicsItem *item)
{
    listClearing.append(item);
}

void FramesUpdater::clear()
{
    QGraphicsItem *item;
    foreach (item, listClearing)
    {
        item->removeItem(item);
//      delete item;
    }
    scene->update();
    listClearing.clear();
}

