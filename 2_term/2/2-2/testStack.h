#pragma once
#include "arrayStack.h"
#include "stackDouble.h"
#include "stack.h"
#include <QtTest/QtTest>
#include <QtCore/QObject>
class StackTest : public QObject
{
   Q_OBJECT
public:
   explicit StackTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       arrayStack = new ArrayStack();
       stackDouble = new StackDouble();
   }

   void testArrayIsEmptyAfterInit()
   {
       QVERIFY(arrayStack->isEmpty());
   }

   void testArrayPushOneElement()
   {
       arrayStack->push(5);
       QCOMPARE(arrayStack->top(), 5.0);
   }

   void testArrayPushTwoElements()
   {
       arrayStack->push(5);
       QCOMPARE(arrayStack->top(), 5.0);
       arrayStack->push(7);
       QCOMPARE(arrayStack->top(), 7.0);
   }

   void testArrayPushSeveralElements()
   {
       arrayStack->push(5);
       QCOMPARE(arrayStack->top(), 5.0);
       arrayStack->push(7);
       QCOMPARE(arrayStack->top(), 7.0);
       arrayStack->push(99);
       QCOMPARE(arrayStack->top(), 99.0);
       arrayStack->push(109);
       QCOMPARE(arrayStack->top(), 109.0);
   }

   void testArrayPopOneElement()
   {
       arrayStack->push(5);
       QVERIFY(arrayStack->pop() == 5);
   }

   void testArrayPopTwoElements()
   {
       arrayStack->push(5);
       arrayStack->push(7);
       QVERIFY(arrayStack->pop() == 7);
       QVERIFY(arrayStack->pop() == 5);
   }

   void testArrayPopSeveralElements()
   {
       arrayStack->push(5);
       arrayStack->push(7);
       arrayStack->push(99);
       arrayStack->push(109);
       QVERIFY(arrayStack->pop() == 109);
       QVERIFY(arrayStack->pop() == 99);
       QVERIFY(arrayStack->pop() == 7);
       QVERIFY(arrayStack->pop() == 5);
   }

   void testArrayIsEmptyAfterFilling()
   {
       arrayStack->push(5);
       QVERIFY(!arrayStack->isEmpty());
   }

   void testArrayIsEmptyAfterFillingAndRemoving()
   {
       arrayStack->push(5);
       arrayStack->pop();
       QVERIFY(arrayStack->isEmpty());
   }

   void testArrayTopStack()
   {
       arrayStack->push(3);
       QVERIFY(arrayStack->top() == 3);
   }

   void testdoubleIsEmptyAfterInit()
   {
       QVERIFY(stackDouble->isEmpty());
   }

   void testDoublePushOneElement()
   {
       stackDouble->push(5);
       QCOMPARE(stackDouble->top(), 5.0);
   }

   void testDoublePushTwoElements()
   {
       stackDouble->push(5);
       QCOMPARE(stackDouble->top(), 5.0);
       stackDouble->push(7);
       QCOMPARE(stackDouble->top(), 7.0);
   }

   void testDoublePushSeveralElements()
   {
       stackDouble->push(5);
       QCOMPARE(stackDouble->top(), 5.0);
       stackDouble->push(7);
       QCOMPARE(stackDouble->top(), 7.0);
       stackDouble->push(99);
       QCOMPARE(stackDouble->top(), 99.0);
       stackDouble->push(109);
       QCOMPARE(stackDouble->top(), 109.0);
   }

   void testDoublePopOneElement()
   {
       stackDouble->push(5);
       QVERIFY(stackDouble->pop() == 5);
   }

   void testDoublePopTwoElements()
   {
       stackDouble->push(5);
       stackDouble->push(7);
       QVERIFY(stackDouble->pop() == 7);
       QVERIFY(stackDouble->pop() == 5);
   }

   void testDoublePopSeveralElements()
   {
       stackDouble->push(5);
       stackDouble->push(7);
       stackDouble->push(99);
       stackDouble->push(109);
       QVERIFY(stackDouble->pop() == 109);
       QVERIFY(stackDouble->pop() == 99);
       QVERIFY(stackDouble->pop() == 7);
       QVERIFY(stackDouble->pop() == 5);
   }

   void testDoubleTopStack()
   {
       stackDouble->push(3);
       QVERIFY(stackDouble->top() == 3);
   }

   void testDoubleIsEmptyAfterFilling()
   {
       stackDouble->push(5);
       QVERIFY(!stackDouble->isEmpty());
   }

   void testDoubleIsEmptyAfterFillingAndRemoving()
   {
       stackDouble->push(5);
       stackDouble->pop();
       QVERIFY(stackDouble->isEmpty());
   }

   void cleanup()
   {
       delete arrayStack;
       delete stackDouble;
   }
private:
   Stack* arrayStack;
   Stack* stackDouble;
};
