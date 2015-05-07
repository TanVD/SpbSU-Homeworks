#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include <QtTest/QTest>
#include "queue.h"

class QueueTest : public QObject
{
    Q_OBJECT
public:
    QueueTest(QObject *parent = 0)
        : QObject(parent)
    {
    }
private slots:
    void init()
    {
        queue = new Queue<int>();
    }

    void enqueuDequeue()
    {
        queue->enqueue(5, 3);
        queue->enqueue(9, 6);
        queue->enqueue(11, 7);
        QVERIFY(queue->dequeue() == 11);
        queue->enqueue(5, 3);
        QVERIFY(queue->dequeue() == 9);
        QVERIFY(queue->dequeue() == 5);
        QVERIFY(queue->dequeue() == 5);
        queue->enqueue(11, 2);
        QVERIFY(queue->dequeue() == 11);
    }

    void cleanup()
    {
        delete queue;
    }

private:
    Queue<int>* queue;
};
