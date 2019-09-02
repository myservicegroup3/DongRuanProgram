#ifndef __MYSQLTOOLS__
#define __MYSQLTOOLS__

#include <mysql/mysql.h>


MYSQL *connectMysql(char *hostName, char *userName, char *password, char *databases);
void modifyMysql(MYSQL *mysql, char * keys, char *preValues, char *values, char * tableName);
void insertMysql(MYSQL *mysql, char * values_str, char * tableName);
void deleteLineMysql(MYSQL *mysql, char *keys, char * tableName);
void inputClient(MYSQL *mysql, Client *&client[]);
void inputMessages(MYSQL *mysql, std::map<int, std::vector<Messages>> &messages_pool);


MYSQL *connectMysql(char *hostName, char *userName, char *password, char *databases)
{//连接主机上的数据库
    /*分配和初始化mysql对象: mysql_init()*/
    MYSQL *mysql;
    if (NULL == mysql_init(mysql))     
    {
        printf("mysql_init(): %s\n", mysql_error(mysql));
        exit(EXIT_FAILURE);
    }
    /*连接主机上的MYSQL数据库: mysql_real_connect()*/
    if (NULL == mysql_real_connect(
                mysql,
                hostName,
                userName,
                password,
                databases,
                0,
                NULL,
                0
                 ))
    {
        printf("mysql_real_connect(): %s\n", mysql_error(mysql));
        exit(EXIT_FAILURE);
    }
    printf("Connect to MySql successful!\n");
    return mysql;
}

//*client[] 为结果参数
void inputClient(MYSQL *mysql, Client *&client[])//将数据库的数据加载到*client中
{
    int ret = mysql_query(mysql, "SELECT id,pwd,fd FROM users");
    if(!ret)
    {
        MYSQL_RES * user_res = mysql_store_result(mysql);
        if(user_res)
        {
            int rows = mysql_num_rows(user_res);
            Client::client_amount = rows;
            int rownum = 0;
            while(MYSQL_ROW row = mysql_fetch_row(user_res))
            {
                for(int i = 0; i<3; i++)
                {
                    switch (i)
                    {
                    case 0:
                        client[rownum]->id = row[0];
                        break;
                    case 1:
                        client[rownum]->fd = row[1];
                        break;
                    case 2:
                        client[rownum]->pwd = row[2];
                        break;
                    
                    default:
                        break;
                    }//switch
                }//for
                rownum++;
            }//while
        }//if(user_res)
        if(mysql_errno(user_res))
        {
            printf("Connect Erro:%d %s\n",mysql_errno(mysql),mysql_error(mysql));//返回错误代码、错误消息
                return -2;
        }
        mysql_free_result(mysql);
    }//if(!ret)
    else
    {
        printf("Connect Erro:%d %s\n",mysql_errno(mysql),mysql_error(mysql));//返回错误代码、错误消息
        return -3;
    }
}

//向消息池中写入数据库数据
//messages_pool 为结果参数
void inputMessages(MYSQL *mysql, std::map<int, std::vector<Messages>> &messages_pool)
{
    int ret = mysql_query(mysql, "SELECT recv_id,send_id,msg FROM messages");
    if(!ret)
    {
        MYSQL_RES * messages_res = mysql_store_result(mysql);
        if(messages_res)
        {
            int rows = mysql_num_rows(messages_res);
            while(MYSQL_ROW row = mysql_fetch_row(messages_res))
            {
                Messages msg(row[1],row[0],row[2]);
                messages_pool[row[0]].push_back(msg);
            }
        }
        if(mysql_errno(messages_res))
        {
            printf("Connect Erro:%d %s\n",mysql_errno(mysql),mysql_error(mysql));//返回错误代码、错误消息
                return -4;
        }
        mysql_free_result(mysql);
    }
    else
    {
        printf("Connect Erro:%d %s\n",mysql_errno(mysql),mysql_error(mysql));//返回错误代码、错误消息
        return -3;
    }
}

//向数据库某表中新增一行
//values_str格式："values(value1,value2,value3...)"
//tableName -- 表名
void insertMysql(MYSQL *mysql, char * values_str, char * tableName)
{
    char * query_str;
    sprintf(query_str, "insert into %s %s", values_str, tableName);
    int ret = mysql_real_query(mysql, query_str, strlen(query_str));
    if(0 != ret)
    {
        printf("insert ERROR: %s\n", mysql_error(mysql));
        exit(EXIT_FAILURE);
    }
}

//根据某个字段值，修改某关键字的内容
//keys -- 字段名
//preValues -- 替换前关键字
//values -- 替换后关键字
void modifyMysql(MYSQL *mysql, char * keys, char *preValues, char *values, char * tableName)
{
    char * modify_str;
    sprintf(modify_str,"UPDATE %s SET %s = REPLACE(%s, %s, %s)", tableName, keys, keys, preValues, values);
    int ret = mysql_real_query(mysql, modify_str, strlen(modify_str));
    if(0 != ret)
    {
        printf("modify ERROR: %s\n", mysql_error(mysql));
        exit(EXIT_FAILURE);
    }
}

//根据某个字段值，删除某行的内容
//keys -- 字段值
void deleteLineMysql(MYSQL *mysql, char *keys, char *tableName)
{
    char * deleteLine_str;
    sprintf(deleteLineMysql, "delete from %s where name = '%s'", tableName, keys);
    int ret = mysql_real_query(mysql, deleteLine_str, strlen(deleteLine_str));
    if(0 != ret)
    {
        printf("deleteline ERROR: %s\n", mysql_error(mysql));
        exit(EXIT_FAILURE);
    }
}
#endif