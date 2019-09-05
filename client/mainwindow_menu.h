#ifndef MAINWINDOW_MENU_H
#define MAINWINDOW_MENU_H
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
#include <QLineEdit>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPicture>
#include <QMainWindow>
#include <QTcpSocket>
#include "rules.h"
#include "mainwindow.h"
class ListWidget;


namespace Ui {
class MainWindow_menu;
}

class MainWindow_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_menu(QList<QString> sendidList,QList<QString> sendnameList ,QList<QString> sendmessagesList ,QString sendid, QString sendname, QTcpSocket *sendtcpClient,QWidget *parent = 0);
    ~MainWindow_menu();
    QVector<bool>isShow;
    Ui::MainWindow_menu *ui;
    QList<QString>nameList;
    QList<QString>idList;
    QList<QString>messagesList;
    QString name;
    QString id;
    void createUserList();
    void sendmessage(QString data);
    void createClickButton();
    void readConnect(QTcpSocket *tcpClient);
    QString send_message;
    void send(QList<QString> sendidList,QList<QString> sendnameList ,QList<QString> sendmessagesList ,QString sendid, QString sendname, QTcpSocket *sendtcpClient);


private slots:
    void onMinisizeBtn();
    void onCloseBtn();
    void readMessages();
    void readifConnect();
    void on_Head1_clicked();
    void on_addButton_clicked();
    void on_addButton_2_clicked(bool checked);
    void on_FindEdit_returnPressed();
    void readMessagesend();

    void on_addButton_2_clicked();

private:
    QTcpSocket *tcpClient;
    int connecttype = 0;
    int jj;//好友数量
    int group=0;//群数量
    QMap<QString,QString>map;
    QVector<QToolButton *>vToolBtn;
    QVector<QToolButton *>vToolBtn1;

protected:
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    bool mouse_is_press;
    QPoint mouse_move_len;

};

#endif // MAINWINDOW_MENU_H
