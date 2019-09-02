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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QLabel *label_5;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 429);
        Dialog->setStyleSheet(QStringLiteral("#Dialog{border-image:url(:/new/prefix2/Picture/backImg.JPG);}"));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 10, 171, 31));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 15, 71, 21));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 50, 71, 21));
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 50, 171, 31));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 110, 71, 21));
        radioButton = new QRadioButton(Dialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(140, 110, 71, 21));
        radioButton_2 = new QRadioButton(Dialog);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(220, 110, 71, 21));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 140, 71, 21));
        dateEdit = new QDateEdit(Dialog);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(140, 140, 121, 22));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 190, 71, 21));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 190, 131, 22));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 360, 75, 23));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 360, 75, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Dialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        radioButton->setText(QApplication::translate("Dialog", "\347\224\267", nullptr));
        radioButton_2->setText(QApplication::translate("Dialog", "\345\245\263", nullptr));
        label_4->setText(QApplication::translate("Dialog", "\345\207\272\347\224\237\345\271\264\346\234\210\357\274\232", nullptr));
        label_5->setText(QApplication::translate("Dialog", "\350\201\214\344\270\232\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
