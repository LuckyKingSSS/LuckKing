/****************************************************************************
** Meta object code from reading C++ file 'propertysettingwnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../propertysettingwnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'propertysettingwnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PropertySettingWnd_t {
    QByteArrayData data[9];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PropertySettingWnd_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PropertySettingWnd_t qt_meta_stringdata_PropertySettingWnd = {
    {
QT_MOC_LITERAL(0, 0, 18), // "PropertySettingWnd"
QT_MOC_LITERAL(1, 19, 20), // "signalChangeLanguage"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 19), // "slotOnChooseAccount"
QT_MOC_LITERAL(4, 61, 7), // "strText"
QT_MOC_LITERAL(5, 69, 18), // "slotChangeLanguage"
QT_MOC_LITERAL(6, 88, 6), // "iIndex"
QT_MOC_LITERAL(7, 95, 13), // "slotTranslate"
QT_MOC_LITERAL(8, 109, 11) // "strLanguage"

    },
    "PropertySettingWnd\0signalChangeLanguage\0"
    "\0slotOnChooseAccount\0strText\0"
    "slotChangeLanguage\0iIndex\0slotTranslate\0"
    "strLanguage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PropertySettingWnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void PropertySettingWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PropertySettingWnd *_t = static_cast<PropertySettingWnd *>(_o);
        switch (_id) {
        case 0: _t->signalChangeLanguage(); break;
        case 1: _t->slotOnChooseAccount((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->slotChangeLanguage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slotTranslate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PropertySettingWnd::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PropertySettingWnd::signalChangeLanguage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PropertySettingWnd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PropertySettingWnd.data,
      qt_meta_data_PropertySettingWnd,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PropertySettingWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PropertySettingWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PropertySettingWnd.stringdata))
        return static_cast<void*>(const_cast< PropertySettingWnd*>(this));
    return QWidget::qt_metacast(_clname);
}

int PropertySettingWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PropertySettingWnd::signalChangeLanguage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
