#ifndef FILEOPERATOR_H
#define FILEOPERATOR_H
#include "user.h"
const int maxsize = 1024;
class FileOperator
{
public:
    FileOperator();

    static bool queryFile(QString name, QString pwd);
    static bool writeFile(User& user);
};

#endif // FILEOPERATOR_H
