/****************************************************************************
** Meta object code from reading C++ file 'rigol_oscilliscope.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rigol_oscilliscope.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rigol_oscilliscope.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RigolOscilliscope_t {
    QByteArrayData data[12];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RigolOscilliscope_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RigolOscilliscope_t qt_meta_stringdata_RigolOscilliscope = {
    {
QT_MOC_LITERAL(0, 0, 17), // "RigolOscilliscope"
QT_MOC_LITERAL(1, 18, 28), // "signal_RigolConnectionUpdate"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 38), // "common::comms::CommunicationC..."
QT_MOC_LITERAL(4, 87, 5), // "value"
QT_MOC_LITERAL(5, 93, 21), // "signal_RigolPlottable"
QT_MOC_LITERAL(6, 115, 25), // "common::TupleSensorString"
QT_MOC_LITERAL(7, 141, 11), // "sensorTuple"
QT_MOC_LITERAL(8, 153, 6), // "on_off"
QT_MOC_LITERAL(9, 160, 26), // "signal_RigolNewSensorValue"
QT_MOC_LITERAL(10, 187, 24), // "common_data::SensorState"
QT_MOC_LITERAL(11, 212, 4) // "data"

    },
    "RigolOscilliscope\0signal_RigolConnectionUpdate\0"
    "\0common::comms::CommunicationConnection\0"
    "value\0signal_RigolPlottable\0"
    "common::TupleSensorString\0sensorTuple\0"
    "on_off\0signal_RigolNewSensorValue\0"
    "common_data::SensorState\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RigolOscilliscope[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    2,   32,    2, 0x06 /* Public */,
       9,    2,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Bool,    7,    8,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 10,    7,   11,

       0        // eod
};

void RigolOscilliscope::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RigolOscilliscope *_t = static_cast<RigolOscilliscope *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_RigolConnectionUpdate((*reinterpret_cast< const common::comms::CommunicationConnection(*)>(_a[1]))); break;
        case 1: _t->signal_RigolPlottable((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 2: _t->signal_RigolNewSensorValue((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const common_data::SensorState(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationConnection >(); break;
            }
            break;
        case 1:
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
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::SensorState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RigolOscilliscope::*_t)(const common::comms::CommunicationConnection & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RigolOscilliscope::signal_RigolConnectionUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RigolOscilliscope::*_t)(const common::TupleSensorString & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RigolOscilliscope::signal_RigolPlottable)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RigolOscilliscope::*_t)(const common::TupleSensorString & , const common_data::SensorState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RigolOscilliscope::signal_RigolNewSensorValue)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject RigolOscilliscope::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RigolOscilliscope.data,
      qt_meta_data_RigolOscilliscope,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RigolOscilliscope::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RigolOscilliscope::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RigolOscilliscope.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RigolMeasurementUpdates_Interface"))
        return static_cast< RigolMeasurementUpdates_Interface*>(this);
    if (!strcmp(_clname, "comms_Rigol::CommsEvents"))
        return static_cast< comms_Rigol::CommsEvents*>(this);
    return QObject::qt_metacast(_clname);
}

int RigolOscilliscope::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RigolOscilliscope::signal_RigolConnectionUpdate(const common::comms::CommunicationConnection & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< RigolOscilliscope *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RigolOscilliscope::signal_RigolPlottable(const common::TupleSensorString & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RigolOscilliscope::signal_RigolNewSensorValue(const common::TupleSensorString & _t1, const common_data::SensorState & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< RigolOscilliscope *>(this), &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE