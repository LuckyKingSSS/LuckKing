/****************************************************************************
** Meta object code from reading C++ file 'mediaplayercontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../mediaplayercontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayercontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MediaPlayerControl_t {
    QByteArrayData data[11];
    char stringdata[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayerControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayerControl_t qt_meta_stringdata_MediaPlayerControl = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MediaPlayerControl"
QT_MOC_LITERAL(1, 19, 16), // "PlayStopCallback"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "PlayStartCallback"
QT_MOC_LITERAL(4, 55, 17), // "PlayPauseCallback"
QT_MOC_LITERAL(5, 73, 18), // "PlayFinishCallback"
QT_MOC_LITERAL(6, 92, 20), // "QueuePlayingCallback"
QT_MOC_LITERAL(7, 113, 6), // "frames"
QT_MOC_LITERAL(8, 120, 15), // "QueuePlayerStop"
QT_MOC_LITERAL(9, 136, 17), // "QueuePlayerFinish"
QT_MOC_LITERAL(10, 154, 21) // "QueuePlayerSeekFinish"

    },
    "MediaPlayerControl\0PlayStopCallback\0"
    "\0PlayStartCallback\0PlayPauseCallback\0"
    "PlayFinishCallback\0QueuePlayingCallback\0"
    "frames\0QueuePlayerStop\0QueuePlayerFinish\0"
    "QueuePlayerSeekFinish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayerControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   58,    2, 0x02 /* Public */,
       8,    0,   61,    2, 0x02 /* Public */,
       9,    0,   62,    2, 0x02 /* Public */,
      10,    1,   63,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void MediaPlayerControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MediaPlayerControl *_t = static_cast<MediaPlayerControl *>(_o);
        switch (_id) {
        case 0: _t->PlayStopCallback(); break;
        case 1: _t->PlayStartCallback(); break;
        case 2: _t->PlayPauseCallback(); break;
        case 3: _t->PlayFinishCallback(); break;
        case 4: _t->QueuePlayingCallback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->QueuePlayerStop(); break;
        case 6: _t->QueuePlayerFinish(); break;
        case 7: _t->QueuePlayerSeekFinish((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MediaPlayerControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayerControl::PlayStopCallback)) {
                *result = 0;
            }
        }
        {
            typedef void (MediaPlayerControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayerControl::PlayStartCallback)) {
                *result = 1;
            }
        }
        {
            typedef void (MediaPlayerControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayerControl::PlayPauseCallback)) {
                *result = 2;
            }
        }
        {
            typedef void (MediaPlayerControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayerControl::PlayFinishCallback)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MediaPlayerControl::staticMetaObject = {
    { &IMediaPlayerControl::staticMetaObject, qt_meta_stringdata_MediaPlayerControl.data,
      qt_meta_data_MediaPlayerControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MediaPlayerControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayerControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayerControl.stringdata))
        return static_cast<void*>(const_cast< MediaPlayerControl*>(this));
    return IMediaPlayerControl::qt_metacast(_clname);
}

int MediaPlayerControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IMediaPlayerControl::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MediaPlayerControl::PlayStopCallback()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MediaPlayerControl::PlayStartCallback()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MediaPlayerControl::PlayPauseCallback()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MediaPlayerControl::PlayFinishCallback()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
