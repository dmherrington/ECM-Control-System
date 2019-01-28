/****************************************************************************
** Meta object code from reading C++ file 'library_qmodbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../library_qmodbus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'library_qmodbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Library_QModBus_t {
    QByteArrayData data[10];
    char stringdata0[196];
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
QT_MOC_LITERAL(5, 86, 31), // "signal_SerialPortReadyToConnect"
QT_MOC_LITERAL(6, 118, 25), // "signal_SerialPortNotReady"
QT_MOC_LITERAL(7, 144, 23), // "signal_SerialPortUpdate"
QT_MOC_LITERAL(8, 168, 22), // "signal_RXNewSerialData"
QT_MOC_LITERAL(9, 191, 4) // "data"

    },
    "Library_QModBus\0signal_CommunicationUpdate\0"
    "\0common::comms::CommunicationUpdate\0"
    "update\0signal_SerialPortReadyToConnect\0"
    "signal_SerialPortNotReady\0"
    "signal_SerialPortUpdate\0signal_RXNewSerialData\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Library_QModBus[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,
       7,    1,   44,    2, 0x06 /* Public */,
       8,    1,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QByteArray,    9,

       0        // eod
};

void Library_QModBus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Library_QModBus *_t = static_cast<Library_QModBus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_CommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 1: _t->signal_SerialPortReadyToConnect(); break;
        case 2: _t->signal_SerialPortNotReady(); break;
        case 3: _t->signal_SerialPortUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 4: _t->signal_RXNewSerialData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Library_QModBus::*)(const common::comms::CommunicationUpdate & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_CommunicationUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Library_QModBus::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_SerialPortReadyToConnect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Library_QModBus::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_SerialPortNotReady)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Library_QModBus::*)(const common::comms::CommunicationUpdate ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_SerialPortUpdate)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Library_QModBus::*)(const QByteArray ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Library_QModBus::signal_RXNewSerialData)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Library_QModBus::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Library_QModBus.data,
    qt_meta_data_Library_QModBus,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
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
void Library_QModBus::signal_SerialPortReadyToConnect()const
{
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Library_QModBus::signal_SerialPortNotReady()const
{
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Library_QModBus::signal_SerialPortUpdate(const common::comms::CommunicationUpdate _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Library_QModBus::signal_RXNewSerialData(const QByteArray _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Library_QModBus *>(this), &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
