/****************************************************************************
** Meta object code from reading C++ file 'additional_sensor_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../additional_sensor_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additional_sensor_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdditionalSensorDisplay_t {
    QByteArrayData data[27];
    char stringdata0[391];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdditionalSensorDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdditionalSensorDisplay_t qt_meta_stringdata_AdditionalSensorDisplay = {
    {
QT_MOC_LITERAL(0, 0, 23), // "AdditionalSensorDisplay"
QT_MOC_LITERAL(1, 24, 28), // "signal_DialogWindowVisibilty"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 38), // "GeneralDialogWindow::DialogWi..."
QT_MOC_LITERAL(4, 93, 4), // "type"
QT_MOC_LITERAL(5, 98, 10), // "visibility"
QT_MOC_LITERAL(6, 109, 13), // "CreateNewDock"
QT_MOC_LITERAL(7, 123, 25), // "common::TupleSensorString"
QT_MOC_LITERAL(8, 149, 6), // "sensor"
QT_MOC_LITERAL(9, 156, 24), // "common_data::SensorTypes"
QT_MOC_LITERAL(10, 181, 18), // "WindowRangeChanged"
QT_MOC_LITERAL(11, 200, 4), // "left"
QT_MOC_LITERAL(12, 205, 5), // "right"
QT_MOC_LITERAL(13, 211, 20), // "SensorDisplayChanged"
QT_MOC_LITERAL(14, 232, 7), // "display"
QT_MOC_LITERAL(15, 240, 13), // "SchemeChanged"
QT_MOC_LITERAL(16, 254, 6), // "scheme"
QT_MOC_LITERAL(17, 261, 11), // "AxisChanged"
QT_MOC_LITERAL(18, 273, 5), // "lower"
QT_MOC_LITERAL(19, 279, 5), // "upper"
QT_MOC_LITERAL(20, 285, 17), // "ChangeColorScheme"
QT_MOC_LITERAL(21, 303, 26), // "CustomContextMenuRequested"
QT_MOC_LITERAL(22, 330, 3), // "pos"
QT_MOC_LITERAL(23, 334, 22), // "DisplayActionTriggered"
QT_MOC_LITERAL(24, 357, 17), // "OnDockVisibilitiy"
QT_MOC_LITERAL(25, 375, 7), // "visible"
QT_MOC_LITERAL(26, 383, 7) // "NewDock"

    },
    "AdditionalSensorDisplay\0"
    "signal_DialogWindowVisibilty\0\0"
    "GeneralDialogWindow::DialogWindowTypes\0"
    "type\0visibility\0CreateNewDock\0"
    "common::TupleSensorString\0sensor\0"
    "common_data::SensorTypes\0WindowRangeChanged\0"
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
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       6,    2,   74,    2, 0x06 /* Public */,
      10,    2,   79,    2, 0x06 /* Public */,
      13,    2,   84,    2, 0x06 /* Public */,
      15,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    2,   92,    2, 0x0a /* Public */,
      20,    1,   97,    2, 0x0a /* Public */,
      21,    1,  100,    2, 0x08 /* Private */,
      23,    0,  103,    2, 0x08 /* Private */,
      24,    1,  104,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      26,    2,  107,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9,    8,    4,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,   11,   12,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool,    8,   14,
    QMetaType::Void, QMetaType::Bool,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,   18,   19,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::QPoint,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9,    8,    4,

       0        // eod
};

void AdditionalSensorDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdditionalSensorDisplay *_t = static_cast<AdditionalSensorDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_DialogWindowVisibilty((*reinterpret_cast< const GeneralDialogWindow::DialogWindowTypes(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->CreateNewDock((*reinterpret_cast< common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< common_data::SensorTypes(*)>(_a[2]))); break;
        case 2: _t->WindowRangeChanged((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 3: _t->SensorDisplayChanged((*reinterpret_cast< common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->SchemeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->AxisChanged((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 6: _t->ChangeColorScheme((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->CustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->DisplayActionTriggered(); break;
        case 9: _t->OnDockVisibilitiy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->NewDock((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const common_data::SensorTypes(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            }
            break;
        case 10:
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
            using _t = void (AdditionalSensorDisplay::*)(const GeneralDialogWindow::DialogWindowTypes & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::signal_DialogWindowVisibilty)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdditionalSensorDisplay::*)(common::TupleSensorString , common_data::SensorTypes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::CreateNewDock)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AdditionalSensorDisplay::*)(QDateTime , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::WindowRangeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AdditionalSensorDisplay::*)(common::TupleSensorString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::SensorDisplayChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AdditionalSensorDisplay::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdditionalSensorDisplay::SchemeChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdditionalSensorDisplay::staticMetaObject = {
    { &GeneralDialogWindow::staticMetaObject, qt_meta_stringdata_AdditionalSensorDisplay.data,
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
    return GeneralDialogWindow::qt_metacast(_clname);
}

int AdditionalSensorDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeneralDialogWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void AdditionalSensorDisplay::signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AdditionalSensorDisplay::CreateNewDock(common::TupleSensorString _t1, common_data::SensorTypes _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AdditionalSensorDisplay::WindowRangeChanged(QDateTime _t1, QDateTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AdditionalSensorDisplay::SensorDisplayChanged(common::TupleSensorString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AdditionalSensorDisplay::SchemeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
