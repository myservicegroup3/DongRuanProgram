#ifndef LISTWIDGET_H
#define LISTWIDGET_H
#include <QListWidget>
class ListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = 0);

protected:
    void contextMenuEvent ( QContextMenuEvent * event );

public slots:
    void addListWidgetItem();
    void deleteListWidgetItem();
    void modifyListWidgetItem();

};

#endif // LISTWIDGET_H
