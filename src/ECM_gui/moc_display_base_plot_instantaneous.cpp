/****************************************************************************
** Meta object code from reading C++ file 'display_base_plot_instantaneous.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SensorDisplay/display_base_plot_instantaneous.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display_base_plot_instantaneous.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DisplayBasePlotInstantaneous_t {
    QByteArrayData data[14];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DisplayBasePlotInstantaneous_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DisplayBasePlotInstantaneous_t qt_meta_stringdata_DisplayBasePlotInstantaneous = {
    {
QT_MOC_LITERAL(0, 0, 28), // "DisplayBasePlotInstantaneous"
QT_MOC_LITERAL(1, 29, 10), // "UpdateAxis"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 10), // "leftWindow"
QT_MOC_LITERAL(4, 52, 11), // "rightWindow"
QT_MOC_LITERAL(5, 64, 11), // "CurrentTime"
QT_MOC_LITERAL(6, 76, 11), // "currentTime"
QT_MOC_LITERAL(7, 88, 18), // "PlottedDataUpdated"
QT_MOC_LITERAL(8, 107, 17), // "ChangeColorScheme"
QT_MOC_LITERAL(9, 125, 6), // "scheme"
QT_MOC_LITERAL(10, 132, 26), // "on_pushButton_Grid_clicked"
QT_MOC_LITERAL(11, 159, 28), // "on_pushButton_Legend_clicked"
QT_MOC_LITERAL(12, 188, 33), // "on_pushButton_GridSpacing_cli..."
QT_MOC_LITERAL(13, 222, 29) // "on_pushButton_yWindow_clicked"

    },
    "DisplayBasePlotInstantaneous\0UpdateAxis\0"
    "\0leftWindow\0rightWindow\0CurrentTime\0"
    "currentTime\0PlottedDataUpdated\0"
    "ChangeColorScheme\0scheme\0"
    "on_pushButton_Grid_clicked\0"
    "on_pushButton_Legend_clicked\0"
    "on_pushButton_GridSpacing_clicked\0"
    "on_pushButton_yWindow_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplayBasePlotInstantaneous[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x0a /* Public */,
       5,    1,   59,    2, 0x0a /* Public */,
       7,    0,   62,    2, 0x0a /* Public */,
       8,    1,   63,    2, 0x0a /* Public */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,    3,    4,
    QMetaType::Void, QMetaType::QDateTime,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DisplayBasePlotInstantaneous::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DisplayBasePlotInstantaneous *_t = static_cast<DisplayBasePlotInstantaneous *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdateAxis((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 1: _t->CurrentTime((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 2: _t->PlottedDataUpdated(); break;
        case 3: _t->ChangeColorScheme((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_Grid_clicked(); break;
        case 5: _t->on_pushButton_Legend_clicked(); break;
        case 6: _t->on_pushButton_GridSpacing_clicked(); break;
        case 7: _t->on_pushButton_yWindow_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject DisplayBasePlotInstantaneous::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DisplayBasePlotInstantaneous.data,
      qt_meta_data_DisplayBasePlotInstantaneous,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DisplayBasePlotInstantaneous::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayBasePlotInstantaneous::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayBasePlotInstantaneous.stringdata0))
        return static_cast<void*>(const_cast< DisplayBasePlotInstantaneous*>(this));
    if (!strcmp(_clname, "ISensorDisplay"))
        return static_cast< ISensorDisplay*>(const_cast< DisplayBasePlotInstantaneous*>(this));
    return QWidget::qt_metacast(_clname);
}

int DisplayBasePlotInstantaneous::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
