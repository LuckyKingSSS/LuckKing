/****************************************************************************
** Meta object code from reading C++ file 'resourcetool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../resourcetool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resourcetool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ResourceTool_t {
    QByteArrayData data[9];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResourceTool_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResourceTool_t qt_meta_stringdata_ResourceTool = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ResourceTool"
QT_MOC_LITERAL(1, 13, 21), // "signalImportMediaInfo"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 12), // "mediaStrInfo"
QT_MOC_LITERAL(4, 49, 22), // "signalRemoveBtnClicked"
QT_MOC_LITERAL(5, 72, 21), // "signalEnableRemoveBtn"
QT_MOC_LITERAL(6, 94, 20), // "slotImportBtnClicked"
QT_MOC_LITERAL(7, 115, 20), // "slotRemoveBtnClicked"
QT_MOC_LITERAL(8, 136, 19) // "slotEnableRemoveBtn"

    },
    "ResourceTool\0signalImportMediaInfo\0\0"
    "mediaStrInfo\0signalRemoveBtnClicked\0"
    "signalEnableRemoveBtn\0slotImportBtnClicked\0"
    "slotRemoveBtnClicked\0slotEnableRemoveBtn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResourceTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResourceTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResourceTool *_t = static_cast<ResourceTool *>(_o);
        switch (_id) {
        case 0: _t->signalImportMediaInfo((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->signalRemoveBtnClicked(); break;
        case 2: _t->signalEnableRemoveBtn(); break;
        case 3: _t->slotImportBtnClicked(); break;
        case 4: _t->slotRemoveBtnClicked(); break;
        case 5: _t->slotEnableRemoveBtn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ResourceTool::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResourceTool::signalImportMediaInfo)) {
                *result = 0;
            }
        }
        {
            typedef void (ResourceTool::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResourceTool::signalRemoveBtnClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (ResourceTool::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResourceTool::signalEnableRemoveBtn)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ResourceTool::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ResourceTool.data,
      qt_meta_data_ResourceTool,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ResourceTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResourceTool::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ResourceTool.stringdata))
        return static_cast<void*>(const_cast< ResourceTool*>(this));
    return QWidget::qt_metacast(_clname);
}

int ResourceTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ResourceTool::signalImportMediaInfo(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ResourceTool::signalRemoveBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ResourceTool::signalEnableRemoveBtn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
