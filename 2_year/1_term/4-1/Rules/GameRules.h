#pragma once
#include <QGraphicsScene>
#include <QList>
#include <Avatar.h>
#include "FramesUpdater.h"
#include <AvatarImage.h>
#include <QMessageBox>
#include "GroundImage.h"

/**
 * @brief The GameRules class this class is used to detect collisions
 * and treat them according to rules of game
 */

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

