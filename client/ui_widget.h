/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextBrowser *msgBrowser;
    QTextEdit *msgTextEdit;
    QTableWidget *usrTblWidget;
    QFontComboBox *fontCbx;
    QComboBox *sizeCbx;
    QPushButton *sendBtn;
    QPushButton *exitBtn;
    QToolButton *boldTBtn;
    QToolButton *italicTBtn;
    QToolButton *underlineTBtn;
    QToolButton *colorTBtn;
    QToolButton *saveTBtn;
    QToolButton *clearTBtn;
    QWidget *widget;
    QLabel *label_2;
    QLineEdit *inviteEdit;
    QToolButton *inviteButton;
    QWidget *newwidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(680, 500);
        Widget->setMouseTracking(true);
        Widget->setTabletTracking(true);
        Widget->setStyleSheet(QStringLiteral(""));
        msgBrowser = new QTextBrowser(Widget);
        msgBrowser->setObjectName(QStringLiteral("msgBrowser"));
        msgBrowser->setGeometry(QRect(10, 50, 481, 211));
        msgBrowser->setStyleSheet(QLatin1String("#msgBrowser{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));\n"
"            border:1px;\n"
"            border-radius:20px; \n"
"            padding:2px 4px;  \n"
"}"));
        msgTextEdit = new QTextEdit(Widget);
        msgTextEdit->setObjectName(QStringLiteral("msgTextEdit"));
        msgTextEdit->setGeometry(QRect(10, 310, 481, 151));
        msgTextEdit->setStyleSheet(QLatin1String("#msgTextEdit{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));\n"
"            border:1px;\n"
"            border-radius:20px; \n"
"            padding:2px 4px;  \n"
"}"));
        usrTblWidget = new QTableWidget(Widget);
        if (usrTblWidget->columnCount() < 1)
            usrTblWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usrTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        usrTblWidget->setObjectName(QStringLiteral("usrTblWidget"));
        usrTblWidget->setGeometry(QRect(500, 280, 171, 211));
        usrTblWidget->setStyleSheet(QLatin1String("#usrTblWidget{\n"
"			color: rgb(255, 255, 255);\n"
"            \n"
"            border:1px;\n"
"			background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));\n"
"            border-radius:20px; \n"
"            padding:2px 4px;  \n"
"}"));
        usrTblWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        usrTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        usrTblWidget->setShowGrid(false);
        fontCbx = new QFontComboBox(Widget);
        fontCbx->setObjectName(QStringLiteral("fontCbx"));
        fontCbx->setGeometry(QRect(10, 270, 91, 31));
        sizeCbx = new QComboBox(Widget);
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->setObjectName(QStringLiteral("sizeCbx"));
        sizeCbx->setGeometry(QRect(110, 270, 91, 31));
        sizeCbx->setStyleSheet(QStringLiteral("QComboBox{border-color:rgb(170, 255, 255);}"));
        sendBtn = new QPushButton(Widget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(190, 470, 75, 23));
        sendBtn->setStyleSheet(QLatin1String("QPushButton:hover{\n"
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
        exitBtn = new QPushButton(Widget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(340, 470, 75, 23));
        exitBtn->setStyleSheet(QLatin1String("QPushButton:hover{\n"
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
        boldTBtn = new QToolButton(Widget);
        boldTBtn->setObjectName(QStringLiteral("boldTBtn"));
        boldTBtn->setGeometry(QRect(210, 270, 33, 32));
        boldTBtn->setStyleSheet(QStringLiteral("#boldTBtn{border-image:url(:/new/prefix1/Picture/_bold.png);}"));
        boldTBtn->setCheckable(true);
        italicTBtn = new QToolButton(Widget);
        italicTBtn->setObjectName(QStringLiteral("italicTBtn"));
        italicTBtn->setGeometry(QRect(250, 270, 33, 32));
        italicTBtn->setStyleSheet(QStringLiteral("#italicTBtn{border-image:url(:/new/prefix1/Picture/_italic.png);}"));
        italicTBtn->setCheckable(true);
        underlineTBtn = new QToolButton(Widget);
        underlineTBtn->setObjectName(QStringLiteral("underlineTBtn"));
        underlineTBtn->setGeometry(QRect(290, 270, 33, 32));
        underlineTBtn->setStyleSheet(QStringLiteral("#underlineTBtn{border-image:url(:/new/prefix1/Picture/_xiahuaxian.png);}"));
        underlineTBtn->setCheckable(true);
        colorTBtn = new QToolButton(Widget);
        colorTBtn->setObjectName(QStringLiteral("colorTBtn"));
        colorTBtn->setGeometry(QRect(330, 270, 33, 32));
        colorTBtn->setStyleSheet(QStringLiteral("#colorTBtn{border-image:url(:/new/prefix1/Picture/_changecolor.png);}"));
        colorTBtn->setCheckable(true);
        saveTBtn = new QToolButton(Widget);
        saveTBtn->setObjectName(QStringLiteral("saveTBtn"));
        saveTBtn->setGeometry(QRect(370, 270, 33, 32));
        saveTBtn->setStyleSheet(QStringLiteral("#saveTBtn{border-image:url(:/new/prefix1/Picture/_save.png);}"));
        saveTBtn->setCheckable(true);
        clearTBtn = new QToolButton(Widget);
        clearTBtn->setObjectName(QStringLiteral("clearTBtn"));
        clearTBtn->setGeometry(QRect(410, 270, 33, 32));
        clearTBtn->setStyleSheet(QStringLiteral("#clearTBtn{border-image:url(:/new/prefix1/Picture/_clear.png);}"));
        clearTBtn->setCheckable(true);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(500, 140, 181, 151));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 171, 61));
        QFont font;
        font.setFamily(QStringLiteral("Simplex"));
        font.setPointSize(16);
        label_2->setFont(font);
        inviteEdit = new QLineEdit(widget);
        inviteEdit->setObjectName(QStringLiteral("inviteEdit"));
        inviteEdit->setGeometry(QRect(0, 90, 141, 31));
        inviteEdit->setStyleSheet(QLatin1String("#inviteEdit{\n"
"			color: rgb(255, 255, 255);\n"
"            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));\n"
"            border:1px;\n"
"            border-radius:4px; \n"
"            padding:2px 4px;  \n"
"}"));
        inviteButton = new QToolButton(widget);
        inviteButton->setObjectName(QStringLiteral("inviteButton"));
        inviteButton->setGeometry(QRect(140, 90, 31, 31));
        inviteButton->setStyleSheet(QStringLiteral("#inviteButton{border-image:url(:/new/prefix1/Picture/search.png);}"));
        newwidget = new QWidget(Widget);
        newwidget->setObjectName(QStringLiteral("newwidget"));
        newwidget->setGeometry(QRect(-1, -1, 681, 511));
        newwidget->setStyleSheet(QStringLiteral("#newwidget{border-image:url(:/new/prefix1/Picture/sea3.jpg);}"));
        newwidget->raise();
        msgBrowser->raise();
        msgTextEdit->raise();
        usrTblWidget->raise();
        fontCbx->raise();
        sizeCbx->raise();
        sendBtn->raise();
        exitBtn->raise();
        boldTBtn->raise();
        italicTBtn->raise();
        underlineTBtn->raise();
        colorTBtn->raise();
        saveTBtn->raise();
        clearTBtn->raise();
        widget->raise();

        retranslateUi(Widget);

        sizeCbx->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        QTableWidgetItem *___qtablewidgetitem = usrTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        sizeCbx->setItemText(0, QApplication::translate("Widget", "8", nullptr));
        sizeCbx->setItemText(1, QApplication::translate("Widget", "9", nullptr));
        sizeCbx->setItemText(2, QApplication::translate("Widget", "10", nullptr));
        sizeCbx->setItemText(3, QApplication::translate("Widget", "11", nullptr));
        sizeCbx->setItemText(4, QApplication::translate("Widget", "12", nullptr));
        sizeCbx->setItemText(5, QApplication::translate("Widget", "13", nullptr));
        sizeCbx->setItemText(6, QApplication::translate("Widget", "14", nullptr));
        sizeCbx->setItemText(7, QApplication::translate("Widget", "15", nullptr));
        sizeCbx->setItemText(8, QApplication::translate("Widget", "16", nullptr));
        sizeCbx->setItemText(9, QApplication::translate("Widget", "17", nullptr));
        sizeCbx->setItemText(10, QApplication::translate("Widget", "18", nullptr));
        sizeCbx->setItemText(11, QApplication::translate("Widget", "19", nullptr));
        sizeCbx->setItemText(12, QApplication::translate("Widget", "20", nullptr));
        sizeCbx->setItemText(13, QApplication::translate("Widget", "21", nullptr));
        sizeCbx->setItemText(14, QApplication::translate("Widget", "22", nullptr));

        sendBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
#ifndef QT_NO_SHORTCUT
        sendBtn->setShortcut(QApplication::translate("Widget", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        exitBtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_SHORTCUT
        exitBtn->setShortcut(QApplication::translate("Widget", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        boldTBtn->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        boldTBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        italicTBtn->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        italicTBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        underlineTBtn->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        underlineTBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        colorTBtn->setToolTip(QApplication::translate("Widget", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        colorTBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveTBtn->setToolTip(QApplication::translate("Widget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        saveTBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        clearTBtn->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        clearTBtn->setText(QString());
        label_2->setText(QApplication::translate("Widget", "Enjoy talking!", nullptr));
        inviteButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
