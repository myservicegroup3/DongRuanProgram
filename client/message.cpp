#include "message.h"
#include "ui_message.h"
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QToolButton>
#include <QVector>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringList>
#include <QMessageBox>
#include <QIcon>
#include <QList>
#include <QScrollArea>
#include <QLineEdit>
#include <stdlib.h>
Message::Message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Message)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //ui->Head->setStyleSheet("border-radius:2px");

    QPushButton *m_minisizeBtn = new QPushButton(this);;
    QPushButton *m_closeBtn = new QPushButton(this);;
    m_minisizeBtn->setFixedSize(24, 24);
    m_minisizeBtn->setFlat(true);
    QString minisizeBtnStyle = "\
        QPushButton{\
            border-image:url(:/new/prefix1/Picture/minisize.png);\
        }\
        QPushButton:hover{\
            border-image:url(:/new/prefix1/Picture/minisizeHover.png);\
        }\
        QPushButton:pressed{\
            border-image:url(:/new/prefix1/Picture/minisizePressed.png);\
        }";
    m_minisizeBtn->setStyleSheet(minisizeBtnStyle);
    m_closeBtn->setFixedSize(24, 24);
    m_minisizeBtn->setFlat(true);
    QString closeBtnStyle = "\
        QPushButton{\
            border-image:url(:/new/prefix1/Picture/close.png);\
        }\
        QPushButton:hover{\
            border-image:url(:/new/prefix1/Picture/closeHover.png);\
        }\
        QPushButton:pressed{\
            border-image:url(:/new/prefix1/Picture/closePressed.png);\
        }";
    m_closeBtn->setStyleSheet(closeBtnStyle);
    ui->hLayout->addWidget(m_minisizeBtn);
    ui->hLayout->addWidget(m_closeBtn);
    connect(m_minisizeBtn, SIGNAL(clicked(bool)), this, SLOT(onMinisizeBtn()));
    connect(m_closeBtn, SIGNAL(clicked(bool)), this, SLOT(onCloseBtn()));


}

Message::~Message()
{
    delete ui;
}

//窗口可移动
void Message::mousePressEvent1(QMouseEvent *event)
{
    mouse_is_press1 = true;
    mouse_move_len1 = event->globalPos() - this->pos();
}
void Message::mouseMoveEvent1(QMouseEvent *event)
{

    if (  mouse_is_press1 && (event->buttons() && Qt::LeftButton) &&
        (event->globalPos()-mouse_move_len1).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - mouse_move_len1);
        mouse_move_len1 = event->globalPos() - pos();
    }
}

void Message::mouseReleaseEvent1(QMouseEvent *event)
{
    mouse_is_press1 = false;
}

void Message::readMessages()
{

    QString data = tcpClient->readAll();
    qDebug() << data;
    int nops_type_id = data.toStdString().find(split_type_gid);
    Signal type = (Signal)std::atoi(data.toStdString().substr(0,nops_type_id).c_str());
    qDebug() << type;
    switch(type)
    {
    case LogInSuccess:
        //建立连接


        //发射信号



    case WrongPassword:
        QMessageBox::information(this, u8"提示", u8"登入失败！密码错误", QMessageBox::Ok);
        break;
    case SomeError:
        QMessageBox::information(this, u8"提示", u8"登入失败！请先注册", QMessageBox::Ok);
        break;
    }
}

void Message::readifConnect()
{
    QString data = tcpClient->readAll();
    qDebug() << data;
    int nops_type_end = data.toStdString().find(split_type_gid);
    Signal type = (Signal)std::atoi(data.toStdString().substr(0,nops_type_end).c_str());
    if(type == ConnectSuccess)
        connecttype = 1;
    else
        connecttype = 0;
}


void Message::onMinisizeBtn()
{
    this->showMinimized();
}

void Message::onCloseBtn()
{
    this->close();
}

void Message::on_addBtn_clicked(bool checked)
{

}
