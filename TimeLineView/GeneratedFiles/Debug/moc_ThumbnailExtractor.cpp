/****************************************************************************
** Meta object code from reading C++ file 'ThumbnailExtractor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../TimelineManager/ThumbnailExtractor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThumbnailExtractor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThumbnailExtractor_t {
    QByteArrayData data[3];
    char stringdata[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThumbnailExtractor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThumbnailExtractor_t qt_meta_stringdata_ThumbnailExtractor = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ThumbnailExtractor"
QT_MOC_LITERAL(1, 19, 24), // "signalGetNeededThumbnail"
QT_MOC_LITERAL(2, 44, 0) // ""

    },
    "ThumbnailExtractor\0signalGetNeededThumbnail\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThumbnailExtractor[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void ThumbnailExtractor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThumbnailExtractor *_t = static_cast<ThumbnailExtractor *>(_o);
        switch (_id) {
        case 0: _t->signalGetNeededThumbnail(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThumbnailExtractor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThumbnailExtractor::signalGetNeededThumbnail)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ThumbnailExtractor::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThumbnailExtractor.data,
      qt_meta_data_ThumbnailExtractor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ThumbnailExtractor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThumbnailExtractor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ThumbnailExtractor.stringdata))
        return static_cast<void*>(const_cast< ThumbnailExtractor*>(this));
    return QThread::qt_metacast(_clname);
}

int ThumbnailExtractor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void ThumbnailExtractor::signalGetNeededThumbnail()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
