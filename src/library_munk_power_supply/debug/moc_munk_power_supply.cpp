/****************************************************************************
** Meta object code from reading C++ file 'munk_power_supply.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../munk_power_supply.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'munk_power_supply.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MunkPowerSupply_t {
    QByteArrayData data[21];
    char stringdata0[412];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MunkPowerSupply_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MunkPowerSupply_t qt_meta_stringdata_MunkPowerSupply = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MunkPowerSupply"
QT_MOC_LITERAL(1, 16, 25), // "signal_NewCurrentSetpoint"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 37), // "DataParameter::SegmentCurrent..."
QT_MOC_LITERAL(4, 81, 18), // "currentSetpointREV"
QT_MOC_LITERAL(5, 100, 18), // "currentSetpointFWD"
QT_MOC_LITERAL(6, 119, 25), // "signal_NewVoltageSetpoint"
QT_MOC_LITERAL(7, 145, 37), // "DataParameter::SegmentVoltage..."
QT_MOC_LITERAL(8, 183, 18), // "voltageSetpointREV"
QT_MOC_LITERAL(9, 202, 18), // "voltageSetpointFWD"
QT_MOC_LITERAL(10, 221, 22), // "signal_NewTimeSetpoint"
QT_MOC_LITERAL(11, 244, 33), // "DataParameter::SegmentTimeGen..."
QT_MOC_LITERAL(12, 278, 11), // "segmentTime"
QT_MOC_LITERAL(13, 290, 25), // "messageGenerationProgress"
QT_MOC_LITERAL(14, 316, 20), // "Data::DataFaultCodes"
QT_MOC_LITERAL(15, 337, 4), // "code"
QT_MOC_LITERAL(16, 342, 20), // "transmissionProgress"
QT_MOC_LITERAL(17, 363, 15), // "munkSupplyError"
QT_MOC_LITERAL(18, 379, 15), // "serialPortError"
QT_MOC_LITERAL(19, 395, 11), // "receivedMSG"
QT_MOC_LITERAL(20, 407, 4) // "data"

    },
    "MunkPowerSupply\0signal_NewCurrentSetpoint\0"
    "\0DataParameter::SegmentCurrentSetpoint\0"
    "currentSetpointREV\0currentSetpointFWD\0"
    "signal_NewVoltageSetpoint\0"
    "DataParameter::SegmentVoltageSetpoint\0"
    "voltageSetpointREV\0voltageSetpointFWD\0"
    "signal_NewTimeSetpoint\0"
    "DataParameter::SegmentTimeGeneral\0"
    "segmentTime\0messageGenerationProgress\0"
    "Data::DataFaultCodes\0code\0"
    "transmissionProgress\0munkSupplyError\0"
    "serialPortError\0receivedMSG\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MunkPowerSupply[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       6,    2,   59,    2, 0x06 /* Public */,
      10,    1,   64,    2, 0x06 /* Public */,
      13,    1,   67,    2, 0x06 /* Public */,
      16,    0,   70,    2, 0x06 /* Public */,
      17,    0,   71,    2, 0x06 /* Public */,
      18,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   20,

       0        // eod
};

void MunkPowerSupply::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MunkPowerSupply *_t = static_cast<MunkPowerSupply *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_NewCurrentSetpoint((*reinterpret_cast< const DataParameter::SegmentCurrentSetpoint(*)>(_a[1])),(*reinterpret_cast< const DataParameter::SegmentCurrentSetpoint(*)>(_a[2]))); break;
        case 1: _t->signal_NewVoltageSetpoint((*reinterpret_cast< const DataParameter::SegmentVoltageSetpoint(*)>(_a[1])),(*reinterpret_cast< const DataParameter::SegmentVoltageSetpoint(*)>(_a[2]))); break;
        case 2: _t->signal_NewTimeSetpoint((*reinterpret_cast< const DataParameter::SegmentTimeGeneral(*)>(_a[1]))); break;
        case 3: _t->messageGenerationProgress((*reinterpret_cast< const Data::DataFaultCodes(*)>(_a[1]))); break;
        case 4: _t->transmissionProgress(); break;
        case 5: _t->munkSupplyError(); break;
        case 6: _t->serialPortError(); break;
        case 7: _t->receivedMSG((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MunkPowerSupply::*_t)(const DataParameter::SegmentCurrentSetpoint & , const DataParameter::SegmentCurrentSetpoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MunkPowerSupply::signal_NewCurrentSetpoint)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const DataParameter::SegmentVoltageSetpoint & , const DataParameter::SegmentVoltageSetpoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MunkPowerSupply::signal_NewVoltageSetpoint)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const DataParameter::SegmentTimeGeneral & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MunkPowerSupply::signal_NewTimeSetpoint)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const Data::DataFaultCodes & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MunkPowerSupply::messageGenerationProgress)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MunkPowerSupply::transmissionProgress)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MunkPowerSupply::munkSupplyError)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MunkPowerSupply::serialPortError)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MunkPowerSupply::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MunkPowerSupply.data,
      qt_meta_data_MunkPowerSupply,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MunkPowerSupply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MunkPowerSupply::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MunkPowerSupply.stringdata0))
        return static_cast<void*>(const_cast< MunkPowerSupply*>(this));
    return QObject::qt_metacast(_clname);
}

int MunkPowerSupply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MunkPowerSupply::signal_NewCurrentSetpoint(const DataParameter::SegmentCurrentSetpoint & _t1, const DataParameter::SegmentCurrentSetpoint & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MunkPowerSupply::signal_NewVoltageSetpoint(const DataParameter::SegmentVoltageSetpoint & _t1, const DataParameter::SegmentVoltageSetpoint & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MunkPowerSupply::signal_NewTimeSetpoint(const DataParameter::SegmentTimeGeneral & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MunkPowerSupply::messageGenerationProgress(const Data::DataFaultCodes & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MunkPowerSupply::transmissionProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MunkPowerSupply::munkSupplyError()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MunkPowerSupply::serialPortError()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
