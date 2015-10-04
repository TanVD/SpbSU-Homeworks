#pragma once
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>

class FramesUpdater : public QObject
{
    Q_OBJECT
public:
    FramesUpdater(int fps, QGraphicsScene *scene);
    void appendClearing(QGraphicsItem *item);

signals:
    void update();

private:
    QTimer timer;
    QGraphicsScene *scene;
    QList<QGraphicsItem *> listClearing;

private slots:
    void clear();


};
