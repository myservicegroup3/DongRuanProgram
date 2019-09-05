/********************************************************************************
** Form generated from reading UI file 'creategroup.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUP_H
#define UI_CREATEGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_creategroup
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *createButton;
    QPushButton *pushButton_3;
    QWidget *widget;

    void setupUi(QDialog *creategroup)
    {
        if (creategroup->objectName().isEmpty())
            creategroup->setObjectName(QStringLiteral("creategroup"));
        creategroup->resize(400, 300);
        pushButton = new QPushButton(creategroup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 160, 75, 23));
        pushButton->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"			color: rgb(255, 255, 255); \n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(130,120,226), stop:0.3 rgb(120,130,230), stop:1 rgb(125,140,226));\n"
"            border:1px;  \n"
"            border-radius:5px; \n"
"            padding:2px 4px;\n"
"}\n"
"QPushButton{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\n"
"            border:1px;\n"
"            border-radius:5px; \n"
"            padding:2px 4px;  \n"
"}\n"
"QPushButton:pressed{    \n"
"            color: rgb(255, 255, 255); \n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(240,156,121), stop:0.3 rgb(220,160,140), stop:1 rgb(230,140,120));  \n"
"            border:1px;  \n"
"            border-radius:5px;\n"
"            padding:2px 4px; \n"
"        }\n"
""));
        textEdit_2 = new QTextEdit(creategroup);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(23, 190, 231, 81));
        label = new QLabel(creategroup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 161, 16));
        textBrowser = new QTextBrowser(creategroup);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 40, 231, 111));
        createButton = new QPushButton(creategroup);
        createButton->setObjectName(QStringLiteral("createButton"));
        createButton->setGeometry(QRect(290, 180, 75, 23));
        createButton->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"			color: rgb(255, 255, 255); \n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(130,120,226), stop:0.3 rgb(120,130,230), stop:1 rgb(125,140,226));\n"
"            border:1px;  \n"
"            border-radius:5px; \n"
"            padding:2px 4px;\n"
"}\n"
"QPushButton{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\n"
"            border:1px;\n"
"            border-radius:5px; \n"
"            padding:2px 4px;  \n"
"}\n"
"QPushButton:pressed{    \n"
"            color: rgb(255, 255, 255); \n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(240,156,121), stop:0.3 rgb(220,160,140), stop:1 rgb(230,140,120));  \n"
"            border:1px;  \n"
"            border-radius:5px;\n"
"            padding:2px 4px; \n"
"        }\n"
""));
        pushButton_3 = new QPushButton(creategroup);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 220, 75, 23));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"			color: rgb(255, 255, 255); \n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(130,120,226), stop:0.3 rgb(120,130,230), stop:1 rgb(125,140,226));\n"
"            border:1px;  \n"
"            border-radius:5px; \n"
"            padding:2px 4px;\n"
"}\n"
"QPushButton{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\n"
"            border:1px;\n"
"            border-radius:5px; \n"
"            padding:2px 4px;  \n"
"}\n"
"QPushButton:pressed{    \n"
"            color: rgb(255, 255, 255); \n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(240,156,121), stop:0.3 rgb(220,160,140), stop:1 rgb(230,140,120));  \n"
"            border:1px;  \n"
"            border-radius:5px;\n"
"            padding:2px 4px; \n"
"        }\n"
""));
        widget = new QWidget(creategroup);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 401, 301));
        widget->setStyleSheet(QStringLiteral("#widget{border-image:url(:/new/prefix2/Picture/talkDialogBackgroud2.jpg);}"));
        widget->raise();
        pushButton->raise();
        textEdit_2->raise();
        label->raise();
        textBrowser->raise();
        createButton->raise();
        pushButton_3->raise();

        retranslateUi(creategroup);

        QMetaObject::connectSlotsByName(creategroup);
    } // setupUi

    void retranslateUi(QDialog *creategroup)
    {
        creategroup->setWindowTitle(QApplication::translate("creategroup", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("creategroup", "\346\267\273\345\212\240", nullptr));
        label->setText(QApplication::translate("creategroup", "\350\257\267\351\200\211\346\213\251\345\212\240\345\205\245\347\276\244\350\201\212\347\232\204\345\245\275\345\217\213\357\274\232", nullptr));
        createButton->setText(QApplication::translate("creategroup", "\345\210\233\345\273\272", nullptr));
        pushButton_3->setText(QApplication::translate("creategroup", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class creategroup: public Ui_creategroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUP_H
