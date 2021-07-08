/****************************************************************************
** Meta object code from reading C++ file 'sensoray.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sensoray.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensoray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sensoray_t {
    QByteArrayData data[19];
    char stringdata0[382];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sensoray_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sensoray_t qt_meta_stringdata_Sensoray = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Sensoray"
QT_MOC_LITERAL(1, 9, 34), // "signal_SensorayCommunicationU..."
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(4, 80, 6), // "update"
QT_MOC_LITERAL(5, 87, 25), // "signal_PortReadyToConnect"
QT_MOC_LITERAL(6, 113, 19), // "signal_PortNotReady"
QT_MOC_LITERAL(7, 133, 17), // "signal_PortUpdate"
QT_MOC_LITERAL(8, 151, 20), // "signal_RXNewPortData"
QT_MOC_LITERAL(9, 172, 4), // "data"
QT_MOC_LITERAL(10, 177, 29), // "signal_PortFailedTransmission"
QT_MOC_LITERAL(11, 207, 14), // "ModbusRegister"
QT_MOC_LITERAL(12, 222, 6), // "regMsg"
QT_MOC_LITERAL(13, 229, 29), // "signal_SensorayNewSensorValue"
QT_MOC_LITERAL(14, 259, 25), // "common::TupleSensorString"
QT_MOC_LITERAL(15, 285, 11), // "sensorTuple"
QT_MOC_LITERAL(16, 297, 24), // "common_data::SensorState"
QT_MOC_LITERAL(17, 322, 32), // "signal_SensoryNotificationUpdate"
QT_MOC_LITERAL(18, 355, 26) // "common::NotificationUpdate"

    },
    "Sensoray\0signal_SensorayCommunicationUpdate\0"
    "\0common::comms::CommunicationUpdate\0"
    "update\0signal_PortReadyToConnect\0"
    "signal_PortNotReady\0signal_PortUpdate\0"
    "signal_RXNewPortData\0data\0"
    "signal_PortFailedTransmission\0"
    "ModbusRegister\0regMsg\0"
    "signal_SensorayNewSensorValue\0"
    "common::TupleSensorString\0sensorTuple\0"
    "common_data::SensorState\0"
    "signal_SensoryNotificationUpdate\0"
    "common::NotificationUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sensoray[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    1,   59,    2, 0x06 /* Public */,
       8,    1,   62,    2, 0x06 /* Public */,
      10,    2,   65,    2, 0x06 /* Public */,
      13,    2,   70,    2, 0x06 /* Public */,
      17,    1,   75,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 11,    4,   12,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16,   15,    9,
    QMetaType::Void, 0x80000000 | 18,    4,

       0        // eod
};

void Sensoray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sensoray *_t = static_cast<Sensoray *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_SensorayCommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 1: _t->signal_PortReadyToConnect(); break;
        case 2: _t->signal_PortNotReady(); break;
        case 3: _t->signal_PortUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 4: _t->signal_RXNewPortData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->signal_PortFailedTransmission((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1])),(*reinterpret_cast< const ModbusRegister(*)>(_a[2]))); break;
        case 6: _t->signal_SensorayNewSensorValue((*reinterpret_cast< const common::TupleSensorString(*)>(_a[1])),(*reinterpret_cast< const common_data::SensorState(*)>(_a[2]))); break;
        case 7: _t->signal_SensoryNotificationUpdate((*reinterpret_cast< const common::NotificationUpdate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationUpdate >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationUpdate >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationUpdate >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleSensorString >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::SensorState >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::NotificationUpdate >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Sensoray::*_t)(const common::comms::CommunicationUpdate & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_SensorayCommunicationUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_PortReadyToConnect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_PortNotReady)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)(const common::comms::CommunicationUpdate ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_PortUpdate)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)(const QByteArray ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_RXNewPortData)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)(const common::comms::CommunicationUpdate & , const ModbusRegister & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_PortFailedTransmission)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)(const common::TupleSensorString & , const common_data::SensorState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_SensorayNewSensorValue)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)(const common::NotificationUpdate & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_SensoryNotificationUpdate)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Sensoray::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Sensoray.data,
      qt_meta_data_Sensoray,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Sensoray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sensoray::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sensoray.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "common::comms::ICommunication"))
        return static_cast< common::comms::ICommunication*>(this);
    if (!strcmp(_clname, "comms_Sensoray::CommsEvents"))
        return static_cast< comms_Sensoray::CommsEvents*>(this);
    if (!strcmp(_clname, "ICommunication"))
        return static_cast< common::comms::ICommunication*>(this);
    return QObject::qt_metacast(_clname);
}

int Sensoray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Sensoray::signal_SensorayCommunicationUpdate(const common::comms::CommunicationUpdate & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Sensoray::signal_PortReadyToConnect()const
{
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Sensoray::signal_PortNotReady()const
{
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Sensoray::signal_PortUpdate(const common::comms::CommunicationUpdate _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Sensoray::signal_RXNewPortData(const QByteArray _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Sensoray::signal_PortFailedTransmission(const common::comms::CommunicationUpdate & _t1, const ModbusRegister & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Sensoray::signal_SensorayNewSensorValue(const common::TupleSensorString & _t1, const common_data::SensorState & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Sensoray::signal_SensoryNotificationUpdate(const common::NotificationUpdate & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
