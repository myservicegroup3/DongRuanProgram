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
    QWidget *Findwidget;
    QLineEdit *signEdit;
    QLabel *UsrName;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *closeLayout;
    QToolButton *Head1;
    QToolButton *addButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hLayout;
    QLineEdit *FindEdit;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayout;
    QWidget *page_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *vLayout2;
    QToolButton *addButton_2;
    QLineEdit *addEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_menu)
    {
        if (MainWindow_menu->objectName().isEmpty())
            MainWindow_menu->setObjectName(QStringLiteral("MainWindow_menu"));
        MainWindow_menu->setWindowModality(Qt::NonModal);
        MainWindow_menu->resize(280, 680);
        MainWindow_menu->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow_menu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Findwidget = new QWidget(centralwidget);
        Findwidget->setObjectName(QStringLiteral("Findwidget"));
        Findwidget->setGeometry(QRect(0, 0, 281, 121));
        Findwidget->setStyleSheet(QStringLiteral("#Findwidget{border-image:url(:/new/prefix1/Picture/sea3.jpg);}"));
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
        addButton = new QToolButton(Findwidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(250, 60, 21, 20));
        addButton->setStyleSheet(QStringLiteral("#addButton{border-image:url(:/new/prefix1/Picture/groupChatIcon.png);}"));
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

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(0, 120, 281, 431));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221"));
        toolBox->setFont(font2);
        toolBox->setStyleSheet(QLatin1String("QToolBox::tab:hover{\n"
"			color: rgb(255, 255, 255); \n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(130,120,226), stop:0.3 rgb(120,130,230), stop:1 rgb(125,140,226));\n"
"            border:1px;  \n"
"            border-radius:5px; \n"
"            padding:2px 4px;\n"
"}\n"
"QToolBox::tab{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\n"
"            border:1px;\n"
"            border-radius:5px; \n"
"            padding:2px 4px;  \n"
"}\n"
"QToolBox::tab:pressed{    \n"
"            color: rgb(255, 255, 255); \n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(240,156,121), stop:0.3 rgb(220,160,140), stop:1 rgb(230,140,120));  \n"
"            border:1px;  \n"
"            border-radius:5px;\n"
"            padding:2px 4px; \n"
"        }\n"
""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 281, 377));
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, -1, 281, 481));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, -1, 261, 381));
        vLayout = new QVBoxLayout(verticalLayoutWidget);
        vLayout->setObjectName(QStringLiteral("vLayout"));
        vLayout->setContentsMargins(0, 0, 0, 0);
        toolBox->addItem(page, QString::fromUtf8("\345\245\275\345\217\213\345\210\227\350\241\250"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 281, 377));
        verticalLayoutWidget_2 = new QWidget(page_2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, -10, 281, 441));
        vLayout2 = new QVBoxLayout(verticalLayoutWidget_2);
        vLayout2->setObjectName(QStringLiteral("vLayout2"));
        vLayout2->setContentsMargins(0, 0, 0, 0);
        toolBox->addItem(page_2, QString::fromUtf8("\347\276\244\350\201\212"));
        addButton_2 = new QToolButton(centralwidget);
        addButton_2->setObjectName(QStringLiteral("addButton_2"));
        addButton_2->setGeometry(QRect(240, 620, 41, 31));
        addButton_2->setStyleSheet(QStringLiteral("#addButton_2{border-image:url(:/new/prefix1/Picture/search.png);}"));
        addEdit = new QLineEdit(centralwidget);
        addEdit->setObjectName(QStringLiteral("addEdit"));
        addEdit->setGeometry(QRect(2, 619, 231, 31));
        addEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-style:ooutset;\n"
"border-radius:10px;\n"
"padding:6px;\n"
"background-color: rgb(255, 255, 127);\n"
"		 \n"
"}"));
        MainWindow_menu->setCentralWidget(centralwidget);
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
        signEdit->setText(QString());
        UsrName->setText(QApplication::translate("MainWindow_menu", "\346\210\221\347\232\204\345\220\215\345\255\227", nullptr));
        Head1->setText(QApplication::translate("MainWindow_menu", "...", nullptr));
        addButton->setText(QApplication::translate("MainWindow_menu", "...", nullptr));
        FindEdit->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow_menu", "\345\245\275\345\217\213\345\210\227\350\241\250", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow_menu", "\347\276\244\350\201\212", nullptr));
        addButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow_menu: public Ui_MainWindow_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_MENU_H
