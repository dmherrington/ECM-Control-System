/****************************************************************************
** Meta object code from reading C++ file 'abstract_communication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../comms/abstract_communication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstract_communication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_common__comms__AbstractCommunication_t {
    QByteArrayData data[7];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_common__comms__AbstractCommunication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_common__comms__AbstractCommunication_t qt_meta_stringdata_common__comms__AbstractCommunication = {
    {
QT_MOC_LITERAL(0, 0, 36), // "common::comms::AbstractCommun..."
QT_MOC_LITERAL(1, 37, 33), // "signal_SerialPortConnectionUp..."
QT_MOC_LITERAL(2, 71, 0), // ""
QT_MOC_LITERAL(3, 72, 19), // "CommunicationUpdate"
QT_MOC_LITERAL(4, 92, 6), // "update"
QT_MOC_LITERAL(5, 99, 22), // "signal_RXNewSerialData"
QT_MOC_LITERAL(6, 122, 4) // "data"

    },
    "common::comms::AbstractCommunication\0"
    "signal_SerialPortConnectionUpdate\0\0"
    "CommunicationUpdate\0update\0"
    "signal_RXNewSerialData\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_common__comms__AbstractCommunication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QByteArray,    6,

       0        // eod
};

void common::comms::AbstractCommunication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractCommunication *_t = static_cast<AbstractCommunication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_SerialPortConnectionUpdate((*reinterpret_cast< const CommunicationUpdate(*)>(_a[1]))); break;
        case 1: _t->signal_RXNewSerialData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AbstractCommunication::*_t)(const CommunicationUpdate & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractCommunication::signal_SerialPortConnectionUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AbstractCommunication::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractCommunication::signal_RXNewSerialData)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject common::comms::AbstractCommunication::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_common__comms__AbstractCommunication.data,
      qt_meta_data_common__comms__AbstractCommunication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *common::comms::AbstractCommunication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *common::comms::AbstractCommunication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_common__comms__AbstractCommunication.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int common::comms::AbstractCommunication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void common::comms::AbstractCommunication::signal_SerialPortConnectionUpdate(const CommunicationUpdate & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< common::comms::AbstractCommunication *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void common::comms::AbstractCommunication::signal_RXNewSerialData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
