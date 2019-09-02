#include "mainwindow_menu.h"
#include "ui_mainwindow_menu.h"
#include "widget.h"
#include <QToolButton>
#include <QVector>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringList>
#include <QMessageBox>
#include <QIcon>
#include <QPushButton>
#include <QList>
#include <QScrollArea>
#include <QPushButton>
#include <QLineEdit>
MainWindow_menu::MainWindow_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_menu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint );
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
    ui->closeLayout->addWidget(m_minisizeBtn);
    ui->closeLayout->addWidget(m_closeBtn);
    connect(m_minisizeBtn, SIGNAL(clicked(bool)), this, SLOT(onMinisizeBtn()));
    connect(m_closeBtn, SIGNAL(clicked(bool)), this, SLOT(onCloseBtn()));


    setWindowTitle("Myself QQ 2019");
    ui->Head1->setStyleSheet("border-image:url(:/123.jpg);");



    ui->UsrName->setStyleSheet("background-color: rgb(255, 255, 255, 0);");
    ui->signEdit->setPlaceholderText(u8"编辑个性签名");
    ui->signEdit->setFrame(false);

    ui->FindEdit->setPlaceholderText(u8"输入搜索关键字：");
    ui->FindEdit->setFrame(false);

    ui->Findwidget->setAutoFillBackground(true);
    /*ui->Findwidget->setStyleSheet("border-image:url(:/new/prefix1/Picture/mainBackImg.jpg);"
                                  "}");*/
    ui->FindEdit->setStyleSheet("background-color: rgb(255, 255, 255, 0);"

                                "border-width:0;border-style:outset;"
                                "");
    ui->signEdit->setStyleSheet("background-color: rgb(255, 255, 255, 0);"

                                "border-width:0;border-style:outset;"
                                "");

       ui->tableWidget->setTabShape(QTabWidget::Triangular);
       ui->tableWidget->setDocumentMode(true);
       ui->tableWidget->setIconSize(QSize(20,20));
       QString tabBarStyle =
           "QTabWidget::pane{\
               border:none;\
           }\
           QTabWidget::tab-bar{\
                   alignment:left;\
           }\
           QTabBar::tab{\
               background:transparent;\
               color:white;\
               min-width:30ex;\
               min-height:10ex;\
           }\
           QTabBar::tab:hover{\
               background:rgb(255, 151, 68, 100);\
           }\
           QTabBar::tab:selected{\
               border-color:rgb(111, 151, 68, 100);\
               background:rgb(111, 151, 68, 80);\
               color:green;\
           }";
       ui->tableWidget->setStyleSheet(tabBarStyle);

       QListWidget *dialogListWidget = new QListWidget;
       QListWidget *friendListWidget = new QListWidget;
       QListWidget *groupChatListWidget = new QListWidget;

       dialogListWidget->setFrameStyle(0);
       friendListWidget->setFrameStyle(0);
       groupChatListWidget->setFrameStyle(0);


       ui->tableWidget->addTab(dialogListWidget, QIcon(QPixmap(":/new/prefix1/Picture/dialogIcon.png")),"");
       ui->tableWidget->addTab(friendListWidget, QIcon(QPixmap(":/new/prefix1/Picture/friendListIcon.png")),"");
       ui->tableWidget->addTab(groupChatListWidget, QIcon(QPixmap(":/new/prefix1/Picture/groupChatIcon.png")),"");

       ui->tableWidget->setTabToolTip(0,"会话");
       ui->tableWidget->setTabToolTip(1,"联系人");
       ui->tableWidget->setTabToolTip(2,"群聊");

       ui->tableWidget->setCurrentIndex(1);


       QVBoxLayout *Layout1 = new QVBoxLayout;
       QVBoxLayout *Layout2 = new QVBoxLayout;
       QVBoxLayout *Layout3 = new QVBoxLayout;

       Layout1->setContentsMargins(5,0,0,0);
       Layout2->setContentsMargins(5,0,0,0);
       Layout3->setContentsMargins(5,0,0,0);

       dialogListWidget->setLayout(Layout1);
       friendListWidget->setLayout(Layout2);
       groupChatListWidget->setLayout(Layout3);


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
           Layout2->addWidget(btn);
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

void MainWindow_menu::onMinisizeBtn()
{
    this->showMinimized();
}

void MainWindow_menu::onCloseBtn()
{
    this->close();
}




void MainWindow_menu::on_FindButton_clicked(bool checked)
{

}

void MainWindow_menu::on_lineEdit_textChanged(const QString &arg1)
{

}

