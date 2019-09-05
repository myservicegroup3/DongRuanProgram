
#include "ui_widget.h"
#include "widget.h"
#include <stdlib.h>


Widget::Widget(QWidget *parent,QString id,QString name,QString myname, QString messages,QTcpSocket *sendtcpclient):
    QWidget(parent),
    ui(new Ui::Widget)
{
    now_id = id;
    now_name = name;
    now_messages = messages;
    now_myname = myname;
    ui->setupUi(this);
    this->uName=name;
    ui->inviteEdit->setPlaceholderText(u8"输入邀请至群聊的ID 点击右侧按钮");
    tcpClient=sendtcpclient;

    //发送与退出按钮
    connect(ui->sendBtn,&QPushButton::clicked,this,[=](){
        sndMsg(Msg);
    });

    connect(ui->exitBtn,&QPushButton::clicked,this,[=]()
    {
        this->close();
    });

    //字体设置
    connect(ui->fontCbx,&QFontComboBox::currentFontChanged,this,[=](const QFont &f){
        ui->msgTextEdit->setCurrentFont(f);
        ui->msgTextEdit->setFocus();
    });
    //字号设置
    void (QComboBox:: * cbxSingal)(const QString &text) = &QComboBox::currentIndexChanged;
       connect(ui->sizeCbx,cbxSingal,this,[=](const QString &text){
           ui->msgTextEdit->setFontPointSize(text.toDouble());
           ui->msgTextEdit->setFocus();
    });
    //加粗
    connect(ui->boldTBtn,&QToolButton::clicked,this,[=](bool checked){
        if(checked)
        {
            ui->msgTextEdit->setFontWeight(QFont::Bold);
        }
        else
        {
            ui->msgTextEdit->setFontWeight(QFont::Normal);
        }
        ui->msgTextEdit->setFocus();
    });
    //倾斜
    connect(ui->italicTBtn,&QToolButton::clicked,this,[=](bool checked){

        ui->msgTextEdit->setFontItalic(checked);

        ui->msgTextEdit->setFocus();
    });
    //下划线
    connect(ui->underlineTBtn,&QToolButton::clicked,this,[=](bool checked){
        ui->msgTextEdit->setFontUnderline(checked);

        ui->msgTextEdit->setFocus();
    });
    //文本颜色
    /*connect(ui->colorTBtn,&QToolButton::clicked,this,[=](){
       //color = QColorDialog::getColor(color,this); //color对象可以在widget.h中定义私有成员

       ui->msgTextEdit->setTextColor();
       ui->msgTextEdit->setFocus();

    });*/
    //保存聊天记录
    connect(ui->saveTBtn,&QToolButton::clicked,this,[=](){
        /*if(ui->msgBrowser->document()->isEmpty())
        {
            QMessageBox::warning(this,"警告","聊天记录为空，无法保存！",QMessageBox::Ok);
        }
        else
        {
            QString fName = QFileDialog::getSaveFileName(this,"保存聊天记录","聊天记录","(*.txt)");
            if(!fName.isEmpty())
            {
                //保存名称不为空再做保存操作
                QFile file(fName);
                file.open(QIODevice::WriteOnly | QFile::Text);

                QTextStream stream(&file);
                stream << ui->msgBrowser->toPlainText();
                file.close();
            }
        }*/
     });
    //清除聊天记录
    ui->clearTBtn->setStyleSheet("border-image:url(:/new/prefix1/Picture/clear.png)");
    connect(ui->clearTBtn,&QToolButton::clicked,[=](){
        ui->msgBrowser->clear();
    });

    ui->msgBrowser->append(now_name + ":" + now_messages);
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
               QMessageBox::warning(0,u8"警告",u8"发送内容不能为空",QMessageBox::Ok);
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
        //udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
    }

    void Widget::readMessages()
    {

    }
    void Widget::readifConnect()
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

    void Widget::receivedata(QString data)
    {
        ui->msgBrowser->setText(data);
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
        //udpSocket->close();
        //udpSocket->destroyed();
        QWidget::closeEvent(e);
    }







Widget::~Widget()
{
    delete ui;
}

void Widget::on_sendBtn_clicked()
{
    QString text=ui->msgTextEdit->toPlainText();
    ui->msgBrowser->append(now_myname + ":" + text);
    tcpClient->connectToHost(IP,PORT);
    if(!tcpClient->waitForConnected(10000))
    {
        qDebug()<<"the connect is failed!" << endl;
    }
    else
    {
        QString Type = QString::number((int)NormalMessage);
        std::string send_str_q = Type.toStdString() + split_type_gid + split_gid_id + now_id.toStdString() + split_id_msg + text.toStdString()+ msg_end;
        QString send_str = QString::fromStdString(send_str_q);
        qDebug()<< send_str;
        int tt;
        if(tt = tcpClient->write(send_str.toUtf8(),send_str.toUtf8().size()))
        {
            qDebug()<<"the write is succeed!" << "tt:" << tt << endl;
            if(connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readMessages())))
            {
                qDebug()<<"\nthe read is succeed!\n";
            }
            else
            {
                qDebug()<<connecttype;
                QMessageBox::information(this, u8"提示", u8"发生连接错误", QMessageBox::Ok);
            }
        }//发送服务器代码完毕
    }
}
