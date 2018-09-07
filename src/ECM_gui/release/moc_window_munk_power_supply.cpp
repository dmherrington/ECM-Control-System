/****************************************************************************
** Meta object code from reading C++ file 'window_munk_power_supply.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../munk_dialog/window_munk_power_supply.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_munk_power_supply.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_MunkPowerSupply_t {
    QByteArrayData data[26];
    char stringdata0[544];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_MunkPowerSupply_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_MunkPowerSupply_t qt_meta_stringdata_Window_MunkPowerSupply = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Window_MunkPowerSupply"
QT_MOC_LITERAL(1, 23, 28), // "signal_DialogWindowVisibilty"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 38), // "GeneralDialogWindow::DialogWi..."
QT_MOC_LITERAL(4, 92, 4), // "type"
QT_MOC_LITERAL(5, 97, 10), // "visibility"
QT_MOC_LITERAL(6, 108, 33), // "on_pushButton_AddSegment_rele..."
QT_MOC_LITERAL(7, 142, 20), // "on_connectionUpdated"
QT_MOC_LITERAL(8, 163, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(9, 198, 10), // "connection"
QT_MOC_LITERAL(10, 209, 31), // "on_pushButton_transmit_released"
QT_MOC_LITERAL(11, 241, 32), // "slot_ParameterTransmissionUpdate"
QT_MOC_LITERAL(12, 274, 11), // "transmitted"
QT_MOC_LITERAL(13, 286, 8), // "required"
QT_MOC_LITERAL(14, 295, 24), // "slot_SegmentDataModified"
QT_MOC_LITERAL(15, 320, 22), // "slot_FaultCodeReceived"
QT_MOC_LITERAL(16, 343, 24), // "slot_ClearFaultRequested"
QT_MOC_LITERAL(17, 368, 22), // "slot_FaultStateCleared"
QT_MOC_LITERAL(18, 391, 29), // "slot_SegmentExceptionReceived"
QT_MOC_LITERAL(19, 421, 11), // "std::string"
QT_MOC_LITERAL(20, 433, 2), // "RW"
QT_MOC_LITERAL(21, 436, 7), // "meaning"
QT_MOC_LITERAL(22, 444, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(23, 468, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(24, 492, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(25, 519, 24) // "on_actionClose_triggered"

    },
    "Window_MunkPowerSupply\0"
    "signal_DialogWindowVisibilty\0\0"
    "GeneralDialogWindow::DialogWindowTypes\0"
    "type\0visibility\0on_pushButton_AddSegment_released\0"
    "on_connectionUpdated\0"
    "common::comms::CommunicationUpdate\0"
    "connection\0on_pushButton_transmit_released\0"
    "slot_ParameterTransmissionUpdate\0"
    "transmitted\0required\0slot_SegmentDataModified\0"
    "slot_FaultCodeReceived\0slot_ClearFaultRequested\0"
    "slot_FaultStateCleared\0"
    "slot_SegmentExceptionReceived\0std::string\0"
    "RW\0meaning\0on_actionOpen_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionClose_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_MunkPowerSupply[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   89,    2, 0x08 /* Private */,
       7,    1,   90,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    2,   94,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    2,  103,    2, 0x08 /* Private */,
      22,    0,  108,    2, 0x08 /* Private */,
      23,    0,  109,    2, 0x08 /* Private */,
      24,    0,  110,    2, 0x08 /* Private */,
      25,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 19,   20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window_MunkPowerSupply::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window_MunkPowerSupply *_t = static_cast<Window_MunkPowerSupply *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_DialogWindowVisibilty((*reinterpret_cast< const GeneralDialogWindow::DialogWindowTypes(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_AddSegment_released(); break;
        case 2: _t->on_connectionUpdated((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_transmit_released(); break;
        case 4: _t->slot_ParameterTransmissionUpdate((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 5: _t->slot_SegmentDataModified(); break;
        case 6: _t->slot_FaultCodeReceived(); break;
        case 7: _t->slot_ClearFaultRequested(); break;
        case 8: _t->slot_FaultStateCleared(); break;
        case 9: _t->slot_SegmentExceptionReceived((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 10: _t->on_actionOpen_triggered(); break;
        case 11: _t->on_actionSave_triggered(); break;
        case 12: _t->on_actionSave_As_triggered(); break;
        case 13: _t->on_actionClose_triggered(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Window_MunkPowerSupply::*)(const GeneralDialogWindow::DialogWindowTypes & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window_MunkPowerSupply::signal_DialogWindowVisibilty)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window_MunkPowerSupply::staticMetaObject = {
    { &GeneralDialogWindow::staticMetaObject, qt_meta_stringdata_Window_MunkPowerSupply.data,
      qt_meta_data_Window_MunkPowerSupply,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Window_MunkPowerSupply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_MunkPowerSupply::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window_MunkPowerSupply.stringdata0))
        return static_cast<void*>(this);
    return GeneralDialogWindow::qt_metacast(_clname);
}

int Window_MunkPowerSupply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeneralDialogWindow::qt_metacall(_c, _id, _a);
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
void Window_MunkPowerSupply::signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
