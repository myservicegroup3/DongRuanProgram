#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QUdpSocket>

namespace Ui {
class Widget;
}
enum MsgType{Msg,UsrEnter,UsrLeft};
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent,QString usrname);
    void sndMsg(MsgType type);//广播UDP消息
    void usrEnter(QString username);//处理新用户加入
    void usrLeft(QString usrname,QString time); //处理用户离开
    QString getUsr(); //获取用户名
    QString getMsg(); //获取聊天信息
    ~Widget();

signals:
    void widgetClose();

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::Widget *ui;
    QUdpSocket * udpSocket;
    qint16 port;
    QString uName;

    void ReceiveMessage();
};

#endif // WIDGET_H
