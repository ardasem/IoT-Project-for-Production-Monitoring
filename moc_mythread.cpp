/****************************************************************************
** Meta object code from reading C++ file 'mythread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mythread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mythread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyButtonThread_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyButtonThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyButtonThread_t qt_meta_stringdata_MyButtonThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MyButtonThread"
QT_MOC_LITERAL(1, 15, 5), // "gsign"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "rsign"
QT_MOC_LITERAL(4, 28, 5), // "ysign"
QT_MOC_LITERAL(5, 34, 6), // "rdsign"
QT_MOC_LITERAL(6, 41, 6), // "rusign"
QT_MOC_LITERAL(7, 48, 6), // "resign"
QT_MOC_LITERAL(8, 55, 19), // "infiniteloopChanger"
QT_MOC_LITERAL(9, 75, 16), // "pageIndexChanger"
QT_MOC_LITERAL(10, 92, 9) // "pageIndex"

    },
    "MyButtonThread\0gsign\0\0rsign\0ysign\0"
    "rdsign\0rusign\0resign\0infiniteloopChanger\0"
    "pageIndexChanger\0pageIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyButtonThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   60,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,   10,

       0        // eod
};

void MyButtonThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyButtonThread *_t = static_cast<MyButtonThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gsign(); break;
        case 1: _t->rsign(); break;
        case 2: _t->ysign(); break;
        case 3: _t->rdsign(); break;
        case 4: _t->rusign(); break;
        case 5: _t->resign(); break;
        case 6: _t->infiniteloopChanger(); break;
        case 7: _t->pageIndexChanger((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyButtonThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyButtonThread::gsign)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyButtonThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyButtonThread::rsign)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyButtonThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyButtonThread::ysign)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyButtonThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyButtonThread::rdsign)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyButtonThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyButtonThread::rusign)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyButtonThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyButtonThread::resign)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyButtonThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyButtonThread.data,
      qt_meta_data_MyButtonThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyButtonThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyButtonThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyButtonThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MyButtonThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MyButtonThread::gsign()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyButtonThread::rsign()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyButtonThread::ysign()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyButtonThread::rdsign()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyButtonThread::rusign()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MyButtonThread::resign()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
