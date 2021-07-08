/****************************************************************************
** Meta object code from reading C++ file 'library_qmodbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../library_qmodbus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'library_qmodbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Library_QModBus_t {
    QByteArrayData data[15];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Library_QModBus_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Library_QModBus_t qt_meta_stringdata_Library_QModBus = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Library_QModBus"
QT_MOC_LITERAL(1, 16, 26), // "signal_CommunicationUpdate"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(4, 79, 6), // "update"
QT_MOC_LITERAL(5, 86, 25), // "signal_PortReadyToConnect"
QT_MOC_LITERAL(6, 112, 19), // "signal_PortNotReady"
QT_MOC_LITERAL(7, 132, 17), // "signal_PortUpdate"
QT_MOC_LITERAL(8, 150, 20), // "signal_RXNewPortData"
QT_MOC_LITERAL(9, 171, 4), // "data"
QT_MOC_LITERAL(10, 176, 20), // "signal_RXNewRegister"
QT_MOC_LITERAL(11, 197, 14), // "ModbusRegister"
QT_MOC_LITERAL(12, 212, 6), // "regObj"
QT_MOC_LITERAL(13, 219, 29), // "signal_PortFailedTransmission"
QT_MOC_LITERAL(14, 249, 6) // "regMsg"

    },
    "Library_QModBus\0signal_CommunicationUpdate\0"
    "\0common::comms::CommunicationUpdate\0"
    "update\0signal_PortReadyToConnect\0"
    "signal_PortNotReady\0signal_PortUpdate\0"
    "signal_RXNewPortData\0data\0"
    "signal_RXNewRegister\0ModbusRegister\0"
    "regObj\0signal_PortFailedTransmission\0"
    "regMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Library_QModBus[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    1,   54,    2, 0x06 /* Public */,
       8,    1,   57,    2, 0x06 /* Public */,
      10,    1,   60,    2, 0x06 /* Public */,
      13,    2,   63,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 11,    4,   14,

       0        // eod
};

void Library_QModBus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Library_QModBus *_t = static_cast<Library_QModBus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_CommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 1: _t->signal_PortReadyToConnect(); break;
        case 2: _t->signal_PortNotReady(); break;
        case 3: _t->signal_PortUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 4: _t->signal_RXNewPortData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->signal_RXNewRegister((*reinterpret_cast< const ModbusRegister(*)>(_a[1]))); break;
        case 6: _t->signal_PortFailedTransmission((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1])),(*reinterpret_cast< const ModbusRegister(*)>(_a[2]))); break;
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
        case 6:
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
            typedef void (Library_QModBus::*_t)(const common::comms::CommunicationUpdate & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_CommunicationUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Library_QModBus::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_PortReadyToConnect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Library_QModBus::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_PortNotReady)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Library_QModBus::*_t)(const common::comms::CommunicationUpdate ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_PortUpdate)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Library_QModBus::*_t)(const QByteArray ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_RXNewPortData)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Library_QModBus::*_t)(const ModbusRegister & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_RXNewRegister)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Library_QModBus::*_t)(const common::comms::CommunicationUpdate & , const ModbusRegister & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_PortFailedTransmission)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Library_QModBus::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Library_QModBus.data,
      qt_meta_data_Library_QModBus,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Library_QModBus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Library_QModBus::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Library_QModBus.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "common::comms::ICommunication"))
        return static_cast< common::comms::ICommunication*>(this);
    if (!strcmp(_clname, "comms_QModBus::CommsEvents"))
        return static_cast< comms_QModBus::CommsEvents*>(this);
    if (!strcmp(_clname, "ICommunication"))
        return static_cast< common::comms::ICommunication*>(this);
    return QObject::qt_metacast(_clname);
}

int Library_QModBus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Library_QModBus::signal_CommunicationUpdate(const common::comms::CommunicationUpdate & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Library_QModBus::signal_PortReadyToConnect()const
{
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Library_QModBus::signal_PortNotReady()const
{
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Library_QModBus::signal_PortUpdate(const common::comms::CommunicationUpdate _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Library_QModBus::signal_RXNewPortData(const QByteArray _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Library_QModBus::signal_RXNewRegister(const ModbusRegister & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Library_QModBus::signal_PortFailedTransmission(const common::comms::CommunicationUpdate & _t1, const ModbusRegister & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
