#ifndef DIALOG_H
#define DIALOG_H
#include <QString>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString getnamepwd();
    void setnamepwd(QString &value1,QString &value2);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void send(QString b,QString c);
private:
    Ui::Dialog *ui;
    QString rname;
    QString rpassward;
};

#endif // DIALOG_H
