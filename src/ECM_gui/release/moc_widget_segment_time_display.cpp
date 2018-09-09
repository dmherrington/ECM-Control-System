/****************************************************************************
** Meta object code from reading C++ file 'widget_segment_time_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../munk_dialog/widget_segment_time_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_segment_time_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetSegmentTimeDisplay_t {
    QByteArrayData data[6];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetSegmentTimeDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetSegmentTimeDisplay_t qt_meta_stringdata_WidgetSegmentTimeDisplay = {
    {
QT_MOC_LITERAL(0, 0, 24), // "WidgetSegmentTimeDisplay"
QT_MOC_LITERAL(1, 25, 11), // "updatedData"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 50), // "std::list<registers_Munk::Seg..."
QT_MOC_LITERAL(4, 89, 7), // "newData"
QT_MOC_LITERAL(5, 97, 26) // "signal_SegmentDataModified"

    },
    "WidgetSegmentTimeDisplay\0updatedData\0"
    "\0std::list<registers_Munk::SegmentTimeDataDetailed>\0"
    "newData\0signal_SegmentDataModified"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetSegmentTimeDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void WidgetSegmentTimeDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetSegmentTimeDisplay *_t = static_cast<WidgetSegmentTimeDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatedData((*reinterpret_cast< const std::list<registers_Munk::SegmentTimeDataDetailed>(*)>(_a[1]))); break;
        case 1: _t->signal_SegmentDataModified(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetSegmentTimeDisplay::*)(const std::list<registers_Munk::SegmentTimeDataDetailed> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetSegmentTimeDisplay::updatedData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetSegmentTimeDisplay::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetSegmentTimeDisplay::signal_SegmentDataModified)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetSegmentTimeDisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetSegmentTimeDisplay.data,
      qt_meta_data_WidgetSegmentTimeDisplay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WidgetSegmentTimeDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetSegmentTimeDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetSegmentTimeDisplay.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "WidgetTimeDataInterface"))
        return static_cast< WidgetTimeDataInterface*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetSegmentTimeDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void WidgetSegmentTimeDisplay::updatedData(const std::list<registers_Munk::SegmentTimeDataDetailed> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetSegmentTimeDisplay::signal_SegmentDataModified()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
