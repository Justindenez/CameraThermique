/****************************************************************************
** Meta object code from reading C++ file 'LeptonThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LeptonThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LeptonThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LeptonThread_t {
    QByteArrayData data[10];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LeptonThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LeptonThread_t qt_meta_stringdata_LeptonThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LeptonThread"
QT_MOC_LITERAL(1, 13, 13), // "updateTextMax"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "updateTextMin"
QT_MOC_LITERAL(4, 42, 11), // "updateImage"
QT_MOC_LITERAL(5, 54, 14), // "updateImageRaw"
QT_MOC_LITERAL(6, 69, 7), // "Capture"
QT_MOC_LITERAL(7, 77, 3), // "num"
QT_MOC_LITERAL(8, 81, 10), // "performFFC"
QT_MOC_LITERAL(9, 92, 8) // "setAlpha"

    },
    "LeptonThread\0updateTextMax\0\0updateTextMin\0"
    "updateImage\0updateImageRaw\0Capture\0"
    "num\0performFFC\0setAlpha"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeptonThread[] = {

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
       3,    1,   52,    2, 0x06 /* Public */,
       4,    1,   55,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   62,    2, 0x0a /* Public */,
       9,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void LeptonThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LeptonThread *_t = static_cast<LeptonThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTextMax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateTextMin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->updateImageRaw(); break;
        case 4: _t->Capture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->performFFC(); break;
        case 6: _t->setAlpha((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LeptonThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LeptonThread::updateTextMax)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LeptonThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LeptonThread::updateTextMin)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LeptonThread::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LeptonThread::updateImage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LeptonThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LeptonThread::updateImageRaw)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LeptonThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LeptonThread::Capture)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LeptonThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_LeptonThread.data,
      qt_meta_data_LeptonThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LeptonThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LeptonThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LeptonThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int LeptonThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void LeptonThread::updateTextMax(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LeptonThread::updateTextMin(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LeptonThread::updateImage(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LeptonThread::updateImageRaw()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LeptonThread::Capture(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
