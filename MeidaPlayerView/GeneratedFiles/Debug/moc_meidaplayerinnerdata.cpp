/****************************************************************************
** Meta object code from reading C++ file 'meidaplayerinnerdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../meidaplayerinnerdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'meidaplayerinnerdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MeidaPlayerInnerData_t {
    QByteArrayData data[8];
    char stringdata[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeidaPlayerInnerData_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeidaPlayerInnerData_t qt_meta_stringdata_MeidaPlayerInnerData = {
    {
QT_MOC_LITERAL(0, 0, 20), // "MeidaPlayerInnerData"
QT_MOC_LITERAL(1, 21, 23), // "signalSliderValueChange"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 9), // "iNewValue"
QT_MOC_LITERAL(4, 56, 20), // "sigalDurationChanged"
QT_MOC_LITERAL(5, 77, 21), // "sigalSyncRulerHandler"
QT_MOC_LITERAL(6, 99, 15), // "slotSeekToFrame"
QT_MOC_LITERAL(7, 115, 6) // "iFrame"

    },
    "MeidaPlayerInnerData\0signalSliderValueChange\0"
    "\0iNewValue\0sigalDurationChanged\0"
    "sigalSyncRulerHandler\0slotSeekToFrame\0"
    "iFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeidaPlayerInnerData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void MeidaPlayerInnerData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeidaPlayerInnerData *_t = static_cast<MeidaPlayerInnerData *>(_o);
        switch (_id) {
        case 0: _t->signalSliderValueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigalDurationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigalSyncRulerHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slotSeekToFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MeidaPlayerInnerData::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeidaPlayerInnerData::signalSliderValueChange)) {
                *result = 0;
            }
        }
        {
            typedef void (MeidaPlayerInnerData::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeidaPlayerInnerData::sigalDurationChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MeidaPlayerInnerData::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MeidaPlayerInnerData::sigalSyncRulerHandler)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MeidaPlayerInnerData::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MeidaPlayerInnerData.data,
      qt_meta_data_MeidaPlayerInnerData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeidaPlayerInnerData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeidaPlayerInnerData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeidaPlayerInnerData.stringdata))
        return static_cast<void*>(const_cast< MeidaPlayerInnerData*>(this));
    return QWidget::qt_metacast(_clname);
}

int MeidaPlayerInnerData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MeidaPlayerInnerData::signalSliderValueChange(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MeidaPlayerInnerData::sigalDurationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MeidaPlayerInnerData::sigalSyncRulerHandler(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE