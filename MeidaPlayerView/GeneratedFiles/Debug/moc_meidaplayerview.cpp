/****************************************************************************
** Meta object code from reading C++ file 'meidaplayerview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../../include/inc_MediaPlayerView/meidaplayerview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'meidaplayerview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MeidaPlayerView_t {
    QByteArrayData data[10];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeidaPlayerView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeidaPlayerView_t qt_meta_stringdata_MeidaPlayerView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MeidaPlayerView"
QT_MOC_LITERAL(1, 16, 15), // "signalSeekToPos"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "iFrame"
QT_MOC_LITERAL(4, 40, 28), // "signalPlaySliderValueChanged"
QT_MOC_LITERAL(5, 69, 9), // "iNewValue"
QT_MOC_LITERAL(6, 79, 20), // "sigalDurationChanged"
QT_MOC_LITERAL(7, 100, 21), // "sigalSyncRulerHandler"
QT_MOC_LITERAL(8, 122, 9), // "playMovie"
QT_MOC_LITERAL(9, 132, 12) // "strMoviePath"

    },
    "MeidaPlayerView\0signalSeekToPos\0\0"
    "iFrame\0signalPlaySliderValueChanged\0"
    "iNewValue\0sigalDurationChanged\0"
    "sigalSyncRulerHandler\0playMovie\0"
    "strMoviePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeidaPlayerView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void MeidaPlayerView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeidaPlayerView *_t = static_cast<MeidaPlayerView *>(_o);
        switch (_id) {
        case 0: _t->signalSeekToPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalPlaySliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigalDurationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sigalSyncRulerHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->playMovie((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MeidaPlayerView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeidaPlayerView::signalSeekToPos)) {
                *result = 0;
            }
        }
        {
            typedef void (MeidaPlayerView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeidaPlayerView::signalPlaySliderValueChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MeidaPlayerView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeidaPlayerView::sigalDurationChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (MeidaPlayerView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeidaPlayerView::sigalSyncRulerHandler)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MeidaPlayerView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MeidaPlayerView.data,
      qt_meta_data_MeidaPlayerView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeidaPlayerView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeidaPlayerView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeidaPlayerView.stringdata))
        return static_cast<void*>(const_cast< MeidaPlayerView*>(this));
    return QWidget::qt_metacast(_clname);
}

int MeidaPlayerView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MeidaPlayerView::signalSeekToPos(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MeidaPlayerView::signalPlaySliderValueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MeidaPlayerView::sigalDurationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MeidaPlayerView::sigalSyncRulerHandler(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
