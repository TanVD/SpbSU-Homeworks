#pragma once
#include "list.h"
#include "linkedList.h"
#include "doubleLinkedList.h"
#include <QtTest/QtTest>
#include <QtCore/QObject>
class ListTest : public QObject
{
   Q_OBJECT
public:
   explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       listLinked = new LinkedList();
       listDouble = new DoubleLinkedList();
   }

   void testAddRemoveList()
   {
       listLinked->add(5);
       listLinked->add(7);
       listLinked->add(99);
       listDouble->add(5);
       listDouble->add(7);
       listDouble->add(99);
       QVERIFY(listLinked->remove(7));
       QVERIFY(!listLinked->remove(9));
       QVERIFY(!listDouble->remove(9));
       QVERIFY(listLinked->remove(99));
       QVERIFY(listDouble->remove(7));
       QVERIFY(listDouble->remove(5));
       QVERIFY(listLinked->remove(5));
       QVERIFY(listDouble->remove(99));
       listLinked->add(5);
       listDouble->add(5);
       QVERIFY(listLinked->remove(5));
       QVERIFY(listDouble->remove(5));
   }

   void clenup()
   {
       delete listLinked;
       delete listDouble;
   }
private:
   List* listLinked;
   List* listDouble;
};
