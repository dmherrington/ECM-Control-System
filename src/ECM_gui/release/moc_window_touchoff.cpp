/****************************************************************************
** Meta object code from reading C++ file 'window_touchoff.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../misc_dialogs/window_touchoff.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_touchoff.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_Touchoff_t {
    QByteArrayData data[13];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_Touchoff_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_Touchoff_t qt_meta_stringdata_Window_Touchoff = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Window_Touchoff"
QT_MOC_LITERAL(1, 16, 28), // "signal_DialogWindowVisibilty"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 38), // "GeneralDialogWindow::DialogWi..."
QT_MOC_LITERAL(4, 85, 4), // "type"
QT_MOC_LITERAL(5, 90, 10), // "visibility"
QT_MOC_LITERAL(6, 101, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(7, 126, 38), // "on_pushButton_ExecuteTouchoff..."
QT_MOC_LITERAL(8, 165, 34), // "on_pushButton_TouchoffRef_rel..."
QT_MOC_LITERAL(9, 200, 29), // "slot_UpdateMotionProfileState"
QT_MOC_LITERAL(10, 230, 18), // "MotionProfileState"
QT_MOC_LITERAL(11, 249, 5), // "state"
QT_MOC_LITERAL(12, 255, 34) // "on_pushButton_TouchoffGap_rel..."

    },
    "Window_Touchoff\0signal_DialogWindowVisibilty\0"
    "\0GeneralDialogWindow::DialogWindowTypes\0"
    "type\0visibility\0on_actionClose_triggered\0"
    "on_pushButton_ExecuteTouchoff_released\0"
    "on_pushButton_TouchoffRef_released\0"
    "slot_UpdateMotionProfileState\0"
    "MotionProfileState\0state\0"
    "on_pushButton_TouchoffGap_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_Touchoff[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,
       9,    1,   52,    2, 0x08 /* Private */,
      12,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

void Window_Touchoff::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window_Touchoff *_t = static_cast<Window_Touchoff *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_DialogWindowVisibilty((*reinterpret_cast< const GeneralDialogWindow::DialogWindowTypes(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->on_actionClose_triggered(); break;
        case 2: _t->on_pushButton_ExecuteTouchoff_released(); break;
        case 3: _t->on_pushButton_TouchoffRef_released(); break;
        case 4: _t->slot_UpdateMotionProfileState((*reinterpret_cast< const MotionProfileState(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_TouchoffGap_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            using _t = void (Window_Touchoff::*)(const GeneralDialogWindow::DialogWindowTypes & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window_Touchoff::signal_DialogWindowVisibilty)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window_Touchoff::staticMetaObject = {
    { &GeneralDialogWindow::staticMetaObject, qt_meta_stringdata_Window_Touchoff.data,
      qt_meta_data_Window_Touchoff,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Window_Touchoff::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_Touchoff::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window_Touchoff.stringdata0))
        return static_cast<void*>(this);
    return GeneralDialogWindow::qt_metacast(_clname);
}

int Window_Touchoff::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeneralDialogWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Window_Touchoff::signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
