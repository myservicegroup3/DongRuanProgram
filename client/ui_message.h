/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_H
#define UI_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Message
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hLayout;
    QWidget *widget_2;
    QWidget *widget;
    QToolButton *Head;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *nameEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *IDEdit;

    void setupUi(QWidget *Message)
    {
        if (Message->objectName().isEmpty())
            Message->setObjectName(QStringLiteral("Message"));
        Message->resize(368, 392);
        Message->setStyleSheet(QStringLiteral("#Message{border-image:url(:/new/prefix1/Picture/sea3.jpg);}"));
        horizontalLayoutWidget = new QWidget(Message);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(289, 0, 81, 31));
        hLayout = new QHBoxLayout(horizontalLayoutWidget);
        hLayout->setObjectName(QStringLiteral("hLayout"));
        hLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(Message);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(-11, 0, 381, 401));
        widget_2->setStyleSheet(QStringLiteral("#widget_2{border-image:url(:/new/prefix1/Picture/sea3.jpg);}"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 40, 321, 321));
        Head = new QToolButton(widget);
        Head->setObjectName(QStringLiteral("Head"));
        Head->setGeometry(QRect(20, 10, 80, 80));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(169, -11, 141, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameEdit = new QLineEdit(verticalLayoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setStyleSheet(QLatin1String("#nameEdit{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));\n"
"            border:1px;\n"
"            border-radius:20px; \n"
"            padding:2px 4px;  \n"
"}"));

        verticalLayout->addWidget(nameEdit);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 100, 139, 31));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 10, 71, 21));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(103, 109, 61, 21));
        verticalLayoutWidget_2 = new QWidget(widget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(170, 60, 141, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        IDEdit = new QLineEdit(verticalLayoutWidget_2);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));
        IDEdit->setStyleSheet(QLatin1String("#IDEdit{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));\n"
"            border:1px;\n"
"            border-radius:20px; \n"
"            padding:2px 4px;  \n"
"}"));

        verticalLayout_2->addWidget(IDEdit);

        widget_2->raise();
        horizontalLayoutWidget->raise();

        retranslateUi(Message);

        QMetaObject::connectSlotsByName(Message);
    } // setupUi

    void retranslateUi(QWidget *Message)
    {
        Message->setWindowTitle(QApplication::translate("Message", "Form", nullptr));
        Head->setText(QApplication::translate("Message", "...", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Message", "\346\230\265\347\247\260\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Message", "ID\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Message: public Ui_Message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
