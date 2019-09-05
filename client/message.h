#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include "rules.h"
#include <QTcpSocket>
namespace Ui {
class Message;
}

class Message : public QWidget
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = 0);

    Ui::Message *ui;
     ~Message();
public slots:
    void onMinisizeBtn();
    void onCloseBtn();

    void on_addBtn_clicked(bool checked);

public:
    virtual void mousePressEvent1(QMouseEvent *event);
    virtual void mouseMoveEvent1(QMouseEvent *event);
    virtual void mouseReleaseEvent1(QMouseEvent *event);
    bool mouse_is_press1;
    QPoint mouse_move_len1;
private:
    QTcpSocket *tcpClient= new QTcpSocket;
    void readMessages();
    void readifConnect();
    int connecttype = 0;

};

#endif // MESSAGE_H
