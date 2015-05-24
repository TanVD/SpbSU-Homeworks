/****************************************************************************
** Meta object code from reading C++ file 'treetest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Test2-1/treetest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'treetest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SetTest_t {
    QByteArrayData data[21];
    char stringdata[379];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetTest_t qt_meta_stringdata_SetTest = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SetTest"
QT_MOC_LITERAL(1, 8, 4), // "init"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 7), // "cleanup"
QT_MOC_LITERAL(4, 22, 13), // "addOneElement"
QT_MOC_LITERAL(5, 36, 14), // "addTwoElements"
QT_MOC_LITERAL(6, 51, 18), // "addSeveralElements"
QT_MOC_LITERAL(7, 70, 23), // "checkIsExistsNonExisted"
QT_MOC_LITERAL(8, 94, 16), // "deleteOneElement"
QT_MOC_LITERAL(9, 111, 16), // "deleteTwoElement"
QT_MOC_LITERAL(10, 128, 20), // "deleteSeveralElement"
QT_MOC_LITERAL(11, 149, 20), // "iterationThroughTree"
QT_MOC_LITERAL(12, 170, 17), // "enumaretorGetLast"
QT_MOC_LITERAL(13, 188, 15), // "enumaratorReset"
QT_MOC_LITERAL(14, 204, 19), // "enumaretorRemoveOne"
QT_MOC_LITERAL(15, 224, 32), // "enumeratorRemoveOneAndGoToSecond"
QT_MOC_LITERAL(16, 257, 19), // "enumaretorRemoveTwo"
QT_MOC_LITERAL(17, 277, 20), // "printInorderElements"
QT_MOC_LITERAL(18, 298, 32), // "printInorderElementsByEnumerator"
QT_MOC_LITERAL(19, 331, 27), // "printReverseInorderElements"
QT_MOC_LITERAL(20, 359, 19) // "printStructElements"

    },
    "SetTest\0init\0\0cleanup\0addOneElement\0"
    "addTwoElements\0addSeveralElements\0"
    "checkIsExistsNonExisted\0deleteOneElement\0"
    "deleteTwoElement\0deleteSeveralElement\0"
    "iterationThroughTree\0enumaretorGetLast\0"
    "enumaratorReset\0enumaretorRemoveOne\0"
    "enumeratorRemoveOneAndGoToSecond\0"
    "enumaretorRemoveTwo\0printInorderElements\0"
    "printInorderElementsByEnumerator\0"
    "printReverseInorderElements\0"
    "printStructElements"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,
      19,    0,  126,    2, 0x08 /* Private */,
      20,    0,  127,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SetTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetTest *_t = static_cast<SetTest *>(_o);
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->cleanup(); break;
        case 2: _t->addOneElement(); break;
        case 3: _t->addTwoElements(); break;
        case 4: _t->addSeveralElements(); break;
        case 5: _t->checkIsExistsNonExisted(); break;
        case 6: _t->deleteOneElement(); break;
        case 7: _t->deleteTwoElement(); break;
        case 8: _t->deleteSeveralElement(); break;
        case 9: _t->iterationThroughTree(); break;
        case 10: _t->enumaretorGetLast(); break;
        case 11: _t->enumaratorReset(); break;
        case 12: _t->enumaretorRemoveOne(); break;
        case 13: _t->enumeratorRemoveOneAndGoToSecond(); break;
        case 14: _t->enumaretorRemoveTwo(); break;
        case 15: _t->printInorderElements(); break;
        case 16: _t->printInorderElementsByEnumerator(); break;
        case 17: _t->printReverseInorderElements(); break;
        case 18: _t->printStructElements(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SetTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SetTest.data,
      qt_meta_data_SetTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SetTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SetTest.stringdata))
        return static_cast<void*>(const_cast< SetTest*>(this));
    return QObject::qt_metacast(_clname);
}

int SetTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
