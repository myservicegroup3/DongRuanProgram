#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QToolButton>
#include <QMessageBox>
#include <QDateTime>
#include <QPushButton>
#include <QColorDialog>
#include <QFileDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringList>
#include <QIcon>
#include <QList>
#include <QLineEdit>
#include <QTcpSocket>
#include <QString>
#include "rules.h"
#include "mainwindow_menu.h"
#include <QTcpSocket>
namespace Ui {
class Widget;
}
enum MsgType{Msg,UsrEnter,UsrLeft};
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent,QString id,QString name,QString myname,QString messages,QTcpSocket *sendtcpclient);
    void sndMsg(MsgType type);//广播UDP消息
    void usrEnter(QString username);//处理新用户加入
    void usrLeft(QString usrname,QString time); //处理用户离开
    QString getUsr(); //获取用户名
    QString getMsg(); //获取聊天信息
    void receivedata(QString data);
    QString now_id;
    QString now_name;
    QString now_messages;
    QString now_myname;

    ~Widget();

signals:
    void widgetClose();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_sendBtn_clicked();
    void readMessages();

private:
    Ui::Widget *ui;
    qint16 port;
    QString uName;
    QTcpSocket *tcpClient;
    void readifConnect();
    int connecttype = 0;
    QString add_id;
    QString add_groupid;
    QString zadd_groupid;
    QString zadd_id;
    QString  rgroup_id;
    QList<QString> idList;
    QList<QString> nameList;





};

#endif // WIDGET_H
