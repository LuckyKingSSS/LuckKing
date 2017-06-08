/****************************************************************************
** Meta object code from reading C++ file 'IMediaPlayerControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../../include/inc_MediaPlayerView/IMediaPlayerControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IMediaPlayerControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IMediaPlayerControl_t {
    QByteArrayData data[5];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IMediaPlayerControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IMediaPlayerControl_t qt_meta_stringdata_IMediaPlayerControl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "IMediaPlayerControl"
QT_MOC_LITERAL(1, 20, 15), // "PlayingCallback"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "frames"
QT_MOC_LITERAL(4, 44, 17) // "PlayStartCallback"

    },
    "IMediaPlayerControl\0PlayingCallback\0"
    "\0frames\0PlayStartCallback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IMediaPlayerControl[] = {

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
       4,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void IMediaPlayerControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IMediaPlayerControl *_t = static_cast<IMediaPlayerControl *>(_o);
        switch (_id) {
        case 0: _t->PlayingCallback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->PlayStartCallback(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IMediaPlayerControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMediaPlayerControl::PlayingCallback)) {
                *result = 0;
            }
        }
        {
            typedef void (IMediaPlayerControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMediaPlayerControl::PlayStartCallback)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject IMediaPlayerControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IMediaPlayerControl.data,
      qt_meta_data_IMediaPlayerControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IMediaPlayerControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IMediaPlayerControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IMediaPlayerControl.stringdata))
        return static_cast<void*>(const_cast< IMediaPlayerControl*>(this));
    return QObject::qt_metacast(_clname);
}

int IMediaPlayerControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void IMediaPlayerControl::PlayingCallback(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IMediaPlayerControl::PlayStartCallback()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
