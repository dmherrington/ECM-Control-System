/****************************************************************************
** Meta object code from reading C++ file 'additional_sensor_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../additional_sensor_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additional_sensor_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdditionalSensorDisplay_t {
    QByteArrayData data[24];
    char stringdata0[312];
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
QT_MOC_LITERAL(5, 72, 24), // "common_data::SensorTypes"
QT_MOC_LITERAL(6, 97, 4), // "type"
QT_MOC_LITERAL(7, 102, 18), // "WindowRangeChanged"
QT_MOC_LITERAL(8, 121, 4), // "left"
QT_MOC_LITERAL(9, 126, 5), // "right"
QT_MOC_LITERAL(10, 132, 20), // "SensorDisplayChanged"
QT_MOC_LITERAL(11, 153, 7), // "display"
QT_MOC_LITERAL(12, 161, 13), // "SchemeChanged"
QT_MOC_LITERAL(13, 175, 6), // "scheme"
QT_MOC_LITERAL(14, 182, 11), // "AxisChanged"
QT_MOC_LITERAL(15, 194, 5), // "lower"
QT_MOC_LITERAL(16, 200, 5), // "upper"
QT_MOC_LITERAL(17, 206, 17), // "ChangeColorScheme"
QT_MOC_LITERAL(18, 224, 26), // "CustomContextMenuRequested"
QT_MOC_LITERAL(19, 251, 3), // "pos"
QT_MOC_LITERAL(20, 255, 22), // "DisplayActionTriggered"
QT_MOC_LITERAL(21, 278, 17), // "OnDockVisibilitiy"
QT_MOC_LITERAL(22, 296, 7), // "visible"
QT_MOC_LITERAL(23, 304, 7) // "NewDock"

    },
    "AdditionalSensorDisplay\0CreateNewDock\0"
    "\0common::TupleSensorString\0sensor\0"
    "common_data::SensorTypes\0type\0"
    "WindowRangeChanged\0left\0right\0"
    "SensorDisplayChanged\0display\0SchemeChanged\0"
    "scheme\0AxisChanged\0lower\0upper\0"
    "ChangeColorScheme\0CustomContextMenuRequested\0"
    "pos\0DisplayActionTriggered\0OnDockVisibilitiy\0"
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
        case 0: _t->CreateNewDock((*reinterpret_cast< common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< common_data::SensorTypes(*)>(_a[2]))); break;
        case 1: _t->WindowRangeChanged((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 2: _t->SensorDisplayChanged((*reinterpret_cast< common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->SchemeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->AxisChanged((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 5: _t->ChangeColorScheme((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->CustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->DisplayActionTriggered(); break;
        case 8: _t->OnDockVisibilitiy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->NewDock((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const common_data::SensorTypes(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AdditionalSensorDisplay::*_t)(common::TupleSensorString , common_data::SensorTypes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::CreateNewDock)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AdditionalSensorDisplay::*_t)(QDateTime , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::WindowRangeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AdditionalSensorDisplay::*_t)(common::TupleSensorString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::SensorDisplayChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AdditionalSensorDisplay::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::SchemeChanged)) {
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
        return static_cast<void*>(this);
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AdditionalSensorDisplay::CreateNewDock(common::TupleSensorString _t1, common_data::SensorTypes _t2)
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
