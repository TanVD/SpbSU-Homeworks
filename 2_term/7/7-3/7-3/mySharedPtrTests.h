#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <stack>
#include "mySharedPtr.h"
#include "exampleClass.h"


class MySharedPtrTests : public QObject
{
    Q_OBJECT
public:
    explicit MySharedPtrTests(QObject *parent = 0) : QObject(parent) {}
private:
private slots:

    void createPointerTest()
    {
        MySharedPtr<ExampleClass> object(new ExampleClass(9));
        QCOMPARE(9, (*object).number());
        QCOMPARE(9, object->number());
        QCOMPARE(1, object.copyCounter());
    }

    void onePointerTestCopy()
    {
        MySharedPtr<ExampleClass> object(new ExampleClass(9));
        {
            MySharedPtr<ExampleClass> copiedObject(object);
            QCOMPARE(2, object.copyCounter());
            QCOMPARE(2, copiedObject.copyCounter());
        }
        QCOMPARE(1, object.copyCounter());
    }

    void severalPointerTestCopy()
    {
        MySharedPtr<ExampleClass> object(new ExampleClass(9));
        {
            MySharedPtr<ExampleClass> copiedObjectFirst(object);
            {
                MySharedPtr<ExampleClass> copiedObjectSecond(copiedObjectFirst);
                QCOMPARE(3, object.copyCounter());
                QCOMPARE(3, copiedObjectFirst.copyCounter());
                QCOMPARE(3, copiedObjectSecond.copyCounter());
            }
            QCOMPARE(2, object.copyCounter());
            QCOMPARE(2, copiedObjectFirst.copyCounter());
        }
        QCOMPARE(1, object.copyCounter());
    }

    void onePointerAssignmentTest()
    {
        MySharedPtr<ExampleClass> objectFirst(new ExampleClass(9));
        MySharedPtr<ExampleClass> objectSecond(new ExampleClass(10));
        objectFirst = objectSecond;
        QCOMPARE(objectFirst->number(), objectSecond->number());
        QCOMPARE(objectFirst.copyCounter(), 2);
        QCOMPARE(objectFirst->number(), 10);
    }


    void severalObjectAssignmentTest()
    {
        MySharedPtr<ExampleClass> objectFirst(new ExampleClass(9));
        MySharedPtr<ExampleClass> objectSecond(new ExampleClass(10));
        MySharedPtr<ExampleClass> objectThird(new ExampleClass(11));
        objectSecond = objectFirst;
        objectThird = objectSecond;
        QCOMPARE(objectFirst->number(), objectSecond->number());
        QCOMPARE(objectSecond->number(), objectThird->number());
        QCOMPARE(objectFirst->number(), 9);
        QCOMPARE(objectFirst.copyCounter(), objectSecond.copyCounter());
        QCOMPARE(objectSecond.copyCounter(), objectThird.copyCounter());
        QCOMPARE(objectFirst.copyCounter(), 3);

    }


    void exampleFirst()
    {
        //...
        {
            MySharedPtr<ExampleClass> objectFirst(new ExampleClass(9));
            int input = 9;
            if (input > 8)
            {
                MySharedPtr<ExampleClass> objectSecond = objectFirst;
                QCOMPARE(objectSecond->number() + 2, 11);
            }
            else
            {
                MySharedPtr<ExampleClass> objectSecond = objectFirst;
                QCOMPARE(objectSecond->number() + 5, 14);
            }
        }
        //...
        //No need to worry about created in block objects
    }

    void exampleSecond()
    {
        //...
        {
            ExampleClass* object = new ExampleClass(9);
            int y = 8 + object->number();
        }
        //...
        //Here will be memory leak (nobody deletes object)
        //...
        {
            MySharedPtr<ExampleClass> myRightObject(new ExampleClass(9));
            int y = 8 + myRightObject->number();
        }
        //...
        //Here is all good
    }
};
