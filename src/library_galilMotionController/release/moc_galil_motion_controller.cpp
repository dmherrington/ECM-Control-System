/****************************************************************************
** Meta object code from reading C++ file 'galil_motion_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../galil_motion_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'galil_motion_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GalilMotionController_t {
    QByteArrayData data[43];
    char stringdata0[857];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GalilMotionController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GalilMotionController_t qt_meta_stringdata_GalilMotionController = {
    {
QT_MOC_LITERAL(0, 0, 21), // "GalilMotionController"
QT_MOC_LITERAL(1, 22, 31), // "signal_MCNewPositionalPlottable"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 29), // "common::TuplePositionalString"
QT_MOC_LITERAL(4, 85, 13), // "variableTuple"
QT_MOC_LITERAL(5, 99, 6), // "on_off"
QT_MOC_LITERAL(6, 106, 29), // "signal_MCNewVariablePlottable"
QT_MOC_LITERAL(7, 136, 34), // "common::TupleProfileVariableS..."
QT_MOC_LITERAL(8, 171, 24), // "signal_MCNewDigitalInput"
QT_MOC_LITERAL(9, 196, 12), // "StatusInputs"
QT_MOC_LITERAL(10, 209, 5), // "input"
QT_MOC_LITERAL(11, 215, 20), // "signal_MCNewPosition"
QT_MOC_LITERAL(12, 236, 5), // "tuple"
QT_MOC_LITERAL(13, 242, 35), // "common_data::MachinePositiona..."
QT_MOC_LITERAL(14, 278, 4), // "data"
QT_MOC_LITERAL(15, 283, 32), // "signal_MCNewProfileVariableValue"
QT_MOC_LITERAL(16, 316, 39), // "common_data::MotionProfileVar..."
QT_MOC_LITERAL(17, 356, 42), // "signal_MotionControllerCommun..."
QT_MOC_LITERAL(18, 399, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(19, 434, 10), // "connection"
QT_MOC_LITERAL(20, 445, 23), // "signal_MCNewMotionState"
QT_MOC_LITERAL(21, 469, 22), // "ECM::Galil::GalilState"
QT_MOC_LITERAL(22, 492, 5), // "state"
QT_MOC_LITERAL(23, 498, 11), // "std::string"
QT_MOC_LITERAL(24, 510, 11), // "stateString"
QT_MOC_LITERAL(25, 522, 27), // "signal_MCNewProgramReceived"
QT_MOC_LITERAL(26, 550, 14), // "ProgramGeneric"
QT_MOC_LITERAL(27, 565, 7), // "program"
QT_MOC_LITERAL(28, 573, 28), // "signal_MCNewProgramLabelList"
QT_MOC_LITERAL(29, 602, 16), // "ProgramLabelList"
QT_MOC_LITERAL(30, 619, 6), // "labels"
QT_MOC_LITERAL(31, 626, 31), // "signal_MCNewProgramVariableList"
QT_MOC_LITERAL(32, 658, 19), // "ProgramVariableList"
QT_MOC_LITERAL(33, 678, 12), // "variableList"
QT_MOC_LITERAL(34, 691, 25), // "signal_GalilHomeIndicated"
QT_MOC_LITERAL(35, 717, 9), // "indicated"
QT_MOC_LITERAL(36, 727, 31), // "signal_GalilUpdatedProfileState"
QT_MOC_LITERAL(37, 759, 18), // "MotionProfileState"
QT_MOC_LITERAL(38, 778, 16), // "signal_ErrorCode"
QT_MOC_LITERAL(39, 795, 11), // "errorString"
QT_MOC_LITERAL(40, 807, 32), // "signal_CustomUserRequestReceived"
QT_MOC_LITERAL(41, 840, 7), // "request"
QT_MOC_LITERAL(42, 848, 8) // "response"

    },
    "GalilMotionController\0"
    "signal_MCNewPositionalPlottable\0\0"
    "common::TuplePositionalString\0"
    "variableTuple\0on_off\0signal_MCNewVariablePlottable\0"
    "common::TupleProfileVariableString\0"
    "signal_MCNewDigitalInput\0StatusInputs\0"
    "input\0signal_MCNewPosition\0tuple\0"
    "common_data::MachinePositionalState\0"
    "data\0signal_MCNewProfileVariableValue\0"
    "common_data::MotionProfileVariableState\0"
    "signal_MotionControllerCommunicationUpdate\0"
    "common::comms::CommunicationUpdate\0"
    "connection\0signal_MCNewMotionState\0"
    "ECM::Galil::GalilState\0state\0std::string\0"
    "stateString\0signal_MCNewProgramReceived\0"
    "ProgramGeneric\0program\0"
    "signal_MCNewProgramLabelList\0"
    "ProgramLabelList\0labels\0"
    "signal_MCNewProgramVariableList\0"
    "ProgramVariableList\0variableList\0"
    "signal_GalilHomeIndicated\0indicated\0"
    "signal_GalilUpdatedProfileState\0"
    "MotionProfileState\0signal_ErrorCode\0"
    "errorString\0signal_CustomUserRequestReceived\0"
    "request\0response"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GalilMotionController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       6,    2,   89,    2, 0x06 /* Public */,
       8,    1,   94,    2, 0x06 /* Public */,
      11,    2,   97,    2, 0x06 /* Public */,
      15,    2,  102,    2, 0x06 /* Public */,
      17,    1,  107,    2, 0x06 /* Public */,
      20,    2,  110,    2, 0x06 /* Public */,
      25,    1,  115,    2, 0x06 /* Public */,
      28,    1,  118,    2, 0x06 /* Public */,
      31,    1,  121,    2, 0x06 /* Public */,
      34,    1,  124,    2, 0x06 /* Public */,
      36,    1,  127,    2, 0x06 /* Public */,
      38,    1,  130,    2, 0x06 /* Public */,
      40,    2,  133,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 13,   12,   14,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 16,    4,   14,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21, 0x80000000 | 23,   22,   24,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void, 0x80000000 | 37,   22,
    QMetaType::Void, 0x80000000 | 23,   39,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 23,   41,   42,

       0        // eod
};

void GalilMotionController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GalilMotionController *_t = static_cast<GalilMotionController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_MCNewPositionalPlottable((*reinterpret_cast< const common::TuplePositionalString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->signal_MCNewVariablePlottable((*reinterpret_cast< const common::TupleProfileVariableString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 2: _t->signal_MCNewDigitalInput((*reinterpret_cast< const StatusInputs(*)>(_a[1]))); break;
        case 3: _t->signal_MCNewPosition((*reinterpret_cast< const common::TuplePositionalString(*)>(_a[1])),(*reinterpret_cast< const common_data::MachinePositionalState(*)>(_a[2]))); break;
        case 4: _t->signal_MCNewProfileVariableValue((*reinterpret_cast< const common::TupleProfileVariableString(*)>(_a[1])),(*reinterpret_cast< const common_data::MotionProfileVariableState(*)>(_a[2]))); break;
        case 5: _t->signal_MotionControllerCommunicationUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 6: _t->signal_MCNewMotionState((*reinterpret_cast< const ECM::Galil::GalilState(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 7: _t->signal_MCNewProgramReceived((*reinterpret_cast< const ProgramGeneric(*)>(_a[1]))); break;
        case 8: _t->signal_MCNewProgramLabelList((*reinterpret_cast< const ProgramLabelList(*)>(_a[1]))); break;
        case 9: _t->signal_MCNewProgramVariableList((*reinterpret_cast< const ProgramVariableList(*)>(_a[1]))); break;
        case 10: _t->signal_GalilHomeIndicated((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 11: _t->signal_GalilUpdatedProfileState((*reinterpret_cast< const MotionProfileState(*)>(_a[1]))); break;
        case 12: _t->signal_ErrorCode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 13: _t->signal_CustomUserRequestReceived((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TuplePositionalString >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleProfileVariableString >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TuplePositionalString >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::MachinePositionalState >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::TupleProfileVariableString >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common_data::MotionProfileVariableState >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< common::comms::CommunicationUpdate >(); break;
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
            using _t = void (GalilMotionController::*)(const common::TuplePositionalString & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewPositionalPlottable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const common::TupleProfileVariableString & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewVariablePlottable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const StatusInputs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewDigitalInput)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const common::TuplePositionalString & , const common_data::MachinePositionalState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewPosition)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const common::TupleProfileVariableString & , const common_data::MotionProfileVariableState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewProfileVariableValue)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const common::comms::CommunicationUpdate & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MotionControllerCommunicationUpdate)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const ECM::Galil::GalilState & , const std::string & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewMotionState)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const ProgramGeneric & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewProgramReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const ProgramLabelList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewProgramLabelList)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const ProgramVariableList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_MCNewProgramVariableList)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const bool & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_GalilHomeIndicated)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const MotionProfileState & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_GalilUpdatedProfileState)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_ErrorCode)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (GalilMotionController::*)(const std::string & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GalilMotionController::signal_CustomUserRequestReceived)) {
                *result = 13;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GalilMotionController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GalilMotionController.data,
      qt_meta_data_GalilMotionController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GalilMotionController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GalilMotionController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GalilMotionController.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "GalilStatusUpdate_Interface"))
        return static_cast< GalilStatusUpdate_Interface*>(this);
    if (!strcmp(_clname, "GalilCallback_StateInterface"))
        return static_cast< GalilCallback_StateInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int GalilMotionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void GalilMotionController::signal_MCNewPositionalPlottable(const common::TuplePositionalString & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GalilMotionController::signal_MCNewVariablePlottable(const common::TupleProfileVariableString & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GalilMotionController::signal_MCNewDigitalInput(const StatusInputs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GalilMotionController::signal_MCNewPosition(const common::TuplePositionalString & _t1, const common_data::MachinePositionalState & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< GalilMotionController *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GalilMotionController::signal_MCNewProfileVariableValue(const common::TupleProfileVariableString & _t1, const common_data::MotionProfileVariableState & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< GalilMotionController *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GalilMotionController::signal_MotionControllerCommunicationUpdate(const common::comms::CommunicationUpdate & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GalilMotionController *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GalilMotionController::signal_MCNewMotionState(const ECM::Galil::GalilState & _t1, const std::string & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< GalilMotionController *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GalilMotionController::signal_MCNewProgramReceived(const ProgramGeneric & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GalilMotionController::signal_MCNewProgramLabelList(const ProgramLabelList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GalilMotionController::signal_MCNewProgramVariableList(const ProgramVariableList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GalilMotionController::signal_GalilHomeIndicated(const bool & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GalilMotionController *>(this), &staticMetaObject, 10, _a);
}

// SIGNAL 11
void GalilMotionController::signal_GalilUpdatedProfileState(const MotionProfileState & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GalilMotionController *>(this), &staticMetaObject, 11, _a);
}

// SIGNAL 12
void GalilMotionController::signal_ErrorCode(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void GalilMotionController::signal_CustomUserRequestReceived(const std::string & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
