#pragma once
#include <QGraphicsScene>
#include <QList>
#include <Avatar.h>
#include "FramesUpdater.h"
#include <AvatarImage.h>
#include <QMessageBox>

class GameRules : public QObject
{
    Q_OBJECT
public:
    GameRules(QGraphicsScene *scene, FramesUpdater *updater, QObject *parent = 0);
public slots:
    void tankExploded();

private:
    QGraphicsScene *scene;
    FramesUpdater *updater;

private slots:
    void update();

};

