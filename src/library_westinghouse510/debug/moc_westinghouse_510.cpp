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
    QByteArrayData data[15];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Westinghouse510_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Westinghouse510_t qt_meta_stringdata_Westinghouse510 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Westinghouse510"
QT_MOC_LITERAL(1, 16, 27), // "signal_PumpConnectionUpdate"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 38), // "common::comms::CommunicationC..."
QT_MOC_LITERAL(4, 84, 5), // "value"
QT_MOC_LITERAL(5, 90, 22), // "signal_PumpFlowUpdated"
QT_MOC_LITERAL(6, 113, 20), // "signal_PumpOperating"
QT_MOC_LITERAL(7, 134, 29), // "slot_SerialPortReadyToConnect"
QT_MOC_LITERAL(8, 164, 31), // "slot_SerialPortConnectionUpdate"
QT_MOC_LITERAL(9, 196, 6), // "update"
QT_MOC_LITERAL(10, 203, 27), // "slot_SerialPortStatusUpdate"
QT_MOC_LITERAL(11, 231, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(12, 266, 10), // "connection"
QT_MOC_LITERAL(13, 277, 27), // "slot_SerialPortReceivedData"
QT_MOC_LITERAL(14, 305, 4) // "data"

    },
    "Westinghouse510\0signal_PumpConnectionUpdate\0"
    "\0common::comms::CommunicationConnection\0"
    "value\0signal_PumpFlowUpdated\0"
    "signal_PumpOperating\0slot_SerialPortReadyToConnect\0"
    "slot_SerialPortConnectionUpdate\0update\0"
    "slot_SerialPortStatusUpdate\0"
    "common::comms::CommunicationUpdate\0"
    "connection\0slot_SerialPortReceivedData\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Westinghouse510[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   58,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,
      10,    1,   62,    2, 0x08 /* Private */,
      13,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QByteArray,   14,

       0        // eod
};

void Westinghouse510::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Westinghouse510 *_t = static_cast<Westinghouse510 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_PumpConnectionUpdate((*reinterpret_cast< const common::comms::CommunicationConnection(*)>(_a[1]))); break;
        case 1: _t->signal_PumpFlowUpdated((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 2: _t->signal_PumpOperating((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 3: _t->slot_SerialPortReadyToConnect(); break;
        case 4: _t->slot_SerialPortConnectionUpdate((*reinterpret_cast< const common::comms::CommunicationConnection(*)>(_a[1]))); break;
        case 5: _t->slot_SerialPortStatusUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 6: _t->slot_SerialPortReceivedData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
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
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationConnection >(); break;
            }
            break;
        case 5:
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
            typedef void (Westinghouse510::*_t)(const common::comms::CommunicationConnection & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Westinghouse510::signal_PumpConnectionUpdate)) {
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
    return QObject::qt_metacast(_clname);
}

int Westinghouse510::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Westinghouse510::signal_PumpConnectionUpdate(const common::comms::CommunicationConnection & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Westinghouse510 *>(this), &staticMetaObject, 0, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
