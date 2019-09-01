#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include "fileoperator.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "mainwindow_menu.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_2->setPlaceholderText("用户名");
    ui->lineEdit->setAlignment(Qt::AlignHCenter);
    ui->lineEdit->setPlaceholderText("密码");

}

MainWindow::~MainWindow()
{
    delete ui;
}

//QString MainWindow::getNamepwd()
//{

//}

void MainWindow::on_pushButton_5_clicked()
{
    //1.获取用户名和密码
    QString name = ui->lineEdit_2->text();
    QString pwd = ui->lineEdit->text();
    if((!name.isEmpty())&&(!pwd.isEmpty()))
    {
    DataBase* pdb = DataBase::getDatabaseInstence();
    bool ret1 = pdb->findUsr(name);
    if(ret1)
    {
        bool ret2 = pdb->judge(name, pwd);
        if (ret2)
        {
            //登录成功显示主窗口
            MainWindow_menu *mw = new MainWindow_menu();

            //建立连接
            connect(this, SIGNAL(sendUsrname(QString)), mw, SLOT(recUsrname(QString)));

            //发射信号
            emit sendUsrname(name);

            mw->setAttribute(Qt::WA_DeleteOnClose);
            this->close();
            mw->show();
//            this->hide();
        }
        else
        {
            QMessageBox::information(this, "提示", "登入失败！用户名或密码错误", QMessageBox::Ok);
        }
    }
    }
    else
    {
        QMessageBox::information(this, "提示", "登入失败！未注册，请先注册", QMessageBox::Ok);
    }

}




void MainWindow::on_pushButton_2_clicked()
{
    Dialog dlg;
    connect ( &dlg, SIGNAL (send(QString ,QString )),this, SLOT(receive(QString ,QString )) );
    dlg.exec();
}

void MainWindow::receive(QString suername, QString passward)
{
    ui->lineEdit_2->setText(suername);
    ui->lineEdit->setText(passward);
}
