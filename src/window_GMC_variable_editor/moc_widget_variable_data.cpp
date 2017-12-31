/****************************************************************************
** Meta object code from reading C++ file 'widget_variable_data.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget_variable_data.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_variable_data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetVariableData_t {
    QByteArrayData data[12];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetVariableData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetVariableData_t qt_meta_stringdata_WidgetVariableData = {
    {
QT_MOC_LITERAL(0, 0, 18), // "WidgetVariableData"
QT_MOC_LITERAL(1, 19, 18), // "signalRemoveWidget"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 19), // "WidgetVariableData*"
QT_MOC_LITERAL(4, 59, 3), // "var"
QT_MOC_LITERAL(5, 63, 17), // "signalDataChanged"
QT_MOC_LITERAL(6, 81, 36), // "on_pushButton_removeVariable_..."
QT_MOC_LITERAL(7, 118, 39), // "on_lineEdit_displayName_editi..."
QT_MOC_LITERAL(8, 158, 35), // "on_lineEdit_varName_editingFi..."
QT_MOC_LITERAL(9, 194, 36), // "on_doubleSpinBox_max_editingF..."
QT_MOC_LITERAL(10, 231, 36), // "on_doubleSpinBox_min_editingF..."
QT_MOC_LITERAL(11, 268, 40) // "on_doubleSpinBox_default_edit..."

    },
    "WidgetVariableData\0signalRemoveWidget\0"
    "\0WidgetVariableData*\0var\0signalDataChanged\0"
    "on_pushButton_removeVariable_clicked\0"
    "on_lineEdit_displayName_editingFinished\0"
    "on_lineEdit_varName_editingFinished\0"
    "on_doubleSpinBox_max_editingFinished\0"
    "on_doubleSpinBox_min_editingFinished\0"
    "on_doubleSpinBox_default_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetVariableData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetVariableData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetVariableData *_t = static_cast<WidgetVariableData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalRemoveWidget((*reinterpret_cast< WidgetVariableData*(*)>(_a[1]))); break;
        case 1: _t->signalDataChanged(); break;
        case 2: _t->on_pushButton_removeVariable_clicked(); break;
        case 3: _t->on_lineEdit_displayName_editingFinished(); break;
        case 4: _t->on_lineEdit_varName_editingFinished(); break;
        case 5: _t->on_doubleSpinBox_max_editingFinished(); break;
        case 6: _t->on_doubleSpinBox_min_editingFinished(); break;
        case 7: _t->on_doubleSpinBox_default_editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetVariableData* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WidgetVariableData::*_t)(WidgetVariableData * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetVariableData::signalRemoveWidget)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WidgetVariableData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetVariableData::signalDataChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WidgetVariableData::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetVariableData.data,
      qt_meta_data_WidgetVariableData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WidgetVariableData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetVariableData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetVariableData.stringdata0))
        return static_cast<void*>(const_cast< WidgetVariableData*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetVariableData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void WidgetVariableData::signalRemoveWidget(WidgetVariableData * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetVariableData::signalDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
