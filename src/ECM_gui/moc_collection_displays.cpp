/****************************************************************************
** Meta object code from reading C++ file 'collection_displays.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SensorDisplay/collection_displays.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'collection_displays.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CollectionDisplays_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CollectionDisplays_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CollectionDisplays_t qt_meta_stringdata_CollectionDisplays = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CollectionDisplays"
QT_MOC_LITERAL(1, 19, 20), // "DistributeUpdateAxis"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "leftTime"
QT_MOC_LITERAL(4, 50, 9), // "rightTime"
QT_MOC_LITERAL(5, 60, 27), // "DistributeChangeColorScheme"
QT_MOC_LITERAL(6, 88, 6) // "scheme"

    },
    "CollectionDisplays\0DistributeUpdateAxis\0"
    "\0leftTime\0rightTime\0DistributeChangeColorScheme\0"
    "scheme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CollectionDisplays[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x0a /* Public */,
       5,    1,   29,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void CollectionDisplays::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CollectionDisplays *_t = static_cast<CollectionDisplays *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DistributeUpdateAxis((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 1: _t->DistributeChangeColorScheme((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CollectionDisplays::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CollectionDisplays.data,
      qt_meta_data_CollectionDisplays,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CollectionDisplays::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CollectionDisplays::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CollectionDisplays.stringdata0))
        return static_cast<void*>(const_cast< CollectionDisplays*>(this));
    return QObject::qt_metacast(_clname);
}

int CollectionDisplays::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
