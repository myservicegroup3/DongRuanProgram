/********************************************************************************
** Form generated from reading UI file 'mytcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTCPCLIENT_H
#define UI_MYTCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTcpClient
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyTcpClient)
    {
        if (MyTcpClient->objectName().isEmpty())
            MyTcpClient->setObjectName(QStringLiteral("MyTcpClient"));
        MyTcpClient->resize(800, 600);
        menubar = new QMenuBar(MyTcpClient);
        menubar->setObjectName(QStringLiteral("menubar"));
        MyTcpClient->setMenuBar(menubar);
        centralwidget = new QWidget(MyTcpClient);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MyTcpClient->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MyTcpClient);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MyTcpClient->setStatusBar(statusbar);

        retranslateUi(MyTcpClient);

        QMetaObject::connectSlotsByName(MyTcpClient);
    } // setupUi

    void retranslateUi(QMainWindow *MyTcpClient)
    {
        MyTcpClient->setWindowTitle(QApplication::translate("MyTcpClient", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTcpClient: public Ui_MyTcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTCPCLIENT_H
