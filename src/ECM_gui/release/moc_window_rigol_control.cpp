/****************************************************************************
** Meta object code from reading C++ file 'window_rigol_control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rigol_dialog/window_rigol_control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_rigol_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_RigolControl_t {
    QByteArrayData data[21];
    char stringdata0[447];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_RigolControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_RigolControl_t qt_meta_stringdata_Window_RigolControl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Window_RigolControl"
QT_MOC_LITERAL(1, 20, 28), // "signal_DialogWindowVisibilty"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 38), // "GeneralDialogWindow::DialogWi..."
QT_MOC_LITERAL(4, 89, 4), // "type"
QT_MOC_LITERAL(5, 94, 10), // "visibility"
QT_MOC_LITERAL(6, 105, 33), // "slot_OscilliscopeConnectionUp..."
QT_MOC_LITERAL(7, 139, 34), // "common::comms::CommunicationU..."
QT_MOC_LITERAL(8, 174, 5), // "value"
QT_MOC_LITERAL(9, 180, 24), // "slot_onRadioButtonChange"
QT_MOC_LITERAL(10, 205, 28), // "data_Rigol::MeasurementTypes"
QT_MOC_LITERAL(11, 234, 11), // "measurement"
QT_MOC_LITERAL(12, 246, 7), // "checked"
QT_MOC_LITERAL(13, 254, 19), // "slot_onLoadComplete"
QT_MOC_LITERAL(14, 274, 27), // "on_pushButton_Done_released"
QT_MOC_LITERAL(15, 302, 39), // "on_comboBox_Channel_currentIn..."
QT_MOC_LITERAL(16, 342, 4), // "arg1"
QT_MOC_LITERAL(17, 347, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(18, 371, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(19, 396, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(20, 420, 26) // "on_actionSave_As_triggered"

    },
    "Window_RigolControl\0signal_DialogWindowVisibilty\0"
    "\0GeneralDialogWindow::DialogWindowTypes\0"
    "type\0visibility\0slot_OscilliscopeConnectionUpdate\0"
    "common::comms::CommunicationUpdate\0"
    "value\0slot_onRadioButtonChange\0"
    "data_Rigol::MeasurementTypes\0measurement\0"
    "checked\0slot_onLoadComplete\0"
    "on_pushButton_Done_released\0"
    "on_comboBox_Channel_currentIndexChanged\0"
    "arg1\0on_actionOpen_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_RigolControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   69,    2, 0x08 /* Private */,
       9,    2,   72,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    1,   79,    2, 0x08 /* Private */,
      17,    0,   82,    2, 0x08 /* Private */,
      18,    0,   83,    2, 0x08 /* Private */,
      19,    0,   84,    2, 0x08 /* Private */,
      20,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Bool,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window_RigolControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window_RigolControl *_t = static_cast<Window_RigolControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_DialogWindowVisibilty((*reinterpret_cast< const GeneralDialogWindow::DialogWindowTypes(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->slot_OscilliscopeConnectionUpdate((*reinterpret_cast< const common::comms::CommunicationUpdate(*)>(_a[1]))); break;
        case 2: _t->slot_onRadioButtonChange((*reinterpret_cast< const data_Rigol::MeasurementTypes(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 3: _t->slot_onLoadComplete(); break;
        case 4: _t->on_pushButton_Done_released(); break;
        case 5: _t->on_comboBox_Channel_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_actionOpen_triggered(); break;
        case 7: _t->on_actionClose_triggered(); break;
        case 8: _t->on_actionSave_triggered(); break;
        case 9: _t->on_actionSave_As_triggered(); break;
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
            using _t = void (Window_RigolControl::*)(const GeneralDialogWindow::DialogWindowTypes & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window_RigolControl::signal_DialogWindowVisibilty)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window_RigolControl::staticMetaObject = {
    { &GeneralDialogWindow::staticMetaObject, qt_meta_stringdata_Window_RigolControl.data,
      qt_meta_data_Window_RigolControl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Window_RigolControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_RigolControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window_RigolControl.stringdata0))
        return static_cast<void*>(this);
    return GeneralDialogWindow::qt_metacast(_clname);
}

int Window_RigolControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeneralDialogWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Window_RigolControl::signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
