#include "dialoglist.h"
#include "ui_dialoglist.h"
#include "widget.h"
#include <QToolButton>
#include <QVector>
#include <QMessageBox>
DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    setWindowTitle("Myself QQ 2019");
    setWindowIcon(QPixmap(":/123.jpg"));

    QVector<QToolButton *>vToolBtn;
    for(int i=0;i<10;i++)
    {
        QToolButton * btn = new QToolButton;
        btn->setText("123");
        btn->setIcon(QPixmap(":/123.jpg"));
        btn->setIconSize(QPixmap(":/123.jpg").size());
        btn->setAutoRaise(true);
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->vLayout->addWidget(btn);
        vToolBtn.push_back(btn);
    }

    //添加点击事件
       for(int i = 0 ; i < vToolBtn.size();i++)
       {
           connect(vToolBtn[i],&QToolButton::clicked,this,[=]()
           {
               if(isShow[i])
               {
                   QMessageBox::warning(this,"警告",QString("用户%1窗口已弹出").arg(vToolBtn[i]->text()));
                   return;
               }
               isShow[i]=true;
               //qDebug() <<i;
               //此时，widget的构造函数已经修改，（见4.2步骤）创建widget窗口时，参数1 ：0代表以顶层方式弹出
               //参数2：代表vToolBtn[i]->text()代表告诉聊天窗口 人物的姓名
              Widget *chatWidget = new Widget(0,vToolBtn[i]->text());
              chatWidget->setWindowTitle(vToolBtn[i]->text());
              chatWidget->setWindowIcon(vToolBtn[i]->icon());
              chatWidget->show();

              connect(chatWidget,&Widget::widgetClose,this,[=](){isShow[i]=false;});

           });
       }

       for(int i=0;i<9;i++)
       {
           isShow.push_back(false);
       }


}

DialogList::~DialogList()
{
    delete ui;
}
