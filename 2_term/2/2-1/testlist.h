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

   void testLinkedAddOneItem()
   {
       listLinked->add(5);
   }

   void testLinkedAddTwoItems()
   {
       listLinked->add(5);
       listLinked->add(7);
   }

   void testLinkedSeveralItems()
   {
       listLinked->add(5);
       listLinked->add(7);
       listLinked->add(99);
       listLinked->add(199);
   }

   void testLinkedRemoveOneItem()
   {
       listLinked->add(5);
       QVERIFY(listLinked->remove(5));
   }

   void testLinkedRemoveTwoItems()
   {
       listLinked->add(5);
       listLinked->add(7);
       QVERIFY(listLinked->remove(5));
       QVERIFY(listLinked->remove(7));
   }

   void testLinkedRemoveSeveralItems()
   {
       listLinked->add(5);
       listLinked->add(7);
       listLinked->add(99);
       listLinked->add(199);
       QVERIFY(listLinked->remove(5));
       QVERIFY(listLinked->remove(7));
       QVERIFY(listLinked->remove(99));
       QVERIFY(listLinked->remove(199));
   }

   void testLinkedTotallyRemoveAndAdd()
   {
       listLinked->add(5);
       listLinked->add(7);
       QVERIFY(listLinked->remove(5));
       QVERIFY(listLinked->remove(7));
       listLinked->add(99);
       QVERIFY(listLinked->remove(99));
   }

   void testLinkedRemoveNotExisted()
   {
       QVERIFY(!listLinked->remove(9));
   }

   void testDoubleAddOneItem()
   {
       listDouble->add(5);
   }

   void testDoubleAddTwoItems()
   {
       listDouble->add(5);
       listDouble->add(7);
   }

   void testDoubleSeveralItems()
   {
       listDouble->add(5);
       listDouble->add(7);
       listDouble->add(99);
       listDouble->add(199);
   }

   void testDoubleRemoveOneItem()
   {
       listDouble->add(5);
       QVERIFY(listDouble->remove(5));
   }

   void testDoubleRemoveTwoItems()
   {
       listDouble->add(5);
       listDouble->add(7);
       QVERIFY(listDouble->remove(5));
       QVERIFY(listDouble->remove(7));
   }

   void testDoubleRemoveSeveralItems()
   {
       listDouble->add(5);
       listDouble->add(7);
       listDouble->add(99);
       listDouble->add(199);
       QVERIFY(listDouble->remove(5));
       QVERIFY(listDouble->remove(7));
       QVERIFY(listDouble->remove(99));
       QVERIFY(listDouble->remove(199));
   }

   void testDoubleTotallyRemoveAndAdd()
   {
       listDouble->add(5);
       listDouble->add(7);
       QVERIFY(listDouble->remove(5));
       QVERIFY(listDouble->remove(7));
       listDouble->add(99);
       QVERIFY(listDouble->remove(99));
   }

   void testDoubleRemoveNotExisted()
   {
       QVERIFY(!listDouble->remove(9));
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
