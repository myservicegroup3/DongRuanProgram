#include <QMessageBox>
#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "fileoperator.h"
#include "user.h"
#include "database.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("软件开发工程师");
    ui->comboBox->addItem("软件产品经理");
    ui->comboBox->addItem("软件产品销售");
    ui->comboBox->addItem("网管");
    ui->comboBox->addItem("软件测试工程师");
    ui->comboBox->addItem("UI设计师");
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

void Dialog::on_pushButton_clicked()
{
    //注册时保存用户注册信息

    QString name=ui->lineEdit->text();
    QString pwd=ui->lineEdit_2->text();
    QString sex=ui->radioButton->isChecked() ? "Man" : "Woman";
    QString birthday=ui->dateEdit->text();
    QString major=ui->comboBox->currentText();
    //******************************************************************
    if((!name.isEmpty())&&(!pwd.isEmpty()))
    {
    User user(name, pwd, sex, birthday, major);
    DataBase* pdb = DataBase::getDatabaseInstence();
    bool ret = pdb->insertUsr(user);
    if (ret)
    {
        QMessageBox::information(this,
                                 "提示",
                                 "注册成功！",
                                 QMessageBox::Ok);
        //发射信号
        emit send(name,pwd);
    }
    }
    else
    {
        QMessageBox::information(this,
                                 "提示",
                                 "注册失败！",
                                 QMessageBox::Ok);
    }
    this->close();

}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
