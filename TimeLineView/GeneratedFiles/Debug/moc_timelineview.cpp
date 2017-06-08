/****************************************************************************
** Meta object code from reading C++ file 'timelineview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../../include/inc_TimelineView/timelineview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timelineview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimeLineView_t {
    QByteArrayData data[13];
    char stringdata[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeLineView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeLineView_t qt_meta_stringdata_TimeLineView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TimeLineView"
QT_MOC_LITERAL(1, 13, 17), // "signalSeekToFrame"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "iFrame"
QT_MOC_LITERAL(4, 39, 28), // "signalPlaySliderValueChanged"
QT_MOC_LITERAL(5, 68, 6), // "iValue"
QT_MOC_LITERAL(6, 75, 20), // "sigalDurationChanged"
QT_MOC_LITERAL(7, 96, 9), // "iNewValue"
QT_MOC_LITERAL(8, 106, 21), // "sigalSyncRulerHandler"
QT_MOC_LITERAL(9, 128, 22), // "signalSyncPlayerSlider"
QT_MOC_LITERAL(10, 151, 5), // "point"
QT_MOC_LITERAL(11, 157, 9), // "seekToPos"
QT_MOC_LITERAL(12, 167, 3) // "pos"

    },
    "TimeLineView\0signalSeekToFrame\0\0iFrame\0"
    "signalPlaySliderValueChanged\0iValue\0"
    "sigalDurationChanged\0iNewValue\0"
    "sigalSyncRulerHandler\0signalSyncPlayerSlider\0"
    "point\0seekToPos\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeLineView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       8,    1,   53,    2, 0x06 /* Public */,
       9,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QPointF,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,   12,

       0        // eod
};

void TimeLineView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeLineView *_t = static_cast<TimeLineView *>(_o);
        switch (_id) {
        case 0: _t->signalSeekToFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalPlaySliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigalDurationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sigalSyncRulerHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->signalSyncPlayerSlider((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 5: _t->seekToPos((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimeLineView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLineView::signalSeekToFrame)) {
                *result = 0;
            }
        }
        {
            typedef void (TimeLineView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLineView::signalPlaySliderValueChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TimeLineView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLineView::sigalDurationChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (TimeLineView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLineView::sigalSyncRulerHandler)) {
                *result = 3;
            }
        }
        {
            typedef void (TimeLineView::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeLineView::signalSyncPlayerSlider)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject TimeLineView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimeLineView.data,
      qt_meta_data_TimeLineView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimeLineView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeLineView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimeLineView.stringdata))
        return static_cast<void*>(const_cast< TimeLineView*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimeLineView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TimeLineView::signalSeekToFrame(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TimeLineView::signalPlaySliderValueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TimeLineView::sigalDurationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TimeLineView::sigalSyncRulerHandler(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TimeLineView::signalSyncPlayerSlider(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
