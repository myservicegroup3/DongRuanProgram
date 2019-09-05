#ifndef CREATEGROUP_H
#define CREATEGROUP_H

#include <QDialog>
#include "widget.h"

namespace Ui {
class creategroup;
}

class creategroup : public QDialog
{
    Q_OBJECT

public:
    explicit creategroup(QWidget *parent = 0);
    ~creategroup();

private slots:

    //void condButtonPressed();
    void on_pushButton_3_clicked(bool checked);

private:
    Ui::creategroup *ui;
    Widget *group;
};

#endif // CREATEGROUP_H
