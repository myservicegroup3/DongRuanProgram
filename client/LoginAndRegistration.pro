#-------------------------------------------------
#
# Project created by QtCreator 2018-04-19T09:17:44
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginAndRegistration
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    fileoperator.cpp \
    user.cpp \
    mainwindow_menu.cpp \
    listwidget.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    fileoperator.h \
    user.h \
    mainwindow_menu.h \
    listwidget.h \
    database.h

FORMS    += mainwindow.ui \
    dialog.ui \
    mainwindow_menu.ui

RESOURCES += \
    ziyuan.qrc
