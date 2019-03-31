/****************************************************************************
** Meta object code from reading C++ file 'spii_motion_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spii_motion_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spii_motion_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SPIIMotionController_t {
    QByteArrayData data[35];
    char stringdata0[690];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SPIIMotionController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SPIIMotionController_t qt_meta_stringdata_SPIIMotionController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "SPIIMotionController"
QT_MOC_LITERAL(1, 21, 28), // "signal_MCCommunicationUpdate"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(4, 86, 10), // "connection"
QT_MOC_LITERAL(5, 97, 23), // "signal_MCNewMotionState"
QT_MOC_LITERAL(6, 121, 20), // "ECM::SPII::SPIIState"
QT_MOC_LITERAL(7, 142, 5), // "state"
QT_MOC_LITERAL(8, 148, 11), // "stateString"
QT_MOC_LITERAL(9, 160, 21), // "signal_MCBufferUpdate"
QT_MOC_LITERAL(10, 182, 18), // "Status_BufferState"
QT_MOC_LITERAL(11, 201, 22), // "signal_MCHomeIndicated"
QT_MOC_LITERAL(12, 224, 9), // "indicated"
QT_MOC_LITERAL(13, 234, 26), // "signal_MCTouchoffIndicated"
QT_MOC_LITERAL(14, 261, 31), // "signal_MCNewPositionalPlottable"
QT_MOC_LITERAL(15, 293, 29), // "common::TuplePositionalString"
QT_MOC_LITERAL(16, 323, 13), // "variableTuple"
QT_MOC_LITERAL(17, 337, 6), // "on_off"
QT_MOC_LITERAL(18, 344, 29), // "signal_MCNewVariablePlottable"
QT_MOC_LITERAL(19, 374, 34), // "common::TupleProfileVariableS..."
QT_MOC_LITERAL(20, 409, 32), // "signal_MCNewProfileVariableValue"
QT_MOC_LITERAL(21, 442, 39), // "common_data::MotionProfileVar..."
QT_MOC_LITERAL(22, 482, 4), // "data"
QT_MOC_LITERAL(23, 487, 31), // "signal_GalilUpdatedProfileState"
QT_MOC_LITERAL(24, 519, 18), // "MotionProfileState"
QT_MOC_LITERAL(25, 538, 23), // "signal_ErrorCommandCode"
QT_MOC_LITERAL(26, 562, 11), // "CommandType"
QT_MOC_LITERAL(27, 574, 4), // "type"
QT_MOC_LITERAL(28, 579, 11), // "std::string"
QT_MOC_LITERAL(29, 591, 11), // "errorString"
QT_MOC_LITERAL(30, 603, 23), // "signal_ErrorRequestCode"
QT_MOC_LITERAL(31, 627, 12), // "RequestTypes"
QT_MOC_LITERAL(32, 640, 32), // "signal_CustomUserRequestReceived"
QT_MOC_LITERAL(33, 673, 7), // "request"
QT_MOC_LITERAL(34, 681, 8) // "response"

    },
    "SPIIMotionController\0signal_MCCommunicationUpdate\0"
    "\0common::comms::CommunicationUpdate\0"
    "connection\0signal_MCNewMotionState\0"
    "ECM::SPII::SPIIState\0state\0stateString\0"
    "signal_MCBufferUpdate\0Status_BufferState\0"
    "signal_MCHomeIndicated\0indicated\0"
    "signal_MCTouchoffIndicated\0"
    "signal_MCNewPositionalPlottable\0"
    "common::TuplePositionalString\0"
    "variableTuple\0on_off\0signal_MCNewVariablePlottable\0"
    "common::TupleProfileVariableString\0"
    "signal_MCNewProfileVariableValue\0"
    "common_data::MotionProfileVariableState\0"
    "data\0signal_GalilUpdatedProfileState\0"
    "MotionProfileState\0signal_ErrorCommandCode\0"
    "CommandType\0type\0std::string\0errorString\0"
    "signal_ErrorRequestCode\0RequestTypes\0"
    "signal_CustomUserRequestReceived\0"
    "request\0response"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SPIIMotionController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    2,   77,    2, 0x06 /* Public */,
       9,    1,   82,    2, 0x06 /* Public */,
      11,    1,   85,    2, 0x06 /* Public */,
      13,    1,   88,    2, 0x06 /* Public */,
      14,    2,   91,    2, 0x06 /* Public */,
      18,    2,   96,    2, 0x06 /* Public */,
      20,    2,  101,    2, 0x06 /* Public */,
      23,    1,  106,    2, 0x06 /* Public */,
      25,    2,  109,    2, 0x06 /* Public */,
      30,    2,  114,    2, 0x06 /* Public */,
      32,    2,  119,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    8,
    QMetaType::Void, 0x80000000 | 10,    7,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Bool,   16,   17,
    QMetaType::Void, 0x80000000 | 19, QMetaType::Bool,   16,   17,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21,   16,   22,
    QMetaType::Void, 0x80000000 | 24,    7,
    QMetaType::Void, 0x80000000 | 26, 0x80000000 | 28,   27,   29,
    QMetaType::Void, 0x80000000 | 31, 0x80000000 | 28,   27,   29,
    QMetaType::Void, 0x80000000 | 28, 0x80000000 | 28,   33,   34,

       0        // eod
};

void SPIIMotionController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SPIIMotionController *_t = static_cast<SPIIMotionController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_MCCommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 1: _t->signal_MCNewMotionState((*reinterpret_cast< const ECM::SPII::SPIIState(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->signal_MCBufferUpdate((*reinterpret_cast< const Status_BufferState(*)>(_a[1]))); break;
        case 3: _t->signal_MCHomeIndicated((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->signal_MCTouchoffIndicated((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 5: _t->signal_MCNewPositionalPlottable((*reinterpret_cast< const common::TuplePositionalString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 6: _t->signal_MCNewVariablePlottable((*reinterpret_cast< const common::TupleProfileVariableString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 7: _t->signal_MCNewProfileVariableValue((*reinterpret_cast< const common::TupleProfileVariableString(*)>(_a[1])),(*reinterpret_cast< const common_data::MotionProfileVariableState(*)>(_a[2]))); break;
        case 8: _t->signal_GalilUpdatedProfileState((*reinterpret_cast< const MotionProfileState(*)>(_a[1]))); break;
        case 9: _t->signal_ErrorCommandCode((*reinterpret_cast< const CommandType(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 10: _t->signal_ErrorRequestCode((*reinterpret_cast< const RequestTypes(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 11: _t->signal_CustomUserRequestReceived((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
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
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TuplePositionalString >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleProfileVariableString >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleProfileVariableString >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::MotionProfileVariableState >(); break;
            }
            break;
        case 8:
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
            typedef void (SPIIMotionController::*_t)(const common::comms::CommunicationUpdate & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCCommunicationUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const ECM::SPII::SPIIState & , const QString & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewMotionState)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const Status_BufferState & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCBufferUpdate)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const bool & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCHomeIndicated)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const bool & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCTouchoffIndicated)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const common::TuplePositionalString & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewPositionalPlottable)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const common::TupleProfileVariableString & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewVariablePlottable)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const common::TupleProfileVariableString & , const common_data::MotionProfileVariableState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewProfileVariableValue)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const MotionProfileState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_GalilUpdatedProfileState)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const CommandType & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_ErrorCommandCode)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const RequestTypes & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_ErrorRequestCode)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const std::string & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_CustomUserRequestReceived)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SPIIMotionController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SPIIMotionController.data,
      qt_meta_data_SPIIMotionController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SPIIMotionController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SPIIMotionController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SPIIMotionController.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "SPIIDeviceInterface_MotionControl"))
        return static_cast< SPIIDeviceInterface_MotionControl*>(this);
    if (!strcmp(_clname, "SPIICallback_StateInterface"))
        return static_cast< SPIICallback_StateInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int SPIIMotionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SPIIMotionController::signal_MCCommunicationUpdate(const common::comms::CommunicationUpdate & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SPIIMotionController::signal_MCNewMotionState(const ECM::SPII::SPIIState & _t1, const QString & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SPIIMotionController::signal_MCBufferUpdate(const Status_BufferState & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SPIIMotionController::signal_MCHomeIndicated(const bool & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SPIIMotionController::signal_MCTouchoffIndicated(const bool & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SPIIMotionController::signal_MCNewPositionalPlottable(const common::TuplePositionalString & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SPIIMotionController::signal_MCNewVariablePlottable(const common::TupleProfileVariableString & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SPIIMotionController::signal_MCNewProfileVariableValue(const common::TupleProfileVariableString & _t1, const common_data::MotionProfileVariableState & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SPIIMotionController::signal_GalilUpdatedProfileState(const MotionProfileState & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SPIIMotionController::signal_ErrorCommandCode(const CommandType & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SPIIMotionController::signal_ErrorRequestCode(const RequestTypes & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SPIIMotionController::signal_CustomUserRequestReceived(const std::string & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
