/****************************************************************************
** Meta object code from reading C++ file 'additional_sensor_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "additional_sensor_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additional_sensor_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdditionalSensorDisplay_t {
    QByteArrayData data[24];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdditionalSensorDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdditionalSensorDisplay_t qt_meta_stringdata_AdditionalSensorDisplay = {
    {
QT_MOC_LITERAL(0, 0, 23), // "AdditionalSensorDisplay"
QT_MOC_LITERAL(1, 24, 13), // "CreateNewDock"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 25), // "common::TupleSensorString"
QT_MOC_LITERAL(4, 65, 6), // "sensor"
QT_MOC_LITERAL(5, 72, 17), // "data::SensorTypes"
QT_MOC_LITERAL(6, 90, 4), // "type"
QT_MOC_LITERAL(7, 95, 18), // "WindowRangeChanged"
QT_MOC_LITERAL(8, 114, 4), // "left"
QT_MOC_LITERAL(9, 119, 5), // "right"
QT_MOC_LITERAL(10, 125, 20), // "SensorDisplayChanged"
QT_MOC_LITERAL(11, 146, 7), // "display"
QT_MOC_LITERAL(12, 154, 13), // "SchemeChanged"
QT_MOC_LITERAL(13, 168, 6), // "scheme"
QT_MOC_LITERAL(14, 175, 11), // "AxisChanged"
QT_MOC_LITERAL(15, 187, 5), // "lower"
QT_MOC_LITERAL(16, 193, 5), // "upper"
QT_MOC_LITERAL(17, 199, 17), // "ChangeColorScheme"
QT_MOC_LITERAL(18, 217, 26), // "CustomContextMenuRequested"
QT_MOC_LITERAL(19, 244, 3), // "pos"
QT_MOC_LITERAL(20, 248, 22), // "DisplayActionTriggered"
QT_MOC_LITERAL(21, 271, 17), // "OnDockVisibilitiy"
QT_MOC_LITERAL(22, 289, 7), // "visible"
QT_MOC_LITERAL(23, 297, 7) // "NewDock"

    },
    "AdditionalSensorDisplay\0CreateNewDock\0"
    "\0common::TupleSensorString\0sensor\0"
    "data::SensorTypes\0type\0WindowRangeChanged\0"
    "left\0right\0SensorDisplayChanged\0display\0"
    "SchemeChanged\0scheme\0AxisChanged\0lower\0"
    "upper\0ChangeColorScheme\0"
    "CustomContextMenuRequested\0pos\0"
    "DisplayActionTriggered\0OnDockVisibilitiy\0"
    "visible\0NewDock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdditionalSensorDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       7,    2,   69,    2, 0x06 /* Public */,
      10,    2,   74,    2, 0x06 /* Public */,
      12,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,   82,    2, 0x0a /* Public */,
      17,    1,   87,    2, 0x0a /* Public */,
      18,    1,   90,    2, 0x08 /* Private */,
      20,    0,   93,    2, 0x08 /* Private */,
      21,    1,   94,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      23,    2,   97,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,    8,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,   11,
    QMetaType::Void, QMetaType::Bool,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,   15,   16,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QPoint,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void AdditionalSensorDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdditionalSensorDisplay *_t = static_cast<AdditionalSensorDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateNewDock((*reinterpret_cast< common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< data::SensorTypes(*)>(_a[2]))); break;
        case 1: _t->WindowRangeChanged((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 2: _t->SensorDisplayChanged((*reinterpret_cast< common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->SchemeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->AxisChanged((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 5: _t->ChangeColorScheme((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->CustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->DisplayActionTriggered(); break;
        case 8: _t->OnDockVisibilitiy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->NewDock((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const data::SensorTypes(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AdditionalSensorDisplay::*_t)(common::TupleSensorString , data::SensorTypes );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdditionalSensorDisplay::CreateNewDock)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AdditionalSensorDisplay::*_t)(QDateTime , QDateTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdditionalSensorDisplay::WindowRangeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AdditionalSensorDisplay::*_t)(common::TupleSensorString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdditionalSensorDisplay::SensorDisplayChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AdditionalSensorDisplay::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdditionalSensorDisplay::SchemeChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject AdditionalSensorDisplay::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AdditionalSensorDisplay.data,
      qt_meta_data_AdditionalSensorDisplay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AdditionalSensorDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdditionalSensorDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdditionalSensorDisplay.stringdata0))
        return static_cast<void*>(const_cast< AdditionalSensorDisplay*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AdditionalSensorDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AdditionalSensorDisplay::CreateNewDock(common::TupleSensorString _t1, data::SensorTypes _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AdditionalSensorDisplay::WindowRangeChanged(QDateTime _t1, QDateTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AdditionalSensorDisplay::SensorDisplayChanged(common::TupleSensorString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AdditionalSensorDisplay::SchemeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
