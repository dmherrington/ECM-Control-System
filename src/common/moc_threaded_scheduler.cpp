/****************************************************************************
** Meta object code from reading C++ file 'threaded_scheduler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "threaded_scheduler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threaded_scheduler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadedScheduler_t {
    QByteArrayData data[4];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadedScheduler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadedScheduler_t qt_meta_stringdata_ThreadedScheduler = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ThreadedScheduler"
QT_MOC_LITERAL(1, 18, 11), // "PerformWork"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8) // "CallWork"

    },
    "ThreadedScheduler\0PerformWork\0\0CallWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadedScheduler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x00 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void ThreadedScheduler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadedScheduler *_t = static_cast<ThreadedScheduler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PerformWork(); break;
        case 1: _t->CallWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadedScheduler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadedScheduler::PerformWork)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ThreadedScheduler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadedScheduler.data,
      qt_meta_data_ThreadedScheduler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ThreadedScheduler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadedScheduler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadedScheduler.stringdata0))
        return static_cast<void*>(const_cast< ThreadedScheduler*>(this));
    return QObject::qt_metacast(_clname);
}

int ThreadedScheduler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadedScheduler::PerformWork()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
