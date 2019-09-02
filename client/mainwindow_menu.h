#ifndef MAINWINDOW_MENU_H
#define MAINWINDOW_MENU_H

#include <QMainWindow>
class ListWidget;


namespace Ui {
class MainWindow_menu;
}

class MainWindow_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_menu(QWidget *parent = 0);
    ~MainWindow_menu();
    QVector<bool>isShow;
private slots:
    //登录成功后接收用户名
    //void recUsrname(QString name);
    void onMinisizeBtn();
    void onCloseBtn();
    void on_FindButton_clicked(bool checked);
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow_menu *ui;


};

#endif // MAINWINDOW_MENU_H



