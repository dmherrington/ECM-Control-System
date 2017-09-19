/****************************************************************************
** Meta object code from reading C++ file 'widget_segment_time_data.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget_segment_time_data.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_segment_time_data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Widget_SegmentTimeData_t {
    QByteArrayData data[9];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_SegmentTimeData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_SegmentTimeData_t qt_meta_stringdata_Widget_SegmentTimeData = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Widget_SegmentTimeData"
QT_MOC_LITERAL(1, 23, 20), // "valueChanged_Voltage"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 8), // "newValue"
QT_MOC_LITERAL(4, 54, 37), // "on_doubleSpinBox_voltage_valu..."
QT_MOC_LITERAL(5, 92, 4), // "arg1"
QT_MOC_LITERAL(6, 97, 37), // "on_doubleSpinBox_current_valu..."
QT_MOC_LITERAL(7, 135, 38), // "on_doubleSpinBox_duration_val..."
QT_MOC_LITERAL(8, 174, 31) // "on_comboBox_currentIndexChanged"

    },
    "Widget_SegmentTimeData\0valueChanged_Voltage\0"
    "\0newValue\0on_doubleSpinBox_voltage_valueChanged\0"
    "arg1\0on_doubleSpinBox_current_valueChanged\0"
    "on_doubleSpinBox_duration_valueChanged\0"
    "on_comboBox_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_SegmentTimeData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       6,    1,   45,    2, 0x08 /* Private */,
       7,    1,   48,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void Widget_SegmentTimeData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget_SegmentTimeData *_t = static_cast<Widget_SegmentTimeData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged_Voltage((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 1: _t->on_doubleSpinBox_voltage_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_doubleSpinBox_current_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_doubleSpinBox_duration_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Widget_SegmentTimeData::*_t)(const double & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget_SegmentTimeData::valueChanged_Voltage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Widget_SegmentTimeData::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_SegmentTimeData.data,
      qt_meta_data_Widget_SegmentTimeData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Widget_SegmentTimeData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_SegmentTimeData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_SegmentTimeData.stringdata0))
        return static_cast<void*>(const_cast< Widget_SegmentTimeData*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_SegmentTimeData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Widget_SegmentTimeData::valueChanged_Voltage(const double & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
