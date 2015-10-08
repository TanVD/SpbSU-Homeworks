#pragma once
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>

/**
 * @brief The FramesUpdater class Class responsible for updating
 * scene every n msec (all gamegraphicsitems are connected to this signal)
 * Also class creates and deletes objects from scene every frame
 */

class FramesUpdater : public QObject
{
    Q_OBJECT
public:
    FramesUpdater(int fps, QGraphicsScene *scene);

    /**
     * @brief appendClearing Add item to list for removing
     * from scene
     */
    void appendClearing(QGraphicsItem *item);

    /**
     * @brief appendAdding Add item to list for adding
     * on scene
     */
    void appendAdding(QGraphicsItem *item);

signals:
    /**
     * @brief update Every frame this signal emitted
     */
    void update();

private:
    QTimer timer;
    QGraphicsScene *scene;
    QList<QGraphicsItem *> listAdding;
    QList<QGraphicsItem *> listClearing;

private slots:
    void clear();
    void add();


};
