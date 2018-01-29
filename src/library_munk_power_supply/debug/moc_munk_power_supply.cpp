/****************************************************************************
** Meta object code from reading C++ file 'munk_power_supply.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../munk_power_supply.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'munk_power_supply.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MunkPowerSupply_t {
    QByteArrayData data[9];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MunkPowerSupply_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MunkPowerSupply_t qt_meta_stringdata_MunkPowerSupply = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MunkPowerSupply"
QT_MOC_LITERAL(1, 16, 30), // "signal_ConnectionStatusUpdated"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 10), // "open_close"
QT_MOC_LITERAL(4, 59, 25), // "signal_CommunicationError"
QT_MOC_LITERAL(5, 85, 26), // "signal_CommunicationUpdate"
QT_MOC_LITERAL(6, 112, 20), // "signal_SegmentSetAck"
QT_MOC_LITERAL(7, 133, 23), // "signal_SegmentException"
QT_MOC_LITERAL(8, 157, 24) // "signal_FaultCodeRecieved"

    },
    "MunkPowerSupply\0signal_ConnectionStatusUpdated\0"
    "\0open_close\0signal_CommunicationError\0"
    "signal_CommunicationUpdate\0"
    "signal_SegmentSetAck\0signal_SegmentException\0"
    "signal_FaultCodeRecieved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MunkPowerSupply[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,
       6,    0,   49,    2, 0x06 /* Public */,
       7,    0,   50,    2, 0x06 /* Public */,
       8,    0,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MunkPowerSupply::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MunkPowerSupply *_t = static_cast<MunkPowerSupply *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_ConnectionStatusUpdated((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->signal_CommunicationError(); break;
        case 2: _t->signal_CommunicationUpdate(); break;
        case 3: _t->signal_SegmentSetAck(); break;
        case 4: _t->signal_SegmentException(); break;
        case 5: _t->signal_FaultCodeRecieved(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MunkPowerSupply::*_t)(const bool & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_ConnectionStatusUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_CommunicationError)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_CommunicationUpdate)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_SegmentSetAck)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_SegmentException)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_FaultCodeRecieved)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject MunkPowerSupply::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MunkPowerSupply.data,
      qt_meta_data_MunkPowerSupply,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MunkPowerSupply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MunkPowerSupply::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MunkPowerSupply.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "comms::CommsEvents"))
        return static_cast< comms::CommsEvents*>(this);
    return QObject::qt_metacast(_clname);
}

int MunkPowerSupply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MunkPowerSupply::signal_ConnectionStatusUpdated(const bool & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MunkPowerSupply::signal_CommunicationError()const
{
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MunkPowerSupply::signal_CommunicationUpdate()const
{
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MunkPowerSupply::signal_SegmentSetAck()const
{
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MunkPowerSupply::signal_SegmentException()const
{
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MunkPowerSupply::signal_FaultCodeRecieved()const
{
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
