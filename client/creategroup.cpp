#include "creategroup.h"
#include "ui_creategroup.h"
#include "mainwindow_menu.h"
#include "widget.h"

creategroup::creategroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creategroup)
{
    ui->setupUi(this);
    connect(ui->createButton,SIGNAL(clicked(bool)),this,SLOT(condButtonPressed()));
}

creategroup::~creategroup()
{
    delete ui;
}

/*void creategroup::condButtonPressed()
{
    group = new Widget(this);
    group->show();
}*/


void creategroup::on_pushButton_3_clicked(bool checked)
{
    this->close();
}

//缺少功能 点击创建按钮新建一个widget 实现群聊
//       把好友列表放到上方窗中 点击添加选择加入群聊的好友


/*void creategroup::on_createButton_clicked(bool checked)
{

}*/
