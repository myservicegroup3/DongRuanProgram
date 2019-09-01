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
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_menu
{
public:
    QWidget *centralwidget;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *FWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayout;
    QWidget *page_2;
    QWidget *Findwidget;
    QLineEdit *signEdit;
    QLabel *UsrName;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hLayout;
    QLineEdit *FindEdit;
    QPushButton *FindButton;
    QToolButton *Head1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_menu)
    {
        if (MainWindow_menu->objectName().isEmpty())
            MainWindow_menu->setObjectName(QStringLiteral("MainWindow_menu"));
        MainWindow_menu->setWindowModality(Qt::NonModal);
        MainWindow_menu->resize(280, 750);
        MainWindow_menu->setStyleSheet(QLatin1String("QMainWindow{\n"
"	background-color: rgb(255, 255, 127);\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"}"));
        centralwidget = new QWidget(MainWindow_menu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(0, 120, 281, 561));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 281, 509));
        FWidget = new QWidget(page);
        FWidget->setObjectName(QStringLiteral("FWidget"));
        FWidget->setGeometry(QRect(-1, -1, 281, 511));
        verticalLayoutWidget = new QWidget(FWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 261, 511));
        vLayout = new QVBoxLayout(verticalLayoutWidget);
        vLayout->setObjectName(QStringLiteral("vLayout"));
        vLayout->setContentsMargins(0, 0, 0, 0);
        toolBox->addItem(page, QString::fromUtf8("\345\245\275\345\217\213\345\210\227\350\241\250"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 281, 509));
        toolBox->addItem(page_2, QString::fromUtf8("\347\276\244\347\273\204"));
        Findwidget = new QWidget(centralwidget);
        Findwidget->setObjectName(QStringLiteral("Findwidget"));
        Findwidget->setGeometry(QRect(0, 0, 281, 121));
        signEdit = new QLineEdit(Findwidget);
        signEdit->setObjectName(QStringLiteral("signEdit"));
        signEdit->setGeometry(QRect(100, 40, 151, 20));
        UsrName = new QLabel(Findwidget);
        UsrName->setObjectName(QStringLiteral("UsrName"));
        UsrName->setGeometry(QRect(100, 0, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\350\210\222\344\275\223"));
        font.setPointSize(16);
        UsrName->setFont(font);
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

        FindButton = new QPushButton(horizontalLayoutWidget);
        FindButton->setObjectName(QStringLiteral("FindButton"));

        hLayout->addWidget(FindButton);

        Head1 = new QToolButton(centralwidget);
        Head1->setObjectName(QStringLiteral("Head1"));
        Head1->setGeometry(QRect(0, 0, 71, 65));
        MainWindow_menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_menu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 280, 23));
        MainWindow_menu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_menu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_menu->setStatusBar(statusbar);

        retranslateUi(MainWindow_menu);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow_menu);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_menu)
    {
        MainWindow_menu->setWindowTitle(QApplication::translate("MainWindow_menu", "MainWindow", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow_menu", "\345\245\275\345\217\213\345\210\227\350\241\250", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow_menu", "\347\276\244\347\273\204", nullptr));
        signEdit->setText(QString());
        UsrName->setText(QApplication::translate("MainWindow_menu", "\346\210\221\347\232\204ID", nullptr));
        FindEdit->setText(QString());
        FindButton->setText(QApplication::translate("MainWindow_menu", "\346\220\234\347\264\242", nullptr));
        Head1->setText(QApplication::translate("MainWindow_menu", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_menu: public Ui_MainWindow_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_MENU_H
