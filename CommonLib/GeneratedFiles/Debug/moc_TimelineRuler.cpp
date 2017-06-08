/****************************************************************************
** Meta object code from reading C++ file 'TimelineRuler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/inc_CommonLib/TimelineRuler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimelineRuler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimelineRuler_t {
    QByteArrayData data[11];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineRuler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineRuler_t qt_meta_stringdata_TimelineRuler = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TimelineRuler"
QT_MOC_LITERAL(1, 14, 18), // "StartFramesChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "EndFramesChanged"
QT_MOC_LITERAL(4, 51, 13), // "FramesChanged"
QT_MOC_LITERAL(5, 65, 6), // "frames"
QT_MOC_LITERAL(6, 72, 16), // "StartZoomChanged"
QT_MOC_LITERAL(7, 89, 14), // "EndZoomChanged"
QT_MOC_LITERAL(8, 104, 11), // "ZoomChanged"
QT_MOC_LITERAL(9, 116, 4), // "zoom"
QT_MOC_LITERAL(10, 121, 19) // "OffsetFramesChanged"

    },
    "TimelineRuler\0StartFramesChanged\0\0"
    "EndFramesChanged\0FramesChanged\0frames\0"
    "StartZoomChanged\0EndZoomChanged\0"
    "ZoomChanged\0zoom\0OffsetFramesChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineRuler[] = {

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
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void TimelineRuler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineRuler *_t = static_cast<TimelineRuler *>(_o);
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
            typedef void (TimelineRuler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineRuler::StartFramesChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (TimelineRuler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineRuler::EndFramesChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TimelineRuler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineRuler::FramesChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (TimelineRuler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineRuler::StartZoomChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (TimelineRuler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineRuler::EndZoomChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (TimelineRuler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineRuler::ZoomChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (TimelineRuler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineRuler::OffsetFramesChanged)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject TimelineRuler::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimelineRuler.data,
      qt_meta_data_TimelineRuler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineRuler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineRuler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineRuler.stringdata))
        return static_cast<void*>(const_cast< TimelineRuler*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimelineRuler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TimelineRuler::StartFramesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TimelineRuler::EndFramesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TimelineRuler::FramesChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TimelineRuler::StartZoomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void TimelineRuler::EndZoomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void TimelineRuler::ZoomChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TimelineRuler::OffsetFramesChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
