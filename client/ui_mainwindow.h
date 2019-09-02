/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(481, 319);
        MainWindow->setStyleSheet(QLatin1String("/*QMainWindow{\n"
"	\n"
"	\n"
"	border-image:url(:/new/prefix2/Picture/backImg.JPG);\n"
"}*/"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 200, 181, 31));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit:hover{\n"
"border-style:ooutset;\n"
"border-radius:10px;\n"
"padding:6px;\n"
"background-color: rgb(255, 255, 127);\n"
"		 \n"
"}"));
        lineEdit->setEchoMode(QLineEdit::Password);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 150, 75, 31));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton:hover{color:rgb(255, 0, 0);\n"
"background-color: rgb(170, 255, 0);\n"
"}\n"
"QPushButton{background-color:rgb(170, 255, 255)}"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 200, 75, 31));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton:hover{color:rgb(255, 0, 0);\n"
"background-color: rgb(170, 255, 0);\n"
"}\n"
"QPushButton{background-color:rgb(170, 255, 255)}"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(160, 240, 71, 16));
        checkBox->setStyleSheet(QStringLiteral("QCheckBox:hover{color:rgb(255, 0, 0)}"));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(270, 240, 71, 16));
        checkBox_2->setStyleSheet(QStringLiteral("QCheckBox:hover{color:rgb(255, 0, 0)}"));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(160, 260, 181, 31));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton:hover{color:rgb(255, 0, 0);\n"
"\n"
"	background-color: rgb(170, 255, 0);\n"
"}\n"
"QPushButton{\n"
"	background-color:rgb(170, 255, 255)\n"
"}\n"
""));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 252, 31, 31));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	border-image: url(:/new/prefix1/ziyuan/b4e6539c872c1b4db45852da774183b4.png);\n"
"}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 150, 81, 81));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/ziyuan/HeadImage.png")));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 150, 181, 31));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit:hover{\n"
"border-style:ooutset;\n"
"border-radius:10px;\n"
"padding:6px;\n"
"background-color: rgb(255, 255, 127);\n"
"\n"
"		 \n"
"}"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 481, 141));
        label_2->setStyleSheet(QStringLiteral("QLabel{border-image:url(:/new/prefix1/Picture/backImg.JPG);}"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\347\231\273  \345\275\225", nullptr));
        pushButton_6->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
