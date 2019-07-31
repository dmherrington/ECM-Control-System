/****************************************************************************
** Meta object code from reading C++ file 'plc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PLC_t {
    QByteArrayData data[9];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PLC_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PLC_t qt_meta_stringdata_PLC = {
    {
QT_MOC_LITERAL(0, 0, 3), // "PLC"
QT_MOC_LITERAL(1, 4, 26), // "signal_CommunicationUpdate"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(4, 67, 3), // "obj"
QT_MOC_LITERAL(5, 71, 15), // "slot_PortUpdate"
QT_MOC_LITERAL(6, 87, 6), // "update"
QT_MOC_LITERAL(7, 94, 21), // "slot_PortReceivedData"
QT_MOC_LITERAL(8, 116, 4) // "data"

    },
    "PLC\0signal_CommunicationUpdate\0\0"
    "common::comms::CommunicationUpdate\0"
    "obj\0slot_PortUpdate\0update\0"
    "slot_PortReceivedData\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PLC[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   32,    2, 0x08 /* Private */,
       7,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, QMetaType::QByteArray,    8,

       0        // eod
};

void PLC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PLC *_t = static_cast<PLC *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_CommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 1: _t->slot_PortUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 2: _t->slot_PortReceivedData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
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
            typedef void (PLC::*_t)(const common::comms::CommunicationUpdate & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PLC::signal_CommunicationUpdate)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PLC::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PLC.data,
      qt_meta_data_PLC,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PLC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PLC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PLC.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PLCPollingEvents_Interface"))
        return static_cast< PLCPollingEvents_Interface*>(this);
    return QObject::qt_metacast(_clname);
}

int PLC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PLC::signal_CommunicationUpdate(const common::comms::CommunicationUpdate & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
