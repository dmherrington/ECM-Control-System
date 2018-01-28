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
    QByteArrayData data[23];
    char stringdata0[454];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MunkPowerSupply_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MunkPowerSupply_t qt_meta_stringdata_MunkPowerSupply = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MunkPowerSupply"
QT_MOC_LITERAL(1, 16, 23), // "signal_SerialPortStatus"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 10), // "open_close"
QT_MOC_LITERAL(4, 52, 11), // "std::string"
QT_MOC_LITERAL(5, 64, 11), // "errorString"
QT_MOC_LITERAL(6, 76, 25), // "signal_NewCurrentSetpoint"
QT_MOC_LITERAL(7, 102, 37), // "DataParameter::SegmentCurrent..."
QT_MOC_LITERAL(8, 140, 18), // "currentSetpointREV"
QT_MOC_LITERAL(9, 159, 18), // "currentSetpointFWD"
QT_MOC_LITERAL(10, 178, 25), // "signal_NewVoltageSetpoint"
QT_MOC_LITERAL(11, 204, 37), // "DataParameter::SegmentVoltage..."
QT_MOC_LITERAL(12, 242, 18), // "voltageSetpointREV"
QT_MOC_LITERAL(13, 261, 18), // "voltageSetpointFWD"
QT_MOC_LITERAL(14, 280, 22), // "signal_NewTimeSetpoint"
QT_MOC_LITERAL(15, 303, 33), // "DataParameter::SegmentTimeGen..."
QT_MOC_LITERAL(16, 337, 11), // "segmentTime"
QT_MOC_LITERAL(17, 349, 25), // "messageGenerationProgress"
QT_MOC_LITERAL(18, 375, 20), // "Data::DataFaultCodes"
QT_MOC_LITERAL(19, 396, 4), // "code"
QT_MOC_LITERAL(20, 401, 20), // "transmissionProgress"
QT_MOC_LITERAL(21, 422, 15), // "munkSupplyError"
QT_MOC_LITERAL(22, 438, 15) // "serialPortError"

    },
    "MunkPowerSupply\0signal_SerialPortStatus\0"
    "\0open_close\0std::string\0errorString\0"
    "signal_NewCurrentSetpoint\0"
    "DataParameter::SegmentCurrentSetpoint\0"
    "currentSetpointREV\0currentSetpointFWD\0"
    "signal_NewVoltageSetpoint\0"
    "DataParameter::SegmentVoltageSetpoint\0"
    "voltageSetpointREV\0voltageSetpointFWD\0"
    "signal_NewTimeSetpoint\0"
    "DataParameter::SegmentTimeGeneral\0"
    "segmentTime\0messageGenerationProgress\0"
    "Data::DataFaultCodes\0code\0"
    "transmissionProgress\0munkSupplyError\0"
    "serialPortError"
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
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       6,    2,   59,    2, 0x06 /* Public */,
      10,    2,   64,    2, 0x06 /* Public */,
      14,    1,   69,    2, 0x06 /* Public */,
      17,    1,   72,    2, 0x06 /* Public */,
      20,    0,   75,    2, 0x06 /* Public */,
      21,    0,   76,    2, 0x06 /* Public */,
      22,    0,   77,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
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
        case 0: _t->signal_SerialPortStatus((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 1: _t->signal_NewCurrentSetpoint((*reinterpret_cast< const DataParameter::SegmentCurrentSetpoint(*)>(_a[1])),(*reinterpret_cast< const DataParameter::SegmentCurrentSetpoint(*)>(_a[2]))); break;
        case 2: _t->signal_NewVoltageSetpoint((*reinterpret_cast< const DataParameter::SegmentVoltageSetpoint(*)>(_a[1])),(*reinterpret_cast< const DataParameter::SegmentVoltageSetpoint(*)>(_a[2]))); break;
        case 3: _t->signal_NewTimeSetpoint((*reinterpret_cast< const DataParameter::SegmentTimeGeneral(*)>(_a[1]))); break;
        case 4: _t->messageGenerationProgress((*reinterpret_cast< const Data::DataFaultCodes(*)>(_a[1]))); break;
        case 5: _t->transmissionProgress(); break;
        case 6: _t->munkSupplyError(); break;
        case 7: _t->serialPortError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MunkPowerSupply::*_t)(const bool & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_SerialPortStatus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const DataParameter::SegmentCurrentSetpoint & , const DataParameter::SegmentCurrentSetpoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_NewCurrentSetpoint)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const DataParameter::SegmentVoltageSetpoint & , const DataParameter::SegmentVoltageSetpoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_NewVoltageSetpoint)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const DataParameter::SegmentTimeGeneral & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::signal_NewTimeSetpoint)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)(const Data::DataFaultCodes & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::messageGenerationProgress)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::transmissionProgress)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::munkSupplyError)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MunkPowerSupply::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MunkPowerSupply::serialPortError)) {
                *result = 7;
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
void MunkPowerSupply::signal_SerialPortStatus(const bool & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MunkPowerSupply::signal_NewCurrentSetpoint(const DataParameter::SegmentCurrentSetpoint & _t1, const DataParameter::SegmentCurrentSetpoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MunkPowerSupply::signal_NewVoltageSetpoint(const DataParameter::SegmentVoltageSetpoint & _t1, const DataParameter::SegmentVoltageSetpoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MunkPowerSupply::signal_NewTimeSetpoint(const DataParameter::SegmentTimeGeneral & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MunkPowerSupply::messageGenerationProgress(const Data::DataFaultCodes & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MunkPowerSupply::transmissionProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MunkPowerSupply::munkSupplyError()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MunkPowerSupply::serialPortError()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
