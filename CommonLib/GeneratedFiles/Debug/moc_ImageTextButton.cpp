/****************************************************************************
** Meta object code from reading C++ file 'ImageTextButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/inc_CommonLib/ImageTextButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageTextButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageTextButton_t {
    QByteArrayData data[5];
    char stringdata[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageTextButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageTextButton_t qt_meta_stringdata_ImageTextButton = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ImageTextButton"
QT_MOC_LITERAL(1, 16, 7), // "Clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 2), // "id"
QT_MOC_LITERAL(4, 28, 1) // "p"

    },
    "ImageTextButton\0Clicked\0\0id\0p"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageTextButton[] = {

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
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    3,    4,

       0        // eod
};

void ImageTextButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageTextButton *_t = static_cast<ImageTextButton *>(_o);
        switch (_id) {
        case 0: _t->Clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageTextButton::*_t)(int , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageTextButton::Clicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ImageTextButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageTextButton.data,
      qt_meta_data_ImageTextButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageTextButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageTextButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageTextButton.stringdata))
        return static_cast<void*>(const_cast< ImageTextButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageTextButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ImageTextButton::Clicked(int _t1, QPoint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ImageTextButton2_t {
    QByteArrayData data[8];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageTextButton2_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageTextButton2_t qt_meta_stringdata_ImageTextButton2 = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ImageTextButton2"
QT_MOC_LITERAL(1, 17, 11), // "sigSelected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2), // "id"
QT_MOC_LITERAL(4, 33, 11), // "normalImage"
QT_MOC_LITERAL(5, 45, 13), // "selectedImage"
QT_MOC_LITERAL(6, 59, 15), // "normalTextColor"
QT_MOC_LITERAL(7, 75, 17) // "selectedTextColor"

    },
    "ImageTextButton2\0sigSelected\0\0id\0"
    "normalImage\0selectedImage\0normalTextColor\0"
    "selectedTextColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageTextButton2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       4,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // properties: name, type, flags
       4, QMetaType::QPixmap, 0x00095003,
       5, QMetaType::QPixmap, 0x00095003,
       6, QMetaType::QColor, 0x00095003,
       7, QMetaType::QColor, 0x00095003,

       0        // eod
};

void ImageTextButton2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageTextButton2 *_t = static_cast<ImageTextButton2 *>(_o);
        switch (_id) {
        case 0: _t->sigSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageTextButton2::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageTextButton2::sigSelected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ImageTextButton2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageTextButton2.data,
      qt_meta_data_ImageTextButton2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageTextButton2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageTextButton2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageTextButton2.stringdata))
        return static_cast<void*>(const_cast< ImageTextButton2*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageTextButton2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPixmap*>(_v) = GetNormalImage(); break;
        case 1: *reinterpret_cast< QPixmap*>(_v) = GetSelectedImage(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = GetNormalTextColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = GetSelectedTextColor(); break;
        default: break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: SetNormalImage(*reinterpret_cast< QPixmap*>(_v)); break;
        case 1: SetSelectedImage(*reinterpret_cast< QPixmap*>(_v)); break;
        case 2: SetNormalTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: SetSelectedTextColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ImageTextButton2::sigSelected(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
