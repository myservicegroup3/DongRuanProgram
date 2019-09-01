#include <QFile>
#include <QDataStream>
#include "fileoperator.h"
//本用文件储存信息，已改数据库存储，该类已废弃
FileOperator::FileOperator()
{
}

bool FileOperator::queryFile(QString name, QString pwd)
{
    User user;
    QFile file("./user.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
//    QByteArray ba = file.readLine(1024);
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_2);
    while(!in.atEnd())
    {
        in >> user.name_ >> user.pwd_ >> user.sex_ >> user.birthday_ << user.major_;
        if (name == user.name() && pwd == user.pwd())
        {
            return true;
        }
    }
    return false;
}

bool FileOperator::writeFile(User &user)
{
    QFile file("./user.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }
//    QByteArray ba = file.readLine(1024);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_2);

    out << user.name() /*<< "\t"*/
        << user.pwd() /*<< "\t"*/
        << user.sex() /*<< "\t"*/
        << user.birthday() /*<< "\t"*/
        << user.major()/*<< "\n"*/;

    return true;
}
