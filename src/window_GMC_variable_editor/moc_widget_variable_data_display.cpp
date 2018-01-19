/****************************************************************************
** Meta object code from reading C++ file 'widget_variable_data_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget_variable_data_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_variable_data_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetVariableDataDisplay_t {
    QByteArrayData data[15];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetVariableDataDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetVariableDataDisplay_t qt_meta_stringdata_WidgetVariableDataDisplay = {
    {
QT_MOC_LITERAL(0, 0, 25), // "WidgetVariableDataDisplay"
QT_MOC_LITERAL(1, 26, 25), // "signal_updatedProfileName"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 12), // "std::string&"
QT_MOC_LITERAL(4, 66, 4), // "name"
QT_MOC_LITERAL(5, 71, 20), // "removeVariableWidget"
QT_MOC_LITERAL(6, 92, 19), // "WidgetVariableData*"
QT_MOC_LITERAL(7, 112, 3), // "obj"
QT_MOC_LITERAL(8, 116, 39), // "on_lineEdit_profileName_editi..."
QT_MOC_LITERAL(9, 156, 40), // "on_lineEdit_profileLabel_edit..."
QT_MOC_LITERAL(10, 197, 33), // "on_pushButton_addVariable_cli..."
QT_MOC_LITERAL(11, 231, 14), // "on_dataChanged"
QT_MOC_LITERAL(12, 246, 38), // "on_doubleSpinBox_PGain_editin..."
QT_MOC_LITERAL(13, 285, 38), // "on_doubleSpinBox_IGain_editin..."
QT_MOC_LITERAL(14, 324, 38) // "on_doubleSpinBox_DGain_editin..."

    },
    "WidgetVariableDataDisplay\0"
    "signal_updatedProfileName\0\0std::string&\0"
    "name\0removeVariableWidget\0WidgetVariableData*\0"
    "obj\0on_lineEdit_profileName_editingFinished\0"
    "on_lineEdit_profileLabel_editingFinished\0"
    "on_pushButton_addVariable_clicked\0"
    "on_dataChanged\0on_doubleSpinBox_PGain_editingFinished\0"
    "on_doubleSpinBox_IGain_editingFinished\0"
    "on_doubleSpinBox_DGain_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetVariableDataDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   62,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,
      13,    0,   70,    2, 0x08 /* Private */,
      14,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetVariableDataDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetVariableDataDisplay *_t = static_cast<WidgetVariableDataDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_updatedProfileName((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->removeVariableWidget((*reinterpret_cast< WidgetVariableData*(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_profileName_editingFinished(); break;
        case 3: _t->on_lineEdit_profileLabel_editingFinished(); break;
        case 4: _t->on_pushButton_addVariable_clicked(); break;
        case 5: _t->on_dataChanged(); break;
        case 6: _t->on_doubleSpinBox_PGain_editingFinished(); break;
        case 7: _t->on_doubleSpinBox_IGain_editingFinished(); break;
        case 8: _t->on_doubleSpinBox_DGain_editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (WidgetVariableDataDisplay::*_t)(std::string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetVariableDataDisplay::signal_updatedProfileName)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WidgetVariableDataDisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetVariableDataDisplay.data,
      qt_meta_data_WidgetVariableDataDisplay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WidgetVariableDataDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetVariableDataDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetVariableDataDisplay.stringdata0))
        return static_cast<void*>(const_cast< WidgetVariableDataDisplay*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetVariableDataDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void WidgetVariableDataDisplay::signal_updatedProfileName(std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
