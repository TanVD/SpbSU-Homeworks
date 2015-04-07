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

   void testPushStack()
   {
       arrayStack->push(5);
       arrayStack->push(7);
       arrayStack->push(99);
       stackDouble->push(5);
       stackDouble->push(7);
       stackDouble->push(99);
       QVERIFY(arrayStack->pop() == 99);
       QVERIFY(arrayStack->pop() == 7);
       QVERIFY(arrayStack->pop() == 5);
       QVERIFY(stackDouble->pop() == 99);
       QVERIFY(stackDouble->pop() == 7);
       QVERIFY(stackDouble->pop() == 5);
       arrayStack->push(99);
       stackDouble->push(5);
       QVERIFY(arrayStack->pop() == 99);
       QVERIFY(stackDouble->pop() == 5);
   }

   void testTopStack()
   {
       arrayStack->push(2);
       arrayStack->push(3);
       stackDouble->push(2);
       stackDouble->push(3);
       QVERIFY(arrayStack->top() == 3);
       QVERIFY(arrayStack->top() == 3);
   }

   void testEmptyStack()
   {
       QVERIFY(arrayStack->isEmpty());
       QVERIFY(stackDouble->isEmpty());
       arrayStack->push(5);
       stackDouble->push(5);
       QVERIFY(!arrayStack->isEmpty());
       QVERIFY(!stackDouble->isEmpty());
       arrayStack->pop();
       stackDouble->pop();
       QVERIFY(arrayStack->isEmpty());
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
