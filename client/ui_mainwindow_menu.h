/********************************************************************************
** Form generated from reading UI file 'mainwindow_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_MENU_H
#define UI_MAINWINDOW_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_menu
{
public:
    QWidget *centralwidget;
    QWidget *Findwidget;
    QLineEdit *signEdit;
    QLabel *UsrName;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *closeLayout;
    QToolButton *Head1;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hLayout;
    QLineEdit *FindEdit;
    QTabWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_menu)
    {
        if (MainWindow_menu->objectName().isEmpty())
            MainWindow_menu->setObjectName(QStringLiteral("MainWindow_menu"));
        MainWindow_menu->setWindowModality(Qt::NonModal);
        MainWindow_menu->resize(280, 750);
        MainWindow_menu->setStyleSheet(QLatin1String("#MainWindow_menu{\n"
"	border-image: url(:/new/prefix2/Picture/talkDialogBackgroud2.jpg);\n"
"}"));
        centralwidget = new QWidget(MainWindow_menu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Findwidget = new QWidget(centralwidget);
        Findwidget->setObjectName(QStringLiteral("Findwidget"));
        Findwidget->setGeometry(QRect(0, 0, 281, 121));
        Findwidget->setStyleSheet(QStringLiteral("#Findwidget{border-image:url(:/new/prefix2/Picture/mainBackImg.jpg);}"));
        signEdit = new QLineEdit(Findwidget);
        signEdit->setObjectName(QStringLiteral("signEdit"));
        signEdit->setGeometry(QRect(90, 60, 151, 20));
        UsrName = new QLabel(Findwidget);
        UsrName->setObjectName(QStringLiteral("UsrName"));
        UsrName->setGeometry(QRect(90, 10, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\350\210\222\344\275\223"));
        font.setPointSize(16);
        UsrName->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(Findwidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(210, 0, 71, 31));
        closeLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        closeLayout->setObjectName(QStringLiteral("closeLayout"));
        closeLayout->setContentsMargins(0, 0, 0, 0);
        Head1 = new QToolButton(Findwidget);
        Head1->setObjectName(QStringLiteral("Head1"));
        Head1->setGeometry(QRect(10, 10, 71, 65));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 80, 281, 41));
        hLayout = new QHBoxLayout(horizontalLayoutWidget);
        hLayout->setObjectName(QStringLiteral("hLayout"));
        hLayout->setContentsMargins(0, 0, 0, 0);
        FindEdit = new QLineEdit(horizontalLayoutWidget);
        FindEdit->setObjectName(QStringLiteral("FindEdit"));
        QFont font1;
        font1.setItalic(true);
        FindEdit->setFont(font1);

        hLayout->addWidget(FindEdit);

        tableWidget = new QTabWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 120, 291, 591));
        tableWidget->setStyleSheet(QStringLiteral(""));
        MainWindow_menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_menu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 280, 23));
        MainWindow_menu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_menu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_menu->setStatusBar(statusbar);

        retranslateUi(MainWindow_menu);

        tableWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow_menu);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_menu)
    {
        MainWindow_menu->setWindowTitle(QApplication::translate("MainWindow_menu", "MainWindow", nullptr));
        signEdit->setText(QString());
        UsrName->setText(QApplication::translate("MainWindow_menu", "\346\210\221\347\232\204\345\220\215\345\255\227", nullptr));
        Head1->setText(QApplication::translate("MainWindow_menu", "...", nullptr));
        FindEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow_menu: public Ui_MainWindow_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_MENU_H
