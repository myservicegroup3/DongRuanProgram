#ifndef __MYSQLTOOLS__
#define __MYSQLTOOLS__

#include <mysql/mysql.h>

#define HOST_NAME "localhost"
#define USER_NAME "root"
#define PASSWORD "790011"
#define DATABASES "dongruan"
#define MESSAGES "messages"
#define USERS "users"
#define RELATIONSHIPS "relationships"
#define GROUPS "groups"

int connectMysql();
void modifyMysql(const char * keys, const char * keysvalues, const char *title, const char *values, const char * tableName);
void insertMysql(const char * values_str, const char * tableName);
void deleteLineMysql(const char *keys, const char * tableName, const char * values);
char * myitoa(int d);
MYSQL mysql;


int connectMysql()
{//连接主机上的数据库
    /*分配和初始化mysql对象: mysql_init()*/
    printf("ok");
    if (NULL == mysql_init(&mysql))
    {
        printf("mysql_init(): %s\n", mysql_error(&mysql));
        return -1;
    }
    printf("ok");
    /*连接主机上的MYSQL数据库: mysql_real_connect()*/
    if (NULL == mysql_real_connect(
                &mysql,
                HOST_NAME,
                USER_NAME,
                PASSWORD,
                DATABASES,
                0,
                NULL,
                0
                 ))
    {
        printf("mysql_real_connect(): %s\n", mysql_error(&mysql));
        return -1;
    }
    printf("ok");
    printf("ok");
    return 1;
}

//向数据库某表中新增一行
//values_str格式："values(value1,value2,value3...)"
//tableName -- 表名
void insertMysql(const char * values_str, const char * tableName)
{
    char query_str[100];
    sprintf(query_str,"insert into %s %s", tableName, values_str);
    printf("%s\n",query_str);
    connectMysql();
    int ret = mysql_real_query(&mysql, query_str, strlen(query_str));
    if(0 != ret)
    {
        printf("insert ERROR: %s\n", mysql_error(&mysql));
        exit(EXIT_FAILURE);
    }
    mysql_close(&mysql);
    printf("insert successful!\n");
}

//根据某个字段值，修改某关键字的内容
//keys -- 关键字
//keysvalues -- 关键字条件
//title -- 字段名
//values -- 替换后值
//tableName -- 表名
void modifyMysql(const char * keys, const char * keysvalues, const char *title, const char *values, const char * tableName)
{
    char modify_str[300];
    printf("%s\n", keysvalues);
    sprintf(modify_str,"UPDATE %s SET %s = '%s' WHERE %s = '%s'", tableName, title, values, keys, keysvalues);
    printf("%s\n",modify_str);
    connectMysql();
    int ret = mysql_real_query(&mysql ,modify_str, strlen(modify_str));
    if(0 != ret)
    {
        printf("modify ERROR: %s\n", mysql_error(&mysql));
        exit(EXIT_FAILURE);
    }
    mysql_close(&mysql);
    printf("modify succeed\n");
}

//根据某个字段值，删除某行的内容
//keys -- 字段值
void deleteLineMysql(const char *keys, const char *tableName, const char *values)
{
    char deleteLine_str[100];
    sprintf(deleteLine_str, "delete from %s where %s = '%s'", tableName, keys, values);
    printf("%s\n",deleteLine_str);
    connectMysql();
    int ret = mysql_real_query(&mysql, deleteLine_str, strlen(deleteLine_str));
    if(0 != ret)
    {
        printf("deleteline ERROR: %s\n", mysql_error(&mysql));
        exit(EXIT_FAILURE);
    }
    mysql_close(&mysql);
}

char * myitoa(int d)
{
    char s[100];
    sprintf(s,"%d",d);
    return s;
}

#if 0
//将数据库的数据加载到*client[]中
int inputClient()
{
    connectMysql();
    int ret = mysql_query(&mysql, "SELECT id,fd,pwd,name FROM users");

    if(!ret)
    {
        MYSQL_RES * user_res = mysql_store_result(&mysql);
        if(user_res)
        {
            int rows = mysql_num_rows(user_res);
            Client::client_amount = rows;
            if(rows >= client_amount_max)
            {
                printf("CONNOT INPUT CLIENT DATA : the mysql data is too BIG!\n");
                return -1;
            }
            int rownum = 0;
            while(MYSQL_ROW row = mysql_fetch_row(user_res))
            {
                client[rownum++] = new Client(atoi(row[0]),atoi(row[1]),row[2],row[3]);
            }//while
        }//if(user_res)
        else
        {
            printf("Connect Erro:%d %s\n",mysql_errno(&mysql),mysql_error(&mysql));//返回错误代码、错误消息
                return -1;
        }
        mysql_free_result(user_res);
        mysql_close(&mysql);
    }//if(!ret)
    else
    {
        printf("Connect Erro:%d %s\n",mysql_errno(&mysql),mysql_error(&mysql));//返回错误代码、错误消息
        return -1;
    }
    printf("input Client success!\n");
    return 1;
}

//将数据库的数据加载到map里
//mode 1-relationships 2-groups 3-messages
int inputMap(int mode)
{
	connectMysql();
	int ret;
	switch (mode)
	{
	case 1:
		ret = mysql_query(&mysql, "SELECT id,link_id FROM relationships");
		break;
	case 2:
		ret = mysql_query(&mysql, "SELECT group_id,client_id FROM groups");
		break;
	case 3:
		ret = mysql_query(&mysql, "SELECT send_id,recv_id,type,info_request_no,msg,group_id FROM messages");
		break;
	
	default:
		break;
	}

    if(!ret)
    {
        MYSQL_RES * res = mysql_store_result(&mysql);
        if(res)
        {
            while(MYSQL_ROW row = mysql_fetch_row(res))
            {
				if(mode == 1)
					client_relationship[atoi(row[0])].push_back(atoi(row[1]));
				else if(mode == 2)
					Group[atoi(row[0])].push_back(atoi(row[1]));
				else
				{
                	Messages write_in(atoi(row[0]),atoi(row[1]),(Signal)atoi(row[2]),atoi(row[3]),row[4],atoi(row[5]));
                	messages_pool[atoi(row[1])].push_back(write_in);//messages_poolinsert
				}
            }//while
        }//if res
        else
        {
            printf("Connect Erro:%d %s\n",mysql_errno(&mysql),mysql_error(&mysql));//返回错误代码、错误消息
                return -1;
        }
        mysql_free_result(res);
        mysql_close(&mysql);
    }//if(!ret)
    else
    {
        printf("Connect Erro:%d %s\n",mysql_errno(&mysql),mysql_error(&mysql));//返回错误代码、错误消息
        return -1;
    }
	char result[100];
	switch (mode)
	{
	case 1:
		sprintf(result,"relationships");
		break;
	case 2:
		sprintf(result,"groups");
		break;
	case 3:
		sprintf(result,"messages");
		break;
	
	default:
		break;
	}
    printf("input %s is successd!\n", result);
    return 1;
}

#endif
#endif