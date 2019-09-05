#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include "fileoperator.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "mainwindow_menu.h"
#include "database.h"
#include <QTcpSocket>
#include <stdlib.h>

QByteArray array;
QString globle_id;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_2->setPlaceholderText(u8"用户名");
    ui->lineEdit->setAlignment(Qt::AlignHCenter);
    ui->lineEdit->setPlaceholderText(u8"密码");
}

void MainWindow::on_pushButton_2_clicked()
{

    Dialog dlg;
    connect ( &dlg, SIGNAL (send(QString ,QString)),this, SLOT(receive(QString ,QString )));
    dlg.exec();
}

void MainWindow::receive(QString id, QString passward)//注册输入密码账号
{
    ui->lineEdit_2->setText(id);
    ui->lineEdit->setText(passward);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//QString MainWindow::getNamepwd()
//{

//}

void MainWindow::readifConnect()
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

void MainWindow::readMessages(){
    QString data = tcpClient->readAll();
    qDebug() << data;
    int nops_type_id = data.toStdString().find(split_type_gid);
    Signal type = (Signal)std::atoi(data.toStdString().substr(0,nops_type_id).c_str());
    if(type == LogInSuccess)
    {
        int name_s = data.toStdString().find(split_id_msg);//找打 ‘|’符号的位置;
        data=data.mid(name_s+1);
        int name_el = data.toStdString().find(split_yourname_friendlist);//找‘&'位置
        QString name = data.mid(0, name_el);//主用户名
        qDebug()<<"the user name is " << name;
        data = data.mid(name_el+1);
        qDebug()<<data;
        while(data != QString::fromStdString(msg_end))
        {
            int name_pl=data.toStdString().find(split_id_name);//"-"
            idList<<data.mid(0,name_pl);//找每一个好友的name，用namelist 存起来
            qDebug()<<"the id is "<<data.mid(0,name_pl)<<endl;
            data=data.mid(name_pl+1);
            int id_pl=data.toStdString().find(split_client_client);
            nameList<<data.mid(0,id_pl);
            qDebug()<<"the name is"<<data.mid(0,id_pl)<<endl;//找每一个好友的id
            data=data.mid(id_pl+1);
            Signal type = (Signal)std::atoi(data.toStdString().substr(0,nops_type_id).c_str());
            qDebug() << type;
        }
        qDebug() << "name:" << name;
        MainWindow_menu *mw = new MainWindow_menu(idList, nameList, messagesList, globle_id, name, tcpClient);
        stablemw = mw;
        mw->createUserList();
        mw->createClickButton();
        mw->setAttribute(Qt::WA_DeleteOnClose);
        this->close();
        mw->show();
    }
    if(type == WrongPassword)
    {
        QMessageBox::information(this, u8"提示", u8"登入失败！密码错误", QMessageBox::Ok);
    }
    if(type == SomeError)
    {
        QMessageBox::information(this, u8"提示", u8"登入失败！请先注册", QMessageBox::Ok);
    }
    QString message_id = "-1";
    QString message_re = "";
    QString message_gid = "-1";
    if(type == NormalMessage)
    {
        data=data.mid(nops_type_id+1);
        qDebug() << "data is"<<data;
        int id_start = data.toStdString().find(split_type_id);
        int id_end=data.toStdString().find(split_id_msg);
        message_id = data.mid(id_start + 1,id_end - id_start - 1);
        qDebug()<<"message_id is"<<message_id;
        int end=data.toStdString().find(msg_end);
        message_re = data.mid(id_end + 1, end - id_end -1);
        qDebug()<<"message_re is"<<message_re;
        for(int i = 0; i<idList.size(); i++)
        {
            if(message_re != "")
            {
                messagesList[i] += message_re;
            }
        }
        stablemw->send(idList, nameList, messagesList, globle_id, name, tcpClient);
    }
    if (type == FriendRequest) //别人向你请求添加好友
    {
        if (data.toStdString().find(split_gid_id) == nops_type_id + 1) //判断‘：’后面是否为‘！”,是即单聊
        {
            data = data.mid(nops_type_id + 2); //FriendRequest:!id|message__MSGED__\0
            qDebug() << u8"从id第一位开始" << data;
            int id_end = data.toStdString().find(split_id_msg); //找’|‘
            //.h文件建立一个 add_id,表示申请加你好友人的id
            message_id = data.mid(0, id_end);
            message_re = "";
        }
        else //单聊
        {
            data = data.mid(nops_type_id + 1);                        //定位group_id的第一位
            int group_id_end = data.toStdString().find(split_gid_id); //找’！‘
            message_gid = data.mid(0, group_id_end);                  //表示群聊id
            data = data.mid(group_id_end + 1);                        //定位id的第一位
            int id_end = data.toStdString().find(split_id_msg);       //找’|‘
            message_id = data.mid(0, id_end);
        }
        QuestionWidget(message_id, message_gid);
        stablemw->send(idList, nameList, messagesList, globle_id, name, tcpClient);
    }

    if (type == RequestAgree)
    {                                                                  //RequestAgree:group_id!id|message__MSGED__\0  //别人同意了你的好友申请
        if (!(data.toStdString().find(split_gid_id) == nops_type_id + 1)) //判断‘：’后面是否为‘！”,是即群聊
        {
            data = data.mid(nops_type_id + 1);                        //定位group_id的第一位
            int group_id_end = data.toStdString().find(split_gid_id); //找’！‘
            message_gid = data.mid(0, group_id_end);                 //表示群聊id
            data = data.mid(group_id_end + 1);                        //定位id的第一位
            int id_end = data.toStdString().find(split_id_msg);       //找’|‘
            message_id = data.mid(0, id_end);                            //参数zadd_id表示别人的id
        }
        else
        {
            data = data.mid(nops_type_id + 2); //FriendRequest:group_id!id|message__MSGED__\0
            qDebug() << "从id第一位开始" << data;
            int id_end = data.toStdString().find(split_id_msg); //找’|‘
            //.h文件建立一个 add_id,表示申请加你好友人的id
            message_id = data.mid(0, id_end);
        }
        stablemw->send(idList, nameList, messagesList, globle_id, name, tcpClient);
    }
    if (type == RequestRefuse)
    {                                                                  //RequestAgree:group_id!id|message__MSGED__\0  //别人拒绝了你的好友申请
        if (!(data.toStdString().find(split_gid_id) == nops_type_id + 1)) //判断‘：’后面是否为‘！”,是即群聊
        {
            data = data.mid(nops_type_id + 1);                        //定位group_id的第一位
            int group_id_end = data.toStdString().find(split_gid_id); //找’！‘
            message_gid = data.mid(0, group_id_end);                 //表示群聊id
            data = data.mid(group_id_end + 1);                        //定位id的第一位
            int id_end = data.toStdString().find(split_id_msg);       //找’|‘
            message_id = data.mid(0, id_end);                            //参数zadd_id表示别人的id
        }
        else
        {
            data = data.mid(nops_type_id + 2); //FriendRequest:group_id!id|message__MSGED__\0
            qDebug() << "从id第一位开始" << data;
            int id_end = data.toStdString().find(split_id_msg); //找’|‘
            //.h文件建立一个 add_id,表示申请加你好友人的id
            message_id = data.mid(0, id_end);
        }
        stablemw->send(idList, nameList, messagesList, globle_id, name, tcpClient);
    }
}
//登陆槽函数
void MainWindow::on_pushButton_5_clicked()
{
    tcpClient->connectToHost(IP,PORT);
    if(!tcpClient->waitForConnected(10000))
    {
        qDebug()<<"the connect is failed!" << endl;
    }
    else
    {
            //识别是否接收到可以发送id和密码的消息
#if 0
            while(!connecttype)
            {
                 qDebug() << "Waitng for connect signal" << endl;
                 connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readifConnect()));
            }
#endif
            qDebug()<<"the connect is succeed!" << endl;
            QString id = ui->lineEdit_2->text();
            QString pwd = ui->lineEdit->text();
            //发送用户名和密码到服务器
            QString Type = QString::number((int)LogIn);
            std::string send_str_q = Type.toStdString() + split_type_id + id.toStdString() + split_id_pwd + pwd.toStdString() + msg_end;
            QString send_str = QString::fromStdString(send_str_q);
            qDebug()<< send_str;
            int tt;
            if(tt = tcpClient->write(send_str.toUtf8(),send_str.toUtf8().size()))
            {
                qDebug()<<"the write is succeed!" << "tt:" << tt << endl;
                globle_id = id;
                if(connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readMessages())))
                {
                    qDebug()<<"\nthe read is succeed!\n";
                }
                else
                {
                    qDebug()<<connecttype;
                    QMessageBox::information(this, u8"提示", u8"发生连接错误", QMessageBox::Ok);
                }
            }
            else
            {
                qDebug()<<"the write is ERROR!";
                QMessageBox::information(this, u8"提示", u8"写入数据错误", QMessageBox::Ok);
            }
    }
}

void MainWindow::QuestionWidget(QString nid, QString gid)
{
    qDebug() << "ttttttttttt";
    QString group_id;
    if (gid == "-1")
    {
        group_id = "";
    }
    else
    {
        group_id = gid;
    }
    QString Type_r = QString::number((int)RequestAgree);
    std::string send_str_r = Type_r.toStdString() + split_type_gid + group_id.toStdString() + split_gid_id + nid.toStdString() + split_id_msg + msg_end;
    QString send_r = QString::fromStdString(send_str_r);
    QString Type_w = QString::number((int)RequestRefuse);
    std::string send_str_w = Type_w.toStdString() + split_type_gid + group_id.toStdString() + split_gid_id + nid.toStdString() + split_id_msg + msg_end;
    QString send_w = QString::fromStdString(send_str_w);
    switch(QMessageBox::question(this,QString(tr("好友申请")),QString("user:"+ nid + id + "向你发送了一个好友请求"),QString(tr("接受")), QString(tr("拒绝")),0,1))
    {

        case 0:
            tcpClient->write(send_r.toUtf8());
            break;
        case 1:
            tcpClient->write(send_w.toUtf8());
            break;
        default:
                break;
    }
}
