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
    QByteArrayData data[45];
    char stringdata0[893];
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
QT_MOC_LITERAL(11, 201, 28), // "signal_MCNewProgramLabelList"
QT_MOC_LITERAL(12, 230, 19), // "Operation_LabelList"
QT_MOC_LITERAL(13, 250, 9), // "labelList"
QT_MOC_LITERAL(14, 260, 31), // "signal_MCNewProgramVariableList"
QT_MOC_LITERAL(15, 292, 22), // "Operation_VariableList"
QT_MOC_LITERAL(16, 315, 12), // "variableList"
QT_MOC_LITERAL(17, 328, 20), // "signal_MCNewPosition"
QT_MOC_LITERAL(18, 349, 29), // "common::TuplePositionalString"
QT_MOC_LITERAL(19, 379, 5), // "tuple"
QT_MOC_LITERAL(20, 385, 35), // "common_data::MachinePositiona..."
QT_MOC_LITERAL(21, 421, 4), // "data"
QT_MOC_LITERAL(22, 426, 12), // "valueChanged"
QT_MOC_LITERAL(23, 439, 22), // "signal_MCHomeIndicated"
QT_MOC_LITERAL(24, 462, 9), // "indicated"
QT_MOC_LITERAL(25, 472, 26), // "signal_MCTouchoffIndicated"
QT_MOC_LITERAL(26, 499, 31), // "signal_MCNewPositionalPlottable"
QT_MOC_LITERAL(27, 531, 13), // "variableTuple"
QT_MOC_LITERAL(28, 545, 6), // "on_off"
QT_MOC_LITERAL(29, 552, 29), // "signal_MCNewVariablePlottable"
QT_MOC_LITERAL(30, 582, 34), // "common::TupleProfileVariableS..."
QT_MOC_LITERAL(31, 617, 32), // "signal_MCNewProfileVariableValue"
QT_MOC_LITERAL(32, 650, 39), // "common_data::MotionProfileVar..."
QT_MOC_LITERAL(33, 690, 31), // "signal_GalilUpdatedProfileState"
QT_MOC_LITERAL(34, 722, 18), // "MotionProfileState"
QT_MOC_LITERAL(35, 741, 23), // "signal_ErrorCommandCode"
QT_MOC_LITERAL(36, 765, 11), // "CommandType"
QT_MOC_LITERAL(37, 777, 4), // "type"
QT_MOC_LITERAL(38, 782, 11), // "std::string"
QT_MOC_LITERAL(39, 794, 11), // "errorString"
QT_MOC_LITERAL(40, 806, 23), // "signal_ErrorRequestCode"
QT_MOC_LITERAL(41, 830, 12), // "RequestTypes"
QT_MOC_LITERAL(42, 843, 32), // "signal_CustomUserRequestReceived"
QT_MOC_LITERAL(43, 876, 7), // "request"
QT_MOC_LITERAL(44, 884, 8) // "response"

    },
    "SPIIMotionController\0signal_MCCommunicationUpdate\0"
    "\0common::comms::CommunicationUpdate\0"
    "connection\0signal_MCNewMotionState\0"
    "ECM::SPII::SPIIState\0state\0stateString\0"
    "signal_MCBufferUpdate\0Status_BufferState\0"
    "signal_MCNewProgramLabelList\0"
    "Operation_LabelList\0labelList\0"
    "signal_MCNewProgramVariableList\0"
    "Operation_VariableList\0variableList\0"
    "signal_MCNewPosition\0common::TuplePositionalString\0"
    "tuple\0common_data::MachinePositionalState\0"
    "data\0valueChanged\0signal_MCHomeIndicated\0"
    "indicated\0signal_MCTouchoffIndicated\0"
    "signal_MCNewPositionalPlottable\0"
    "variableTuple\0on_off\0signal_MCNewVariablePlottable\0"
    "common::TupleProfileVariableString\0"
    "signal_MCNewProfileVariableValue\0"
    "common_data::MotionProfileVariableState\0"
    "signal_GalilUpdatedProfileState\0"
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
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,
       9,    1,   97,    2, 0x06 /* Public */,
      11,    1,  100,    2, 0x06 /* Public */,
      14,    1,  103,    2, 0x06 /* Public */,
      17,    3,  106,    2, 0x06 /* Public */,
      23,    1,  113,    2, 0x06 /* Public */,
      25,    1,  116,    2, 0x06 /* Public */,
      26,    2,  119,    2, 0x06 /* Public */,
      29,    2,  124,    2, 0x06 /* Public */,
      31,    2,  129,    2, 0x06 /* Public */,
      33,    1,  134,    2, 0x06 /* Public */,
      35,    2,  137,    2, 0x06 /* Public */,
      40,    2,  142,    2, 0x06 /* Public */,
      42,    2,  147,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    8,
    QMetaType::Void, 0x80000000 | 10,    7,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 20, QMetaType::Bool,   19,   21,   22,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, 0x80000000 | 18, QMetaType::Bool,   27,   28,
    QMetaType::Void, 0x80000000 | 30, QMetaType::Bool,   27,   28,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 32,   27,   21,
    QMetaType::Void, 0x80000000 | 34,    7,
    QMetaType::Void, 0x80000000 | 36, 0x80000000 | 38,   37,   39,
    QMetaType::Void, 0x80000000 | 41, 0x80000000 | 38,   37,   39,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 38,   43,   44,

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
        case 3: _t->signal_MCNewProgramLabelList((*reinterpret_cast< const Operation_LabelList(*)>(_a[1]))); break;
        case 4: _t->signal_MCNewProgramVariableList((*reinterpret_cast< const Operation_VariableList(*)>(_a[1]))); break;
        case 5: _t->signal_MCNewPosition((*reinterpret_cast< const common::TuplePositionalString(*)>(_a[1])),(*reinterpret_cast< const common_data::MachinePositionalState(*)>(_a[2])),(*reinterpret_cast< const bool(*)>(_a[3]))); break;
        case 6: _t->signal_MCHomeIndicated((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 7: _t->signal_MCTouchoffIndicated((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 8: _t->signal_MCNewPositionalPlottable((*reinterpret_cast< const common::TuplePositionalString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 9: _t->signal_MCNewVariablePlottable((*reinterpret_cast< const common::TupleProfileVariableString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 10: _t->signal_MCNewProfileVariableValue((*reinterpret_cast< const common::TupleProfileVariableString(*)>(_a[1])),(*reinterpret_cast< const common_data::MotionProfileVariableState(*)>(_a[2]))); break;
        case 11: _t->signal_GalilUpdatedProfileState((*reinterpret_cast< const MotionProfileState(*)>(_a[1]))); break;
        case 12: _t->signal_ErrorCommandCode((*reinterpret_cast< const CommandType(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 13: _t->signal_ErrorRequestCode((*reinterpret_cast< const RequestTypes(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 14: _t->signal_CustomUserRequestReceived((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
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
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::MachinePositionalState >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TuplePositionalString >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleProfileVariableString >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleProfileVariableString >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::MotionProfileVariableState >(); break;
            }
            break;
        case 11:
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
            typedef void (SPIIMotionController::*_t)(const Operation_LabelList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewProgramLabelList)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const Operation_VariableList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewProgramVariableList)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const common::TuplePositionalString & , const common_data::MachinePositionalState & , const bool & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewPosition)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const bool & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCHomeIndicated)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const bool & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCTouchoffIndicated)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const common::TuplePositionalString & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewPositionalPlottable)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const common::TupleProfileVariableString & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewVariablePlottable)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const common::TupleProfileVariableString & , const common_data::MotionProfileVariableState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_MCNewProfileVariableValue)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const MotionProfileState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_GalilUpdatedProfileState)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const CommandType & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_ErrorCommandCode)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const RequestTypes & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_ErrorRequestCode)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (SPIIMotionController::*_t)(const std::string & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SPIIMotionController::signal_CustomUserRequestReceived)) {
                *result = 14;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
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
void SPIIMotionController::signal_MCNewProgramLabelList(const Operation_LabelList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SPIIMotionController::signal_MCNewProgramVariableList(const Operation_VariableList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SPIIMotionController::signal_MCNewPosition(const common::TuplePositionalString & _t1, const common_data::MachinePositionalState & _t2, const bool & _t3)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SPIIMotionController::signal_MCHomeIndicated(const bool & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SPIIMotionController::signal_MCTouchoffIndicated(const bool & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SPIIMotionController::signal_MCNewPositionalPlottable(const common::TuplePositionalString & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SPIIMotionController::signal_MCNewVariablePlottable(const common::TupleProfileVariableString & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SPIIMotionController::signal_MCNewProfileVariableValue(const common::TupleProfileVariableString & _t1, const common_data::MotionProfileVariableState & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SPIIMotionController::signal_GalilUpdatedProfileState(const MotionProfileState & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SPIIMotionController *>(this), &staticMetaObject, 11, _a);
}

// SIGNAL 12
void SPIIMotionController::signal_ErrorCommandCode(const CommandType & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void SPIIMotionController::signal_ErrorRequestCode(const RequestTypes & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void SPIIMotionController::signal_CustomUserRequestReceived(const std::string & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
