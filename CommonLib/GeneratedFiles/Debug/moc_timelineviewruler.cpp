/****************************************************************************
** Meta object code from reading C++ file 'timelineviewruler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../timelineviewruler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timelineviewruler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimelineViewRuler_t {
    QByteArrayData data[12];
    char stringdata[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewRuler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewRuler_t qt_meta_stringdata_TimelineViewRuler = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TimelineViewRuler"
QT_MOC_LITERAL(1, 18, 18), // "StartFramesChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 16), // "EndFramesChanged"
QT_MOC_LITERAL(4, 55, 13), // "FramesChanged"
QT_MOC_LITERAL(5, 69, 5), // "frame"
QT_MOC_LITERAL(6, 75, 16), // "StartZoomChanged"
QT_MOC_LITERAL(7, 92, 14), // "EndZoomChanged"
QT_MOC_LITERAL(8, 107, 11), // "ZoomChanged"
QT_MOC_LITERAL(9, 119, 4), // "zoom"
QT_MOC_LITERAL(10, 124, 19), // "OffsetFramesChanged"
QT_MOC_LITERAL(11, 144, 6) // "frames"

    },
    "TimelineViewRuler\0StartFramesChanged\0"
    "\0EndFramesChanged\0FramesChanged\0frame\0"
    "StartZoomChanged\0EndZoomChanged\0"
    "ZoomChanged\0zoom\0OffsetFramesChanged\0"
    "frames"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewRuler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       6,    0,   54,    2, 0x06 /* Public */,
       7,    0,   55,    2, 0x06 /* Public */,
       8,    1,   56,    2, 0x06 /* Public */,
      10,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void TimelineViewRuler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineViewRuler *_t = static_cast<TimelineViewRuler *>(_o);
        switch (_id) {
        case 0: _t->StartFramesChanged(); break;
        case 1: _t->EndFramesChanged(); break;
        case 2: _t->FramesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->StartZoomChanged(); break;
        case 4: _t->EndZoomChanged(); break;
        case 5: _t->ZoomChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OffsetFramesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineViewRuler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewRuler::StartFramesChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (TimelineViewRuler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewRuler::EndFramesChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TimelineViewRuler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewRuler::FramesChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (TimelineViewRuler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewRuler::StartZoomChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (TimelineViewRuler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewRuler::EndZoomChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (TimelineViewRuler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewRuler::ZoomChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (TimelineViewRuler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewRuler::OffsetFramesChanged)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject TimelineViewRuler::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimelineViewRuler.data,
      qt_meta_data_TimelineViewRuler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewRuler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewRuler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewRuler.stringdata))
        return static_cast<void*>(const_cast< TimelineViewRuler*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimelineViewRuler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TimelineViewRuler::StartFramesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TimelineViewRuler::EndFramesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TimelineViewRuler::FramesChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TimelineViewRuler::StartZoomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void TimelineViewRuler::EndZoomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void TimelineViewRuler::ZoomChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TimelineViewRuler::OffsetFramesChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
