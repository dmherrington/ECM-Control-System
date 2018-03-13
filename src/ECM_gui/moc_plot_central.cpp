/****************************************************************************
** Meta object code from reading C++ file 'plot_central.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "plot_central.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot_central.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlotCentral_t {
    QByteArrayData data[14];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlotCentral_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlotCentral_t qt_meta_stringdata_PlotCentral = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PlotCentral"
QT_MOC_LITERAL(1, 12, 15), // "ComponentsAdded"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 27), // "QList<common::TupleECMData>"
QT_MOC_LITERAL(4, 57, 13), // "componentList"
QT_MOC_LITERAL(5, 71, 24), // "SelectedExpressionString"
QT_MOC_LITERAL(6, 96, 8), // "selected"
QT_MOC_LITERAL(7, 105, 6), // "string"
QT_MOC_LITERAL(8, 112, 17), // "ComponentsRemoved"
QT_MOC_LITERAL(9, 130, 11), // "OnPlotAdded"
QT_MOC_LITERAL(10, 142, 4), // "expr"
QT_MOC_LITERAL(11, 147, 14), // "OnPlotSelected"
QT_MOC_LITERAL(12, 162, 16), // "OnPlotUnSelected"
QT_MOC_LITERAL(13, 179, 12) // "OnPlotDelete"

    },
    "PlotCentral\0ComponentsAdded\0\0"
    "QList<common::TupleECMData>\0componentList\0"
    "SelectedExpressionString\0selected\0"
    "string\0ComponentsRemoved\0OnPlotAdded\0"
    "expr\0OnPlotSelected\0OnPlotUnSelected\0"
    "OnPlotDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlotCentral[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    2,   52,    2, 0x06 /* Public */,
       8,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   60,    2, 0x08 /* Private */,
      11,    1,   63,    2, 0x08 /* Private */,
      12,    0,   66,    2, 0x08 /* Private */,
      13,    1,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    6,    7,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void PlotCentral::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlotCentral *_t = static_cast<PlotCentral *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ComponentsAdded((*reinterpret_cast< QList<common::TupleECMData>(*)>(_a[1]))); break;
        case 1: _t->SelectedExpressionString((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->ComponentsRemoved((*reinterpret_cast< QList<common::TupleECMData>(*)>(_a[1]))); break;
        case 3: _t->OnPlotAdded((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->OnPlotSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->OnPlotUnSelected(); break;
        case 6: _t->OnPlotDelete((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<common::TupleECMData> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<common::TupleECMData> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlotCentral::*_t)(QList<common::TupleECMData> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotCentral::ComponentsAdded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlotCentral::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotCentral::SelectedExpressionString)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlotCentral::*_t)(QList<common::TupleECMData> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotCentral::ComponentsRemoved)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject PlotCentral::staticMetaObject = {
    { &graphing::PlotHandler::staticMetaObject, qt_meta_stringdata_PlotCentral.data,
      qt_meta_data_PlotCentral,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlotCentral::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlotCentral::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlotCentral.stringdata0))
        return static_cast<void*>(const_cast< PlotCentral*>(this));
    return graphing::PlotHandler::qt_metacast(_clname);
}

int PlotCentral::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = graphing::PlotHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PlotCentral::ComponentsAdded(QList<common::TupleECMData> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlotCentral::SelectedExpressionString(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlotCentral::ComponentsRemoved(QList<common::TupleECMData> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
