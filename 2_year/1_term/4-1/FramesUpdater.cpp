#include "FramesUpdater.h"

FramesUpdater::FramesUpdater(int fps, QGraphicsScene *scene)
    : scene(scene)
{
    int msecToUpdate = 1000 / fps;
    timer.setInterval(msecToUpdate);
    timer.start();
    connect(&timer, &QTimer::timeout, this, &FramesUpdater::update);
    connect(&timer, &QTimer::timeout, this, &FramesUpdater::clear);
    connect(&timer, &QTimer::timeout, this, &FramesUpdater::add);
}

void FramesUpdater::appendClearing(QGraphicsItem *item)
{
    listClearing.append(item);
}

void FramesUpdater::appendAdding(QGraphicsItem *item)
{
    listAdding.append(item);
}

void FramesUpdater::clear()
{
    QGraphicsItem *item;
    foreach (item, listClearing)
    {
        scene->removeItem(item);
        item->setVisible(false);
        //фикс того, что сцена обновляется далеко не каждые 17 мс и пули некрасиво висят в воздухе
        scene->update();
    }
    scene->update();
    listClearing.clear();


}

void FramesUpdater::add()
{
    QGraphicsItem *item;
    foreach (item, listAdding)
    {
        scene->addItem(item);
        scene->update(item->boundingRect());
    }
    scene->update();
    listAdding.clear();
}

