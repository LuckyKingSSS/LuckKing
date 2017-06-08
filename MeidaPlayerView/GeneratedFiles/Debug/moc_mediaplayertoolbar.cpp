/****************************************************************************
** Meta object code from reading C++ file 'mediaplayertoolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../mediaplayertoolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayertoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MediaPlayerToolBar_t {
    QByteArrayData data[10];
    char stringdata[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayerToolBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayerToolBar_t qt_meta_stringdata_MediaPlayerToolBar = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MediaPlayerToolBar"
QT_MOC_LITERAL(1, 19, 7), // "Clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "id"
QT_MOC_LITERAL(4, 31, 1), // "p"
QT_MOC_LITERAL(5, 33, 23), // "signalSliderValueChange"
QT_MOC_LITERAL(6, 57, 9), // "inewValue"
QT_MOC_LITERAL(7, 67, 20), // "sigalDurationChanged"
QT_MOC_LITERAL(8, 88, 21), // "sigalSyncRulerHandler"
QT_MOC_LITERAL(9, 110, 6) // "iValue"

    },
    "MediaPlayerToolBar\0Clicked\0\0id\0p\0"
    "signalSliderValueChange\0inewValue\0"
    "sigalDurationChanged\0sigalSyncRulerHandler\0"
    "iValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayerToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    1,   39,    2, 0x06 /* Public */,
       7,    1,   42,    2, 0x06 /* Public */,
       8,    1,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void MediaPlayerToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MediaPlayerToolBar *_t = static_cast<MediaPlayerToolBar *>(_o);
        switch (_id) {
        case 0: _t->Clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 1: _t->signalSliderValueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigalDurationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sigalSyncRulerHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MediaPlayerToolBar::*_t)(int , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayerToolBar::Clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (MediaPlayerToolBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayerToolBar::signalSliderValueChange)) {
                *result = 1;
            }
        }
        {
            typedef void (MediaPlayerToolBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayerToolBar::sigalDurationChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (MediaPlayerToolBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayerToolBar::sigalSyncRulerHandler)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MediaPlayerToolBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MediaPlayerToolBar.data,
      qt_meta_data_MediaPlayerToolBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MediaPlayerToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayerToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayerToolBar.stringdata))
        return static_cast<void*>(const_cast< MediaPlayerToolBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int MediaPlayerToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MediaPlayerToolBar::Clicked(int _t1, QPoint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MediaPlayerToolBar::signalSliderValueChange(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MediaPlayerToolBar::sigalDurationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MediaPlayerToolBar::sigalSyncRulerHandler(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
