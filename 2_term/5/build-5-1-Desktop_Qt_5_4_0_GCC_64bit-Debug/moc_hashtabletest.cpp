/****************************************************************************
** Meta object code from reading C++ file 'hashtabletest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../5-1/hashtabletest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hashtabletest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HashTableTest_t {
    QByteArrayData data[9];
    char stringdata[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HashTableTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HashTableTest_t qt_meta_stringdata_HashTableTest = {
    {
QT_MOC_LITERAL(0, 0, 13), // "HashTableTest"
QT_MOC_LITERAL(1, 14, 4), // "init"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 17), // "testPushHashTable"
QT_MOC_LITERAL(4, 38, 19), // "testRemoveHashTable"
QT_MOC_LITERAL(5, 58, 25), // "testChangeModuleHashTable"
QT_MOC_LITERAL(6, 84, 22), // "testChangeHashFunction"
QT_MOC_LITERAL(7, 107, 18), // "testStatsHashTable"
QT_MOC_LITERAL(8, 126, 7) // "cleanup"

    },
    "HashTableTest\0init\0\0testPushHashTable\0"
    "testRemoveHashTable\0testChangeModuleHashTable\0"
    "testChangeHashFunction\0testStatsHashTable\0"
    "cleanup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HashTableTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HashTableTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HashTableTest *_t = static_cast<HashTableTest *>(_o);
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->testPushHashTable(); break;
        case 2: _t->testRemoveHashTable(); break;
        case 3: _t->testChangeModuleHashTable(); break;
        case 4: _t->testChangeHashFunction(); break;
        case 5: _t->testStatsHashTable(); break;
        case 6: _t->cleanup(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HashTableTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HashTableTest.data,
      qt_meta_data_HashTableTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HashTableTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HashTableTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HashTableTest.stringdata))
        return static_cast<void*>(const_cast< HashTableTest*>(this));
    return QObject::qt_metacast(_clname);
}

int HashTableTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
