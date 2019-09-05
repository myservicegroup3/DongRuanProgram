/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 429);
        Dialog->setStyleSheet(QStringLiteral(""));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 240, 201, 31));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(110,164,208), stop:0.3 rgb(110,152,230), stop:1 rgb(110,140,220));\n"
"            border:1px;\n"
"            border-radius:5px; \n"
"            padding:2px 4px;  \n"
"}"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 240, 71, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 290, 71, 21));
        label_2->setFont(font);
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 290, 201, 31));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(110,164,208), stop:0.3 rgb(110,152,230), stop:1 rgb(110,140,220));\n"
"            border:1px;\n"
"            border-radius:5px; \n"
"            padding:2px 4px;  \n"
"}"));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 360, 75, 23));
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
"        }"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 360, 75, 23));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton:hover{\n"
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
"        }"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-20, 0, 431, 161));
        widget->setStyleSheet(QStringLiteral("#widget{border-image:url(:/new/prefix1/Picture/sea.jpg);}"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 170, 271, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Simplex_IV50"));
        font1.setPointSize(22);
        label_3->setFont(font1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Welcome!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
