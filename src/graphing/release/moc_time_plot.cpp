/****************************************************************************
** Meta object code from reading C++ file 'time_plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../time_plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'time_plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_graphing__TimePlot_t {
    QByteArrayData data[5];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_graphing__TimePlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_graphing__TimePlot_t qt_meta_stringdata_graphing__TimePlot = {
    {
QT_MOC_LITERAL(0, 0, 18), // "graphing::TimePlot"
QT_MOC_LITERAL(1, 19, 6), // "Replot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 28), // "QCustomPlot::RefreshPriority"
QT_MOC_LITERAL(4, 56, 15) // "refreshPriority"

    },
    "graphing::TimePlot\0Replot\0\0"
    "QCustomPlot::RefreshPriority\0"
    "refreshPriority"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_graphing__TimePlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x01 /* Protected */,
       1,    0,   27,    2, 0x21 /* Protected | MethodCloned */,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void graphing::TimePlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimePlot *_t = static_cast<TimePlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Replot((*reinterpret_cast< QCustomPlot::RefreshPriority(*)>(_a[1]))); break;
        case 1: _t->Replot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject graphing::TimePlot::staticMetaObject = {
    { &QCustomPlot::staticMetaObject, qt_meta_stringdata_graphing__TimePlot.data,
      qt_meta_data_graphing__TimePlot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *graphing::TimePlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *graphing::TimePlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_graphing__TimePlot.stringdata0))
        return static_cast<void*>(this);
    return QCustomPlot::qt_metacast(_clname);
}

int graphing::TimePlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
