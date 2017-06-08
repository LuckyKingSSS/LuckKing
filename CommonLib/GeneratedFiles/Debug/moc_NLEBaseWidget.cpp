/****************************************************************************
** Meta object code from reading C++ file 'NLEBaseWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/inc_CommonLib/NLEBaseWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NLEBaseWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NLEBaseWidget_t {
    QByteArrayData data[1];
    char stringdata[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NLEBaseWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NLEBaseWidget_t qt_meta_stringdata_NLEBaseWidget = {
    {
QT_MOC_LITERAL(0, 0, 13) // "NLEBaseWidget"

    },
    "NLEBaseWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NLEBaseWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void NLEBaseWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject NLEBaseWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NLEBaseWidget.data,
      qt_meta_data_NLEBaseWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NLEBaseWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NLEBaseWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NLEBaseWidget.stringdata))
        return static_cast<void*>(const_cast< NLEBaseWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int NLEBaseWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_NLEGlobalShortcut_t {
    QByteArrayData data[4];
    char stringdata[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NLEGlobalShortcut_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NLEGlobalShortcut_t qt_meta_stringdata_NLEGlobalShortcut = {
    {
QT_MOC_LITERAL(0, 0, 17), // "NLEGlobalShortcut"
QT_MOC_LITERAL(1, 18, 7), // "actived"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 2) // "id"

    },
    "NLEGlobalShortcut\0actived\0\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NLEGlobalShortcut[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void NLEGlobalShortcut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NLEGlobalShortcut *_t = static_cast<NLEGlobalShortcut *>(_o);
        switch (_id) {
        case 0: _t->actived((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NLEGlobalShortcut::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NLEGlobalShortcut::actived)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject NLEGlobalShortcut::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NLEGlobalShortcut.data,
      qt_meta_data_NLEGlobalShortcut,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NLEGlobalShortcut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NLEGlobalShortcut::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NLEGlobalShortcut.stringdata))
        return static_cast<void*>(const_cast< NLEGlobalShortcut*>(this));
    return QObject::qt_metacast(_clname);
}

int NLEGlobalShortcut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void NLEGlobalShortcut::actived(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
