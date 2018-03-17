/****************************************************************************
** Meta object code from reading C++ file 'sensoray.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sensoray.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensoray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sensoray_t {
    QByteArrayData data[10];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sensoray_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sensoray_t qt_meta_stringdata_Sensoray = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Sensoray"
QT_MOC_LITERAL(1, 9, 27), // "signal_SerialPortConnection"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 38), // "common::comms::CommunicationC..."
QT_MOC_LITERAL(4, 77, 6), // "update"
QT_MOC_LITERAL(5, 84, 23), // "signal_SerialPortUpdate"
QT_MOC_LITERAL(6, 108, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(7, 143, 22), // "signal_RXNewSerialData"
QT_MOC_LITERAL(8, 166, 4), // "data"
QT_MOC_LITERAL(9, 171, 16) // "ConnectionStatus"

    },
    "Sensoray\0signal_SerialPortConnection\0"
    "\0common::comms::CommunicationConnection\0"
    "update\0signal_SerialPortUpdate\0"
    "common::comms::CommunicationUpdate\0"
    "signal_RXNewSerialData\0data\0"
    "ConnectionStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sensoray[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       7,    1,   40,    2, 0x06 /* Public */,
       9,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,

       0        // eod
};

void Sensoray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sensoray *_t = static_cast<Sensoray *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_SerialPortConnection((*reinterpret_cast< const common::comms::CommunicationConnection(*)>(_a[1]))); break;
        case 1: _t->signal_SerialPortUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 2: _t->signal_RXNewSerialData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->ConnectionStatus(); break;
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationUpdate >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Sensoray::*_t)(const common::comms::CommunicationConnection ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_SerialPortConnection)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)(const common::comms::CommunicationUpdate ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_SerialPortUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)(const QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::signal_RXNewSerialData)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Sensoray::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sensoray::ConnectionStatus)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Sensoray::staticMetaObject = {
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Sensoray::signal_SerialPortConnection(const common::comms::CommunicationConnection _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Sensoray::signal_SerialPortUpdate(const common::comms::CommunicationUpdate _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Sensoray::signal_RXNewSerialData(const QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Sensoray::ConnectionStatus()const
{
    QMetaObject::activate(const_cast< Sensoray *>(this), &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
