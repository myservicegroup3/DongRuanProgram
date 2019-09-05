/****************************************************************************
** Meta object code from reading C++ file 'mainwindow_menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow_menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_menu_t {
    QByteArrayData data[11];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_menu_t qt_meta_stringdata_MainWindow_menu = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MainWindow_menu"
QT_MOC_LITERAL(1, 16, 13), // "onMinisizeBtn"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "onCloseBtn"
QT_MOC_LITERAL(4, 42, 21), // "on_FindButton_clicked"
QT_MOC_LITERAL(5, 64, 7), // "checked"
QT_MOC_LITERAL(6, 72, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(7, 96, 4), // "arg1"
QT_MOC_LITERAL(8, 101, 16), // "on_Head1_clicked"
QT_MOC_LITERAL(9, 118, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(10, 139, 25) // "on_FindEdit_returnPressed"

    },
    "MainWindow_menu\0onMinisizeBtn\0\0"
    "onCloseBtn\0on_FindButton_clicked\0"
    "checked\0on_lineEdit_textChanged\0arg1\0"
    "on_Head1_clicked\0on_addButton_clicked\0"
    "on_FindEdit_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow_menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow_menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow_menu *_t = static_cast<MainWindow_menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onMinisizeBtn(); break;
        case 1: _t->onCloseBtn(); break;
        case 2: _t->on_FindButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_Head1_clicked(); break;
        case 5: _t->on_addButton_clicked(); break;
        case 6: _t->on_FindEdit_returnPressed(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow_menu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow_menu.data,
      qt_meta_data_MainWindow_menu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow_menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow_menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow_menu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow_menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
