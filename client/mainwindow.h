#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDialog>
#include <QList>
#include "rules.h"
#include "mainwindow_menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    char *myitoa(int a);
    ~MainWindow();
    MainWindow_menu *stablemw;

signals:
    void sendmw(QList<QString> idList,QList<QString> nameList ,QString id, QString name);


private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void receive(QString id,QString passward);
    void readMessages();
    void readifConnect();
    void QuestionWidget(QString nid, QString gid);

private:
    Ui::MainWindow *ui;
    int connecttype = 0;
    QTcpSocket *tcpClient = new QTcpSocket(this);
    QList<QString> idList;
    QList<QString> nameList;
    QList<QString> messagesList;

};

#endif // MAINWINDOW_H
