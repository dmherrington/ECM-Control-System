/****************************************************************************
** Meta object code from reading C++ file 'widget_segment_time_data.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget_segment_time_data.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_segment_time_data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetSegmentTimeData_t {
    QByteArrayData data[8];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetSegmentTimeData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetSegmentTimeData_t qt_meta_stringdata_WidgetSegmentTimeData = {
    {
QT_MOC_LITERAL(0, 0, 21), // "WidgetSegmentTimeData"
QT_MOC_LITERAL(1, 22, 36), // "on_comboBox_Mode_currentIndex..."
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 4), // "arg1"
QT_MOC_LITERAL(4, 65, 37), // "on_doubleSpinBox_Voltage_valu..."
QT_MOC_LITERAL(5, 103, 37), // "on_doubleSpinBox_Current_valu..."
QT_MOC_LITERAL(6, 141, 34), // "on_doubleSpinBox_Time_valueCh..."
QT_MOC_LITERAL(7, 176, 22) // "on_pushButton_released"

    },
    "WidgetSegmentTimeData\0"
    "on_comboBox_Mode_currentIndexChanged\0"
    "\0arg1\0on_doubleSpinBox_Voltage_valueChanged\0"
    "on_doubleSpinBox_Current_valueChanged\0"
    "on_doubleSpinBox_Time_valueChanged\0"
    "on_pushButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetSegmentTimeData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,

       0        // eod
};

void WidgetSegmentTimeData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetSegmentTimeData *_t = static_cast<WidgetSegmentTimeData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_Mode_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_doubleSpinBox_Voltage_valueChanged((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 2: _t->on_doubleSpinBox_Current_valueChanged((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 3: _t->on_doubleSpinBox_Time_valueChanged((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_released(); break;
        default: ;
        }
    }
}

const QMetaObject WidgetSegmentTimeData::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetSegmentTimeData.data,
      qt_meta_data_WidgetSegmentTimeData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WidgetSegmentTimeData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetSegmentTimeData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetSegmentTimeData.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetSegmentTimeData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
