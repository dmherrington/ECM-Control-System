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
    QByteArrayData data[19];
    char stringdata0[273];
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
QT_MOC_LITERAL(5, 85, 11), // "std::string"
QT_MOC_LITERAL(6, 97, 4), // "type"
QT_MOC_LITERAL(7, 102, 3), // "msg"
QT_MOC_LITERAL(8, 106, 26), // "signal_CommunicationUpdate"
QT_MOC_LITERAL(9, 133, 4), // "name"
QT_MOC_LITERAL(10, 138, 24), // "signal_FaultCodeRecieved"
QT_MOC_LITERAL(11, 163, 6), // "regNum"
QT_MOC_LITERAL(12, 170, 20), // "signal_SegmentSetAck"
QT_MOC_LITERAL(13, 191, 23), // "signal_SegmentException"
QT_MOC_LITERAL(14, 215, 2), // "RW"
QT_MOC_LITERAL(15, 218, 7), // "meaning"
QT_MOC_LITERAL(16, 226, 27), // "signal_SegmentWriteProgress"
QT_MOC_LITERAL(17, 254, 9), // "completed"
QT_MOC_LITERAL(18, 264, 8) // "required"

    },
    "MunkPowerSupply\0signal_ConnectionStatusUpdated\0"
    "\0open_close\0signal_CommunicationError\0"
    "std::string\0type\0msg\0signal_CommunicationUpdate\0"
    "name\0signal_FaultCodeRecieved\0regNum\0"
    "signal_SegmentSetAck\0signal_SegmentException\0"
    "RW\0meaning\0signal_SegmentWriteProgress\0"
    "completed\0required"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MunkPowerSupply[] = {

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
       4,    2,   52,    2, 0x06 /* Public */,
       8,    2,   57,    2, 0x06 /* Public */,
      10,    2,   62,    2, 0x06 /* Public */,
      12,    1,   67,    2, 0x06 /* Public */,
      13,    2,   70,    2, 0x06 /* Public */,
      16,    2,   75,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    9,    7,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,   11,    7,
    QMetaType::Void, 0x80000000 | 5,    7,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,   14,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,

       0        // eod
};

void MunkPowerSupply::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MunkPowerSupply *_t = static_cast<MunkPowerSupply *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_ConnectionStatusUpdated((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->signal_CommunicationError((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 2: _t->signal_CommunicationUpdate((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 3: _t->signal_FaultCodeRecieved((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 4: _t->signal_SegmentSetAck((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 5: _t->signal_SegmentException((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 6: _t->signal_SegmentWriteProgress((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
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
            typedef void (MunkPowerSupply::*_t)(const std::string & , const std::string & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_CommunicationError)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const std::string & , const std::string & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_CommunicationUpdate)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const int & , const std::string & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_FaultCodeRecieved)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const std::string & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_SegmentSetAck)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const std::string & , const std::string & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_SegmentException)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_SegmentWriteProgress)) {
                *result = 6;
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
    if (!strcmp(_clname, "MunkStatusCallback_Interface"))
        return static_cast< MunkStatusCallback_Interface*>(this);
    return QObject::qt_metacast(_clname);
}

int MunkPowerSupply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void MunkPowerSupply::signal_CommunicationError(const std::string & _t1, const std::string & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MunkPowerSupply::signal_CommunicationUpdate(const std::string & _t1, const std::string & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MunkPowerSupply::signal_FaultCodeRecieved(const int & _t1, const std::string & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MunkPowerSupply::signal_SegmentSetAck(const std::string & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MunkPowerSupply::signal_SegmentException(const std::string & _t1, const std::string & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< MunkPowerSupply *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MunkPowerSupply::signal_SegmentWriteProgress(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
