/****************************************************************************
** Meta object code from reading C++ file 'window_motion_profile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../misc_dialogs/window_motion_profile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_motion_profile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_MotionProfile_t {
    QByteArrayData data[13];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_MotionProfile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_MotionProfile_t qt_meta_stringdata_Window_MotionProfile = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Window_MotionProfile"
QT_MOC_LITERAL(1, 21, 28), // "signal_DialogWindowVisibilty"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 38), // "GeneralDialogWindow::DialogWi..."
QT_MOC_LITERAL(4, 90, 4), // "type"
QT_MOC_LITERAL(5, 95, 10), // "visibility"
QT_MOC_LITERAL(6, 106, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(7, 131, 26), // "slot_MCNewProgramAvailable"
QT_MOC_LITERAL(8, 158, 14), // "ProgramGeneric"
QT_MOC_LITERAL(9, 173, 7), // "program"
QT_MOC_LITERAL(10, 181, 27), // "on_codeTextEdit_textChanged"
QT_MOC_LITERAL(11, 209, 36), // "on_pushButton_UploadProgram_r..."
QT_MOC_LITERAL(12, 246, 38) // "on_pushButton_DownloadProgram..."

    },
    "Window_MotionProfile\0signal_DialogWindowVisibilty\0"
    "\0GeneralDialogWindow::DialogWindowTypes\0"
    "type\0visibility\0on_actionClose_triggered\0"
    "slot_MCNewProgramAvailable\0ProgramGeneric\0"
    "program\0on_codeTextEdit_textChanged\0"
    "on_pushButton_UploadProgram_released\0"
    "on_pushButton_DownloadProgram_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_MotionProfile[] = {

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
       7,    1,   50,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,
      11,    0,   54,    2, 0x08 /* Private */,
      12,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window_MotionProfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window_MotionProfile *_t = static_cast<Window_MotionProfile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_DialogWindowVisibilty((*reinterpret_cast< const GeneralDialogWindow::DialogWindowTypes(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->on_actionClose_triggered(); break;
        case 2: _t->slot_MCNewProgramAvailable((*reinterpret_cast< const ProgramGeneric(*)>(_a[1]))); break;
        case 3: _t->on_codeTextEdit_textChanged(); break;
        case 4: _t->on_pushButton_UploadProgram_released(); break;
        case 5: _t->on_pushButton_DownloadProgram_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Window_MotionProfile::*)(const GeneralDialogWindow::DialogWindowTypes & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window_MotionProfile::signal_DialogWindowVisibilty)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window_MotionProfile::staticMetaObject = {
    { &GeneralDialogWindow::staticMetaObject, qt_meta_stringdata_Window_MotionProfile.data,
      qt_meta_data_Window_MotionProfile,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Window_MotionProfile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_MotionProfile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window_MotionProfile.stringdata0))
        return static_cast<void*>(this);
    return GeneralDialogWindow::qt_metacast(_clname);
}

int Window_MotionProfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Window_MotionProfile::signal_DialogWindowVisibilty(const GeneralDialogWindow::DialogWindowTypes & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
