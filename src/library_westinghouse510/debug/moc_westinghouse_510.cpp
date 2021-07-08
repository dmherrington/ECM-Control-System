/****************************************************************************
** Meta object code from reading C++ file 'westinghouse_510.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../westinghouse_510.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'westinghouse_510.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Westinghouse510_t {
    QByteArrayData data[21];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Westinghouse510_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Westinghouse510_t qt_meta_stringdata_Westinghouse510 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Westinghouse510"
QT_MOC_LITERAL(1, 16, 30), // "signal_PumpCommunicationUpdate"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(4, 83, 3), // "obj"
QT_MOC_LITERAL(5, 87, 22), // "signal_PumpFlowUpdated"
QT_MOC_LITERAL(6, 110, 5), // "value"
QT_MOC_LITERAL(7, 116, 20), // "signal_PumpOperating"
QT_MOC_LITERAL(8, 137, 36), // "signal_PumpInitializationTime..."
QT_MOC_LITERAL(9, 174, 23), // "signal_PumpNotification"
QT_MOC_LITERAL(10, 198, 26), // "common::NotificationUpdate"
QT_MOC_LITERAL(11, 225, 12), // "notification"
QT_MOC_LITERAL(12, 238, 29), // "slot_SerialPortReadyToConnect"
QT_MOC_LITERAL(13, 268, 15), // "slot_PortUpdate"
QT_MOC_LITERAL(14, 284, 6), // "update"
QT_MOC_LITERAL(15, 291, 27), // "slot_SerialPortReceivedData"
QT_MOC_LITERAL(16, 319, 4), // "data"
QT_MOC_LITERAL(17, 324, 31), // "slot_PumpInitializationComplete"
QT_MOC_LITERAL(18, 356, 27), // "slot_PortFailedTransmission"
QT_MOC_LITERAL(19, 384, 14), // "ModbusRegister"
QT_MOC_LITERAL(20, 399, 6) // "regMsg"

    },
    "Westinghouse510\0signal_PumpCommunicationUpdate\0"
    "\0common::comms::CommunicationUpdate\0"
    "obj\0signal_PumpFlowUpdated\0value\0"
    "signal_PumpOperating\0"
    "signal_PumpInitializationTimeUpdated\0"
    "signal_PumpNotification\0"
    "common::NotificationUpdate\0notification\0"
    "slot_SerialPortReadyToConnect\0"
    "slot_PortUpdate\0update\0"
    "slot_SerialPortReceivedData\0data\0"
    "slot_PumpInitializationComplete\0"
    "slot_PortFailedTransmission\0ModbusRegister\0"
    "regMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Westinghouse510[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,
       9,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   79,    2, 0x08 /* Private */,
      13,    1,   80,    2, 0x08 /* Private */,
      15,    1,   83,    2, 0x08 /* Private */,
      17,    0,   86,    2, 0x08 /* Private */,
      18,    2,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   14,
    QMetaType::Void, QMetaType::QByteArray,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 19,   14,   20,

       0        // eod
};

void Westinghouse510::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Westinghouse510 *_t = static_cast<Westinghouse510 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_PumpCommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 1: _t->signal_PumpFlowUpdated((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 2: _t->signal_PumpOperating((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 3: _t->signal_PumpInitializationTimeUpdated((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->signal_PumpNotification((*reinterpret_cast< const common::NotificationUpdate(*)>(_a[1]))); break;
        case 5: _t->slot_SerialPortReadyToConnect(); break;
        case 6: _t->slot_PortUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 7: _t->slot_SerialPortReceivedData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 8: _t->slot_PumpInitializationComplete(); break;
        case 9: _t->slot_PortFailedTransmission((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1])),(*reinterpret_cast< const ModbusRegister(*)>(_a[2]))); break;
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
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::NotificationUpdate >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationUpdate >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationUpdate >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Westinghouse510::*_t)(const common::comms::CommunicationUpdate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Westinghouse510::signal_PumpCommunicationUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Westinghouse510::*_t)(const double & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Westinghouse510::signal_PumpFlowUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Westinghouse510::*_t)(const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Westinghouse510::signal_PumpOperating)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Westinghouse510::*_t)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Westinghouse510::signal_PumpInitializationTimeUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Westinghouse510::*_t)(const common::NotificationUpdate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Westinghouse510::signal_PumpNotification)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Westinghouse510::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Westinghouse510.data,
      qt_meta_data_Westinghouse510,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Westinghouse510::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Westinghouse510::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Westinghouse510.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "DeviceInterface_Pump"))
        return static_cast< DeviceInterface_Pump*>(this);
    return QObject::qt_metacast(_clname);
}

int Westinghouse510::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Westinghouse510::signal_PumpCommunicationUpdate(const common::comms::CommunicationUpdate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Westinghouse510::signal_PumpFlowUpdated(const double & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Westinghouse510::signal_PumpOperating(const bool & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Westinghouse510::signal_PumpInitializationTimeUpdated(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Westinghouse510::signal_PumpNotification(const common::NotificationUpdate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
