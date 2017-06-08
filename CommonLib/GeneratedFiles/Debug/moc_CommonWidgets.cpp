/****************************************************************************
** Meta object code from reading C++ file 'CommonWidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/inc_CommonLib/CommonWidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommonWidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BaseButton_t {
    QByteArrayData data[6];
    char stringdata[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseButton_t qt_meta_stringdata_BaseButton = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BaseButton"
QT_MOC_LITERAL(1, 11, 7), // "Clicked"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 2), // "id"
QT_MOC_LITERAL(4, 23, 1), // "p"
QT_MOC_LITERAL(5, 25, 7) // "clicked"

    },
    "BaseButton\0Clicked\0\0id\0p\0clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    3,    4,
    QMetaType::Void,

       0        // eod
};

void BaseButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaseButton *_t = static_cast<BaseButton *>(_o);
        switch (_id) {
        case 0: _t->Clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 1: _t->clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BaseButton::*_t)(int , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaseButton::Clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (BaseButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaseButton::clicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject BaseButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BaseButton.data,
      qt_meta_data_BaseButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaseButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaseButton.stringdata))
        return static_cast<void*>(const_cast< BaseButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int BaseButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void BaseButton::Clicked(int _t1, QPoint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaseButton::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_BaseStateButton_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseStateButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseStateButton_t qt_meta_stringdata_BaseStateButton = {
    {
QT_MOC_LITERAL(0, 0, 15) // "BaseStateButton"

    },
    "BaseStateButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseStateButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void BaseStateButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject BaseStateButton::staticMetaObject = {
    { &BaseButton::staticMetaObject, qt_meta_stringdata_BaseStateButton.data,
      qt_meta_data_BaseStateButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaseStateButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseStateButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaseStateButton.stringdata))
        return static_cast<void*>(const_cast< BaseStateButton*>(this));
    return BaseButton::qt_metacast(_clname);
}

int BaseStateButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ToolBarSlider_t {
    QByteArrayData data[10];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolBarSlider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolBarSlider_t qt_meta_stringdata_ToolBarSlider = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ToolBarSlider"
QT_MOC_LITERAL(1, 14, 12), // "valueChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "startValueChanged"
QT_MOC_LITERAL(4, 46, 15), // "endValueChanged"
QT_MOC_LITERAL(5, 62, 9), // "startDrag"
QT_MOC_LITERAL(6, 72, 7), // "endDrag"
QT_MOC_LITERAL(7, 80, 11), // "ResizeChunk"
QT_MOC_LITERAL(8, 92, 10), // "SetCanSeek"
QT_MOC_LITERAL(9, 103, 3) // "can"

    },
    "ToolBarSlider\0valueChanged\0\0"
    "startValueChanged\0endValueChanged\0"
    "startDrag\0endDrag\0ResizeChunk\0SetCanSeek\0"
    "can"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolBarSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    0,   52,    2, 0x06 /* Public */,
       4,    0,   53,    2, 0x06 /* Public */,
       5,    0,   54,    2, 0x06 /* Public */,
       6,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   56,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void ToolBarSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolBarSlider *_t = static_cast<ToolBarSlider *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->startValueChanged(); break;
        case 2: _t->endValueChanged(); break;
        case 3: _t->startDrag(); break;
        case 4: _t->endDrag(); break;
        case 5: _t->ResizeChunk(); break;
        case 6: _t->SetCanSeek((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ToolBarSlider::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBarSlider::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ToolBarSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBarSlider::startValueChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (ToolBarSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBarSlider::endValueChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (ToolBarSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBarSlider::startDrag)) {
                *result = 3;
            }
        }
        {
            typedef void (ToolBarSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBarSlider::endDrag)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject ToolBarSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ToolBarSlider.data,
      qt_meta_data_ToolBarSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ToolBarSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolBarSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ToolBarSlider.stringdata))
        return static_cast<void*>(const_cast< ToolBarSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int ToolBarSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ToolBarSlider::valueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ToolBarSlider::startValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ToolBarSlider::endValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ToolBarSlider::startDrag()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ToolBarSlider::endDrag()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
struct qt_meta_stringdata_ScaleUnitSlider_t {
    QByteArrayData data[6];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScaleUnitSlider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScaleUnitSlider_t qt_meta_stringdata_ScaleUnitSlider = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ScaleUnitSlider"
QT_MOC_LITERAL(1, 16, 12), // "valueChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "value"
QT_MOC_LITERAL(4, 36, 17), // "startValueChanged"
QT_MOC_LITERAL(5, 54, 15) // "endValueChanged"

    },
    "ScaleUnitSlider\0valueChanged\0\0value\0"
    "startValueChanged\0endValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScaleUnitSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    0,   32,    2, 0x06 /* Public */,
       5,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScaleUnitSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScaleUnitSlider *_t = static_cast<ScaleUnitSlider *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->startValueChanged(); break;
        case 2: _t->endValueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScaleUnitSlider::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScaleUnitSlider::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ScaleUnitSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScaleUnitSlider::startValueChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (ScaleUnitSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScaleUnitSlider::endValueChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ScaleUnitSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScaleUnitSlider.data,
      qt_meta_data_ScaleUnitSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScaleUnitSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScaleUnitSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScaleUnitSlider.stringdata))
        return static_cast<void*>(const_cast< ScaleUnitSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScaleUnitSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ScaleUnitSlider::valueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScaleUnitSlider::startValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ScaleUnitSlider::endValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
struct qt_meta_stringdata_MidSlider_t {
    QByteArrayData data[7];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MidSlider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MidSlider_t qt_meta_stringdata_MidSlider = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MidSlider"
QT_MOC_LITERAL(1, 10, 17), // "StartValueChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "value"
QT_MOC_LITERAL(4, 35, 12), // "ValueChanged"
QT_MOC_LITERAL(5, 48, 15), // "EndValueChanged"
QT_MOC_LITERAL(6, 64, 11) // "ResizeChunk"

    },
    "MidSlider\0StartValueChanged\0\0value\0"
    "ValueChanged\0EndValueChanged\0ResizeChunk"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MidSlider[] = {

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
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MidSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MidSlider *_t = static_cast<MidSlider *>(_o);
        switch (_id) {
        case 0: _t->StartValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->EndValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ResizeChunk(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MidSlider::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MidSlider::StartValueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MidSlider::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MidSlider::ValueChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MidSlider::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MidSlider::EndValueChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MidSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MidSlider.data,
      qt_meta_data_MidSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MidSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MidSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MidSlider.stringdata))
        return static_cast<void*>(const_cast< MidSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int MidSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MidSlider::StartValueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MidSlider::ValueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MidSlider::EndValueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_PureSlider_t {
    QByteArrayData data[4];
    char stringdata[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PureSlider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PureSlider_t qt_meta_stringdata_PureSlider = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PureSlider"
QT_MOC_LITERAL(1, 11, 15), // "sigValueChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1) // "v"

    },
    "PureSlider\0sigValueChanged\0\0v"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PureSlider[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void PureSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PureSlider *_t = static_cast<PureSlider *>(_o);
        switch (_id) {
        case 0: _t->sigValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PureSlider::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PureSlider::sigValueChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PureSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PureSlider.data,
      qt_meta_data_PureSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PureSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PureSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PureSlider.stringdata))
        return static_cast<void*>(const_cast< PureSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int PureSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PureSlider::sigValueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_SetColorParamWidget_t {
    QByteArrayData data[4];
    char stringdata[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetColorParamWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetColorParamWidget_t qt_meta_stringdata_SetColorParamWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SetColorParamWidget"
QT_MOC_LITERAL(1, 20, 15), // "sigValueChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 1) // "v"

    },
    "SetColorParamWidget\0sigValueChanged\0"
    "\0v"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetColorParamWidget[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void SetColorParamWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetColorParamWidget *_t = static_cast<SetColorParamWidget *>(_o);
        switch (_id) {
        case 0: _t->sigValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SetColorParamWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetColorParamWidget::sigValueChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SetColorParamWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SetColorParamWidget.data,
      qt_meta_data_SetColorParamWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SetColorParamWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetColorParamWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SetColorParamWidget.stringdata))
        return static_cast<void*>(const_cast< SetColorParamWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SetColorParamWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SetColorParamWidget::sigValueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MagicLabel_t {
    QByteArrayData data[1];
    char stringdata[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MagicLabel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MagicLabel_t qt_meta_stringdata_MagicLabel = {
    {
QT_MOC_LITERAL(0, 0, 10) // "MagicLabel"

    },
    "MagicLabel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MagicLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MagicLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MagicLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MagicLabel.data,
      qt_meta_data_MagicLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MagicLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MagicLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MagicLabel.stringdata))
        return static_cast<void*>(const_cast< MagicLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int MagicLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
