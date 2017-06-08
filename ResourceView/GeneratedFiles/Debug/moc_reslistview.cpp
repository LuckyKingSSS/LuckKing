/****************************************************************************
** Meta object code from reading C++ file 'reslistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../controls/reslistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reslistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ResListView_t {
    QByteArrayData data[11];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResListView_t qt_meta_stringdata_ResListView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ResListView"
QT_MOC_LITERAL(1, 12, 24), // "signalLeftBtnDoubleClick"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 55, 10), // "selectItem"
QT_MOC_LITERAL(5, 66, 9), // "playMovie"
QT_MOC_LITERAL(6, 76, 12), // "strMoviePath"
QT_MOC_LITERAL(7, 89, 12), // "signalUnload"
QT_MOC_LITERAL(8, 102, 10), // "addResInfo"
QT_MOC_LITERAL(9, 113, 13), // "mediaInfoList"
QT_MOC_LITERAL(10, 127, 13) // "deleteResInfo"

    },
    "ResListView\0signalLeftBtnDoubleClick\0"
    "\0QListWidgetItem*\0selectItem\0playMovie\0"
    "strMoviePath\0signalUnload\0addResInfo\0"
    "mediaInfoList\0deleteResInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       7,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   46,    2, 0x0a /* Public */,
      10,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void,

       0        // eod
};

void ResListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResListView *_t = static_cast<ResListView *>(_o);
        switch (_id) {
        case 0: _t->signalLeftBtnDoubleClick((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->playMovie((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalUnload(); break;
        case 3: _t->addResInfo((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->deleteResInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ResListView::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalLeftBtnDoubleClick)) {
                *result = 0;
            }
        }
        {
            typedef void (ResListView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::playMovie)) {
                *result = 1;
            }
        }
        {
            typedef void (ResListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalUnload)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ResListView::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ResListView.data,
      qt_meta_data_ResListView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ResListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResListView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ResListView.stringdata))
        return static_cast<void*>(const_cast< ResListView*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ResListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
void ResListView::signalLeftBtnDoubleClick(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ResListView::playMovie(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ResListView::signalUnload()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
