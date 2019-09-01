#include <QMenu>
#include <QInputDialog>
#include <QAction>
#include <QDebug>
#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent) :
    QListWidget(parent)
{
}

void ListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu* popMenu = new QMenu(this);
    QAction* aAction = new QAction("添加", this);
    QAction* dAction = new QAction("删除", this);
    QAction* mAction = new QAction("修改", this);
    popMenu->addAction(aAction);

    connect(aAction, SIGNAL(triggered()),
            this, SLOT(addListWidgetItem()));
    connect(dAction, SIGNAL(triggered()),
            this, SLOT(deleteListWidgetItem()));
    connect(mAction, SIGNAL(triggered()),
            this, SLOT(modifyListWidgetItem()));

    if(this->itemAt(mapFromGlobal(QCursor::pos())) != NULL) //如果有item则添加"修改"菜单 [1]*
    {
        popMenu->addAction(dAction);
        popMenu->addAction(mAction);
    }

    popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置

    delete popMenu;
    delete aAction;
    delete dAction;
    delete mAction;
}

void ListWidget::addListWidgetItem()
{
    QString text = QInputDialog::getText(this, "输入框", "请输入学生姓名");

//    this->addItem(text);

//    QListWidgetItem* item = new QListWidgetItem(text, this);
//    this->addItem(item);


    QListWidgetItem* newItem = new QListWidgetItem;  // 不能有父窗口
    newItem->setText(text);
    this->insertItem(this->currentRow()+1, newItem);

}
//删除item
void ListWidget::deleteListWidgetItem()
{
//    QListWidgetItem* item = this->currentItem();
//    this->removeItemWidget(item);
//    delete item;

    int r = this->currentRow();//取当前item的行号
    QListWidgetItem* item = this->takeItem(r);
    this->removeItemWidget(item);//移除当前item


}
//修改item
void ListWidget::modifyListWidgetItem()
{
    QString text = QInputDialog::getText(this, "输入框", "请输入学生名称");
    this->currentItem()->setText(text);

}
