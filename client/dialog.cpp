#include <QMessageBox>
#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "mainwindow_menu.h"
#include "fileoperator.h"
#include "user.h"
#include "database.h"
#include <QTcpSocket>

QString globle_pwd;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}


Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getnamepwd()
{
    return rname,rpassward;
}

void Dialog::setnamepwd(QString &value1, QString &value2)
{
    rname=value1;
    rpassward=value2;
}

void Dialog::readMessages()
{
    MainWindow *mw = new MainWindow();
    QString data = tcpClient->readAll();
    qDebug() << data;
    int nops_type_id = data.toStdString().find(split_type_gid);
    int nops_msg = data.toStdString().find(msg_end);
    int nops_id_msg = data.toStdString().find(split_id_msg);
    Signal type = (Signal)std::atoi(data.toStdString().substr(0,nops_type_id).c_str());
    QString id = QString::fromStdString(data.toStdString().substr(nops_id_msg+1,nops_msg-nops_id_msg-1));
    qDebug() << type << " " << id;
    QString mess = u8"注册成功！你的id是：" + id;
    switch(type)
    {
    case LogInSuccess:
        QMessageBox::information(this, u8"提示", mess.toUtf8(), QMessageBox::Ok);
        //建立连接
        connect(this, SIGNAL(send(QString,QString)), mw , SLOT(recv(QString,QString)));

        //发射信号
        emit send(id,globle_pwd);

        this->close();
        break;
    case SomeError:
        QMessageBox::information(this, u8"提示", u8"注册失败！请检查网络", QMessageBox::Ok);
        break;
    }
}

void Dialog::on_pushButton_clicked()
{
    tcpClient->connectToHost(IP,PORT);
    if(!tcpClient->waitForConnected(10000))
    {
        qDebug()<<"the connect is failed!" << endl;
    }
    else
    {
        QString name=ui->lineEdit->text();
        QString pwd=ui->lineEdit_2->text();
        QString signup_type = QString::number(SignUp);
        std::string send_signup_str = signup_type.toStdString() + split_type_id + name.toStdString() + split_id_pwd + pwd.toStdString() + msg_end ;
        QString send_signup = QString::fromStdString(send_signup_str);
        if(tcpClient->write(send_signup.toUtf8(),send_signup.toUtf8().size()))
        {
            qDebug()<<"the write is succeed!" << endl;
            globle_pwd = pwd;
            if(connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readMessages())))
            {
                qDebug()<<"\nthe read is succeed!\n";
            }
            else
            {
                QMessageBox::information(this, u8"提示", u8"发生连接错误", QMessageBox::Ok);
            }
        }
        else
        {

        }
    }
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
