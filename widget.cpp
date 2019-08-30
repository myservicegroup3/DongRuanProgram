#include "widget.h"
#include "ui_widget.h"
#include <QToolButton>
#include <QUdpSocket>
#include <QMessageBox>
#include <QDateTime>
#include <QPushButton>
Widget::Widget(QWidget *parent,QString usrname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->uName=usrname;
    udpSocket=new QUdpSocket(this);
    port=23333;
    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //采用ShareAddress模式(即允许其它的服务连接到相同的地址和端口，特别是用在多客户端监听同一个
    //服务器端口等时特别有效)，和ReuseAddressHint模式(重新连接服务器)
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::ReceiveMessage);
    sndMsg(UsrEnter);//有新用户加入


    connect(ui->sendBtn,&QPushButton::clicked,this,[=](){
        sndMsg(Msg);
    });

    connect(ui->exitBtn,&QPushButton::clicked,this,[=]()
    {
        this->close();
    });
}
    void Widget::sndMsg(MsgType type)
    {
        QByteArray data;
        QDataStream out(&data,QIODevice::WriteOnly);out << type << getUsr();
        //将消息类型 和 用户名 放入到流中
        switch (type)
        {
        case Msg:
            if(ui->msgTextEdit->toPlainText() == "")
            {
               QMessageBox::warning(0,"警告","发送内容不能为空",QMessageBox::Ok);
               return;
            }
            out  <<getMsg();  //发送的是聊天信息    发送格式   消息类型 + 用户名   + 发送内容
            break;
        case UsrEnter:        //发送的是新用户进入  发送格式   消息类型 + 用户名
            break;
        case UsrLeft:         // 发送的是用户离开  发送格式    消息类型 + 用户名
            break;
        default:
            break;
        }
        udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
    }

    void Widget::ReceiveMessage()
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in (&datagram,QIODevice::ReadOnly);
        int msgType;
        in >> msgType; //用户类型获取

        QString usrName,msg;  //用户名、信息
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        switch (msgType){
        case Msg:
            in >> usrName  >>msg;
            ui->msgBrowser->setTextColor(Qt::blue);
            ui->msgBrowser->setCurrentFont(QFont("Times New Roman",12));
            ui->msgBrowser->append("[ " + usrName + " ]" + time);
            ui->msgBrowser->append(msg);
            break;
        case UsrEnter:
            in >> usrName ;
            usrEnter(usrName);
            break;
        case UsrLeft:
            in >> usrName;
            usrLeft(usrName,time);
            break;
        default:
            break;
        }

    }


    QString Widget::getUsr()
    {
        return uName;
    }

    QString Widget::getMsg()
    {

        QString msg = ui->msgTextEdit->toHtml();
        ui->msgTextEdit->clear();
        ui->msgTextEdit->setFocus();
        return msg;
    }

    void Widget::usrEnter(QString usrname)
    {
        bool isEmpty = ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).isEmpty();
        if(isEmpty)
        {
            QTableWidgetItem *usr = new QTableWidgetItem(usrname);

            ui->usrTblWidget->insertRow(0);
            ui->usrTblWidget->setItem(0,0,usr);
            ui->msgBrowser->setTextColor(Qt::gray);
            ui->msgBrowser->setCurrentFont(QFont("Times New Roman",10));
            ui->msgBrowser->append(tr("%1 在线！").arg(usrname));


            //已经在线的各个端点也要告知新加入的端点他们自己的信息，若不这样做，在新端点用户列表中就无法显示其他已经在线的用户
            sndMsg(UsrEnter);
        }
    }

    void Widget::usrLeft(QString usrname,QString time)
    {
        int rowNum = ui->usrTblWidget->findItems(usrname, Qt::MatchExactly).first()->row();
        ui->usrTblWidget->removeRow(rowNum);
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->setCurrentFont(QFont("Times New Roman", 10));
        ui->msgBrowser->append(QString("%1 于 %2 离开！").arg(usrname).arg(time));

    }



    void Widget::closeEvent(QCloseEvent *e)
    {
        emit this->widgetClose();
        sndMsg(UsrLeft);
        udpSocket->close();
        udpSocket->destroyed();
        QWidget::closeEvent(e);
    }



Widget::~Widget()
{
    delete ui;
}



