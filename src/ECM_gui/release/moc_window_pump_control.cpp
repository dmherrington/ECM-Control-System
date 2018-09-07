/****************************************************************************
** Meta object code from reading C++ file 'window_pump_control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pump_dialog/window_pump_control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_pump_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_PumpControl_t {
    QByteArrayData data[21];
    char stringdata0[459];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_PumpControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_PumpControl_t qt_meta_stringdata_Window_PumpControl = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Window_PumpControl"
QT_MOC_LITERAL(1, 19, 28), // "signal_DialogWindowVisibilty"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 38), // "GeneralDialogWindow::DialogWi..."
QT_MOC_LITERAL(4, 88, 4), // "type"
QT_MOC_LITERAL(5, 93, 10), // "visibility"
QT_MOC_LITERAL(6, 104, 25), // "slot_PumpConnectionUpdate"
QT_MOC_LITERAL(7, 130, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(8, 165, 6), // "update"
QT_MOC_LITERAL(9, 172, 21), // "slot_updatedDelayTime"
QT_MOC_LITERAL(10, 194, 5), // "value"
QT_MOC_LITERAL(11, 200, 18), // "slot_updatedPumpOn"
QT_MOC_LITERAL(12, 219, 20), // "slot_updatedFlowRate"
QT_MOC_LITERAL(13, 240, 34), // "on_pushButton_PumpRunning_rel..."
QT_MOC_LITERAL(14, 275, 38), // "on_doubleSpinBox_flowRate_val..."
QT_MOC_LITERAL(15, 314, 4), // "arg1"
QT_MOC_LITERAL(16, 319, 39), // "on_doubleSpinBox_delayTime_va..."
QT_MOC_LITERAL(17, 359, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(18, 384, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(19, 408, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(20, 432, 26) // "on_actionSave_As_triggered"

    },
    "Window_PumpControl\0signal_DialogWindowVisibilty\0"
    "\0GeneralDialogWindow::DialogWindowTypes\0"
    "type\0visibility\0slot_PumpConnectionUpdate\0"
    "common::comms::CommunicationUpdate\0"
    "update\0slot_updatedDelayTime\0value\0"
    "slot_updatedPumpOn\0slot_updatedFlowRate\0"
    "on_pushButton_PumpRunning_released\0"
    "on_doubleSpinBox_flowRate_valueChanged\0"
    "arg1\0on_doubleSpinBox_delayTime_valueChanged\0"
    "on_actionClose_triggered\0"
    "on_actionOpen_triggered\0on_actionSave_triggered\0"
    "on_actionSave_As_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_PumpControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   79,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      11,    1,   85,    2, 0x08 /* Private */,
      12,    1,   88,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    1,   92,    2, 0x08 /* Private */,
      16,    1,   95,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x08 /* Private */,
      18,    0,   99,    2, 0x08 /* Private */,
      19,    0,  100,    2, 0x08 /* Private */,
      20,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window_PumpControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window_PumpControl *_t = static_cast<Window_PumpControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_DialogWindowVisibilty((*reinterpret_cast< const GeneralDialogWindow::DialogWindowTypes(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->slot_PumpConnectionUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 2: _t->slot_updatedDelayTime((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 3: _t->slot_updatedPumpOn((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->slot_updatedFlowRate((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_PumpRunning_released(); break;
        case 6: _t->on_doubleSpinBox_flowRate_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_doubleSpinBox_delayTime_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_actionClose_triggered(); break;
        case 9: _t->on_actionOpen_triggered(); break;
        case 10: _t->on_actionSave_triggered(); break;
        case 11: _t->on_actionSave_As_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
            using _t = void (Window_PumpControl::*)(const GeneralDialogWindow::DialogWindowTypes & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window_PumpControl::signal_DialogWindowVisibilty)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window_PumpControl::staticMetaObject = {
    { &GeneralDialogWindow::staticMetaObject, qt_meta_stringdata_Window_PumpControl.data,
      qt_meta_data_Window_PumpControl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Window_PumpControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_PumpControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window_PumpControl.stringdata0))
        return static_cast<void*>(this);
    return GeneralDialogWindow::qt_metacast(_clname);
}

int Window_PumpControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeneralDialogWindow::qt_metacall(_c, _id, _a);
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
void Window_PumpControl::signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
