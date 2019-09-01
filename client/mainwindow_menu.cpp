/*#include "mainwindow_menu.h"
#include "ui_mainwindow_menu.h"
#include "listwidget.h"

MainWindow_menu::MainWindow_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_menu)
{
    ui->setupUi(this);
    listwidget_ = new ListWidget(this);
//    this->setCentralWidget(listwidget_);
    listwidget_->setGeometry(100, 100, 600, 260);
}

MainWindow_menu::~MainWindow_menu()
{
    delete ui;
}

void MainWindow_menu::recUsrname(QString name)
{
    QString str = QString("欢迎你! %1").arg(name);
    ui->label->setText(str);
}*/


#include "mainwindow_menu.h"
#include "ui_mainwindow_menu.h"
#include "widget.h"
#include <QToolButton>
#include <QVector>
#include <QMessageBox>
#include <QIcon>
#include <QPushButton>
#include <QList>
#include <QScrollArea>
#include <QPushButton>
MainWindow_menu::MainWindow_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_menu)
{
    ui->setupUi(this);


    setWindowTitle("Myself QQ 2019");
    setWindowIcon(QPixmap(":/123.jpg"));

    QPushButton* Head1 = new QPushButton(this);
    QIcon ico(":/123.jpg");
    Head1->setIcon(ico);
    Head1->setIconSize(QSize(80,80));
    Head1->setFlat(true);

    QList<QString>nameList;
        nameList <<"a"<<"b"<<"c"<<"d"<<"e"<<"f"<<"g"
                <<"h"<<"i"<<"j";

    QVector<QToolButton *>vToolBtn;
    for(int i=0;i<10;i++)
    {
        QToolButton * btn = new QToolButton;
        btn->setText(nameList[i]);
        btn->setIcon(QPixmap(":/123.jpg"));
        btn->setIconSize(QPixmap(":/123.jpg").size());
        btn->setAutoRaise(true);
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->vLayout->addWidget(btn);
        vToolBtn.push_back(btn);
    }

    //添加点击事件
       for(int ii = 0  ; ii < vToolBtn.size();ii++)
       {

           connect(vToolBtn[ii],&QToolButton::clicked,this,[=]()
           {
               if(isShow[ii])
               {
                   QMessageBox::warning(this,"警告",QString("用户%1窗口已弹出").arg(vToolBtn[ii]->text()));
                   return;
               }
               isShow[ii]=true;
               //qDebug() <<i;
               //此时，widget的构造函数已经修改，（见4.2步骤）创建widget窗口时，参数1 ：0代表以顶层方式弹出
               //参数2：代表vToolBtn[i]->text()代表告诉聊天窗口 人物的姓名
              Widget *chatWidget = new Widget(0,vToolBtn[ii]->text());
              chatWidget->setWindowTitle(vToolBtn[ii]->text());
              chatWidget->setWindowIcon(vToolBtn[ii]->icon());
              chatWidget->show();
              connect(chatWidget,&Widget::widgetClose,this,[=](){isShow[ii]=false;});


           });
        }

       for(int i=0;i<9;i++)
       {
           isShow.push_back(false);
       }


}

MainWindow_menu::~MainWindow_menu()
{
    delete ui;
}
