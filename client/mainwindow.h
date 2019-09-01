#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    QString getNamepwd();
signals:
    //登录成功后发射信号
    void sendUsrname(QString name);


private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();
    void receive(QString suername,QString passward);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
