/****************************************************************************
** Meta object code from reading C++ file 'ecm_api.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ecm_api.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ecm_api.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ECM_API_t {
    QByteArrayData data[15];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ECM_API_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ECM_API_t qt_meta_stringdata_ECM_API = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ECM_API"
QT_MOC_LITERAL(1, 8, 24), // "signal_LockMotionButtons"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "lock"
QT_MOC_LITERAL(4, 39, 23), // "signal_MCNewMotionState"
QT_MOC_LITERAL(5, 63, 11), // "std::string"
QT_MOC_LITERAL(6, 75, 11), // "stateString"
QT_MOC_LITERAL(7, 87, 40), // "slot_MotionControllerCommunic..."
QT_MOC_LITERAL(8, 128, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(9, 163, 6), // "update"
QT_MOC_LITERAL(10, 170, 29), // "slot_UpdateMotionProfileState"
QT_MOC_LITERAL(11, 200, 18), // "MotionProfileState"
QT_MOC_LITERAL(12, 219, 5), // "state"
QT_MOC_LITERAL(13, 225, 21), // "slot_MCNewMotionState"
QT_MOC_LITERAL(14, 247, 22) // "ECM::Galil::GalilState"

    },
    "ECM_API\0signal_LockMotionButtons\0\0"
    "lock\0signal_MCNewMotionState\0std::string\0"
    "stateString\0slot_MotionControllerCommunicationUpdate\0"
    "common::comms::CommunicationUpdate\0"
    "update\0slot_UpdateMotionProfileState\0"
    "MotionProfileState\0state\0slot_MCNewMotionState\0"
    "ECM::Galil::GalilState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ECM_API[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   45,    2, 0x08 /* Private */,
      10,    1,   48,    2, 0x08 /* Private */,
      13,    2,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 5,   12,    6,

       0        // eod
};

void ECM_API::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ECM_API *_t = static_cast<ECM_API *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_LockMotionButtons((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->signal_MCNewMotionState((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 2: _t->slot_MotionControllerCommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 3: _t->slot_UpdateMotionProfileState((*reinterpret_cast< const MotionProfileState(*)>(_a[1]))); break;
        case 4: _t->slot_MCNewMotionState((*reinterpret_cast< const ECM::Galil::GalilState(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MotionProfileState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ECM_API::*)(const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ECM_API::signal_LockMotionButtons)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ECM_API::*)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ECM_API::signal_MCNewMotionState)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ECM_API::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ECM_API.data,
      qt_meta_data_ECM_API,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ECM_API::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ECM_API::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ECM_API.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ECM_API::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ECM_API::signal_LockMotionButtons(const bool & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ECM_API::signal_MCNewMotionState(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
