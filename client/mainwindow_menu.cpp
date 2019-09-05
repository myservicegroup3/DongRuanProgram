#include "mainwindow_menu.h"
#include "ui_mainwindow_menu.h"
#include "ui_message.h"
#include "widget.h"
#include "message.h"
#include <Qmap>

MainWindow_menu::MainWindow_menu(QList<QString> sendidList,QList<QString> sendnameList ,QList<QString> sendmessagesList ,QString sendid, QString sendname, QTcpSocket *sendtcpClient, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_menu)
{
    nameList = sendnameList;
    idList = sendidList;
    messagesList = sendmessagesList;
    id = sendid;
    name = sendname;
    tcpClient = sendtcpClient;
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
    ui->Head1->setStyleSheet("border-image:url(:/123.jpg);"
                             "border-radius:30px;");



    ui->UsrName->setStyleSheet("background-color: rgb(255, 255, 255, 0);");
    ui->signEdit->setPlaceholderText(u8"编辑个性签名");
    ui->signEdit->setFrame(false);

    ui->FindEdit->setPlaceholderText(u8"输入搜索关键字：");
    ui->FindEdit->setFrame(false);

    ui->addEdit->setPlaceholderText(u8"输入想要添加的ID 点击右侧按钮");

    ui->Findwidget->setAutoFillBackground(true);
    ui->FindEdit->setStyleSheet("background-color: rgb(255, 255, 255, 0);"

                                "border-width:0;border-style:outset;"
                                "");
    ui->signEdit->setStyleSheet("background-color: rgb(255, 255, 255, 0);"

                                "border-width:0;border-style:outset;"
                                "");

    ui->signEdit->setText(u8"哈哈哈");
}

void MainWindw_menu::send(QList<QString> sendidList,QList<QString> sendnameList ,QList<QString> sendmessagesList ,QString sendid, QString sendname, QTcpSocket *sendtcpClient)
{
    nameList = sendnameList;
    idList = sendidList;
    messagesList = sendmessagesList;
    id = sendid;
    name = sendname;
    tcpClient = sendtcpClient;
}


MainWindow_menu::~MainWindow_menu()
{
    delete ui;
}

void MainWindow_menu::readConnect(QTcpSocket *tcpClient)
{
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

void MainWindow_menu::createUserList()
{
    for(jj=0;jj<nameList.size() ;jj++)
    {
        QToolButton * btn = new QToolButton;
        btn->setText(nameList[jj]);
        map.insert(nameList[jj],idList[jj]);
        QString pic=QString (":/Picture/head%1.jpg").arg(jj);
        btn->setIcon(QPixmap(pic));
        btn->setIconSize(QPixmap(pic).size());
        btn->setAutoRaise(true);
        btn->setStyleSheet(
                                "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));"
                                "border:1px;"
                                "border-radius:20px;"
                                "padding:2px 4px;"
                    );
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->vLayout->addWidget(btn);
        vToolBtn.push_back(btn);
    }

}

void MainWindow_menu::createClickButton()
{
    //添加点击事件
    for(int ii = 0; ii<nameList.size() ;ii++)
    {
        messagesList<<"";
    }
    for(int ii = 0; ii<nameList.size() ;ii++)
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
           Widget *chatWidget = new Widget(0,idList[ii],nameList[ii],name,messagesList[ii],tcpClient);
           chatWidget->setWindowTitle(nameList[ii]);
           chatWidget->setWindowIcon(vToolBtn[ii]->icon());
           chatWidget->show();
           //进入聊天窗口，发送给服务器id
            connect(chatWidget,&Widget::widgetClose,this,[=](){isShow[ii]=false;});//关闭聊天窗槽函数
        });
     }
    for(int i=0;i<nameList.size();i++)
    {
        isShow.push_back(false);
    }

    QMap<QString, QString>::const_iterator j;
    for( j=map.constBegin(); j!=map.constEnd(); ++j)
        qDebug() << j.key() <<"        " << j.value();
    //QMap的Key会自动按升序排列

    qDebug() << "---------------------------------";
}


   //实现窗口拖动
void MainWindow_menu::mousePressEvent(QMouseEvent *event)
{
    mouse_is_press = true;
    mouse_move_len = event->globalPos() - this->pos();
}

void MainWindow_menu::mouseMoveEvent(QMouseEvent * event)
{
    if(mouse_is_press && (event->buttons() && Qt::LeftButton)&&
            (event->globalPos()-mouse_move_len).manhattanLength()>QApplication::startDragDistance())
    {
        move(event->globalPos() - mouse_move_len);
        mouse_move_len = event->globalPos() - pos();
    }
}

void MainWindow_menu::mouseReleaseEvent(QMouseEvent * event)
{
    mouse_is_press = false;
}

   //最小化和关闭按钮
void MainWindow_menu::onMinisizeBtn()
{
    this->showMinimized();
}

void MainWindow_menu::onCloseBtn()
{
    this->close();
}

void MainWindow_menu::readMessagesend()
{

}

void MainWindow_menu::readMessages()
{

}

void MainWindow_menu::readifConnect()
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






void MainWindow_menu::on_Head1_clicked()
{
    Message *ms = new Message;
    ms->show();
}

void MainWindow_menu::on_addButton_clicked()
{
    QToolButton *btn1 = new QToolButton;
    //QString friendname = ui->addEdit->text();
    btn1->setText(u8"新群聊");
    btn1->setIcon(QPixmap(":/123.jpg"));
    btn1->setIconSize(QPixmap(":/123.jpg").size());
    btn1->setAutoRaise(true);
    btn1->setStyleSheet(
                            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));"
                            "border:1px;"
                            "border-radius:20px;"
                            "padding:2px 4px;"
                );
    btn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //btn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->vLayout2->addWidget(btn1);
    vToolBtn1.push_back(btn1);
    group++;
//点击事件
    connect(btn1,&QToolButton::clicked,this,[=]()
    {

           Widget *chatWidget = new Widget(0,u8"新群聊","name","messages",tcpClient);
           chatWidget->setWindowTitle(u8"新群聊");
           chatWidget->show();

    });
}



void MainWindow_menu::on_FindEdit_returnPressed()
{
   Message *msg=new Message;
   msg->ui->nameEdit->setText("王宝强");
   msg->ui->Head->setStyleSheet("border-image:url(:/Picture/head4.jpg);"
                                 "border-radius:30px;");
   msg->ui->IDEdit->setText("911");
   msg->show();
}

/*void MainWindow_menu::addfriend()
{
    QVector<QToolButton *>vToolBtn;
    QToolButton * btn1 = new QToolButton;
    btn1->setText("new one");
    btn1->setIcon(QPixmap(":/123.jpg"));
    btn1->setIconSize(QPixmap(":/123.jpg").size());
    btn1->setAutoRaise(true);
    btn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    vToolBtn.push_back(btn1);
}*/

void MainWindow_menu::on_addButton_2_clicked(bool checked)
{
    QVector<QToolButton *>vToolBtn;
    QToolButton *btn1 = new QToolButton;
    QString friendname = ui->addEdit->text();
    btn1->setText(friendname);
    map.insert(friendname,"jj");
    QString pic=QString (":/Picture/head%1.jpg").arg(jj);
     btn1->setIcon(QPixmap(pic));
     btn1->setIconSize(QPixmap(pic).size());
    btn1->setAutoRaise(true);
    btn1->setStyleSheet(
                            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(90,160,170), stop:0.3 rgb(60,203,205), stop:1 rgb(20,225,240));"
                            "border:1px;"
                            "border-radius:20px;"
                            "padding:2px 4px;"
                );
    btn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //btn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->vLayout->addWidget(btn1);
    vToolBtn.push_back(btn1);
    jj++;
}

void MainWindow_menu::sendmessage(QString data)
{
    send_message=data;
}

void MainWindow_menu::on_addButton_2_clicked()//FriendRequest:group_id!id|__MSGED__\0  请求添加好友或者拉好友进某个群
{
    QString text= ui->addEdit->text();
    qDebug()<<text;
    QMessageBox::information(this, u8"提示", u8"发送好友请求成功", QMessageBox::Ok);
    QString Type = QString::number((int)FriendRequest);//假设定义群id 开头第一个id号为0，
    QString sign=0;
    if(text.mid(0,1)==sign)//表示建立群聊
    {std::string send_str_q = Type.toStdString() + split_type_id + text.toStdString() +split_gid_id+ split_id_pwd + msg_end;//这有争议，暂时没法写完
    }
    else//表示添加好友
    {
        std::string send_str_q = Type.toStdString()  +split_type_gid+split_gid_id+ text.toStdString() +split_id_msg + msg_end;
        QString send_str = QString::fromStdString(send_str_q);
        qDebug()<< send_str;
        tcpClient->write(send_str.toUtf8());
    }
}




