#include<iostream>
#include<cstring>
#include<string>
#include<thread>
#include<mutex>
#include<cstdlib>
#include<unistd.h>
#include<condition_variable>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/time.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/un.h>
#include<atomic>

#include<map>
#include<vector>

#include "mysqltools.h"

#define LOCALIP "127.0.0.1"

const int port = 8888;
const int client_amount_max = 20;
const int listen_list_max = 5;
const int id_length_max = 8;
const int pwd_length_max = 10;
const int translate_bytes_max = 256;

//mysql
#define HOST_NAME "localhost"
#define USER_NAME "root"
#define PASSWORD "790011"
#define DATABASES "dongruan"
MYSQL *mysql;


class Client{
public:
    static int client_amount;
    //static atomic<int> client_online;
    int id;
    int fd;//不在线时此处为-1
    std::string pwd;//方便起见
    struct sockaddr_in addr;
    socklen_t addr_len;

    Client(int i,int f):id(i),fd(f){
        pwd = "";
        addr_len = sizeof(addr);
        memset(&addr, 0, sizeof(addr));
    }
    ~Client(){}

    int m_send(){}//从客户端接受数据
    int m_recv(){}//向客户端发送数据

    //int set_info(){}
};

int Client::client_amount = 0;

class Messages{
public:    
    int send_id;
    int recv_id;
    //int time;
    std::string msg;
    
    Messages(int s_id,int r_id,std::string m):send_id(s_id),recv_id(r_id),msg(m){}
    ~Messages(){}
};

enum{LogIn,SignUp,BadCLient,Normal,SomeError};

std::map<int,std::vector<Messages> > messages_pool;//前面是接收者id，后面是信息
Client* client[client_amount_max];//相当于数据库的个人信息

void SubClientThread(int client_no){//检测消息池里有没有发给自己的新消息
    int tag = Normal;
    while(1 && Normal == tag){
        while(!messages_pool[client[client_no]->fd].empty()){//不空，说明有消息没有传给客户端
            Messages* msg = &(messages_pool[client[client_no]->fd][messages_pool[client[client_no]->fd].size()-1]);
            std::string buf = msg->msg;
            std::string id = std::to_string (msg->send_id);
            id.append(1,'|');
            id += buf;
            int ret = write(client[client_no]->fd,&id,id.size());
            if( -1 == ret){
                tag =  SomeError;
                break;
            }
            
            //TODO 数据库
            char *deleteline_str;
            sprintf(deleteline_str, "%d", client[client_no]->fd);
            deleteLineMysql(mysql, deleteline_str, messages);
        
            messages_pool[client[client_no]->fd].pop_back();
        }//2.while(empty)
    }//1.while(1)
}

void ClientThread(int client_no){
    /*再个线程
     *一个负责从客户端拿数据
     *一个负责检测消息池里有没有发给自己的新消息
    */
   std::thread t([client_no](){SubClientThread(client_no);});

   fd_set fds;
   int fd = client[client_no]->fd;
   while(1){
       FD_ZERO(&fds);
       FD_SET(fd,&fds);
    
        int ret_select = select(fd+1,&fds,(fd_set *)NULL,(fd_set *)NULL,NULL);
        if(-1 == ret_select){
            close(fd);
            //停止该用户端其他线程
            return;
        }
        std::string buf;
        int ret_read = read(client[client_no]->fd,&buf,translate_bytes_max);
        if( 0 >= ret_read){
            close(fd);
            //停止该用户端其他线程
            return;
        }
        //分辨消息类型是给别人发消息还是更改某些设定,假设此处是发消息
        //从消息中解析出发送对象的id号，假设id的格式 id|消息
        int recv_id = std::stoi(buf);
        size_t erase = buf.find("|");
        buf = buf.erase(0,erase+1);
        Messages msg(client[client_no]->id,recv_id,buf);
        messages_pool[recv_id].push_back(msg);

        //TODO 数据库
        char *messages_values;
        sprintf(messages_values, "values(%d, %d, '%s')", client[client_no]->id, recv_id, buf);
        insertMysql(mysql, messages_values, "messages");
   }
}


inline void ErrorDeal(int judge){
    if(judge<0){
        printf("%s\n",strerror(errno));
        exit(-1);
    }
    
}

int LogInOrSignedUp(Client * c){
    //接收服务器发来的和客户端有关信息
    std::string buf = "id\n";
    int ret =  write(c->fd,&buf,buf.size());
    if(-1 == ret)
        return -1;
    
    
    std::string id, pwd;
    ret = read(c->fd,&id,id_length_max);
    if( -1 == ret)
        return -1;
    ret = read(c->fd,&pwd,pwd_length_max);
    if( -1 == ret)
        return -1;
    
    c->id =std::stoi(id);
    c->pwd = pwd;

    for(int i=0;i<Client::client_amount;i++){
        if(c->id == client[i]->id){
            if(c->pwd == client[i]->pwd){ //如何避免和LogInBehave一样的循环
                return LogIn;
            }
               
            else 
                return BadCLient;
        }
    }
    return SignUp;
    
}

void BadCLientBehave(Client * c){
    //密码错误
    std::string buf = "Wrong Password\n";
    int ret = write(c->fd,&buf,buf.size());
    close(c->fd);
}

int LogInBehave(Client * c){
    for(int i=0;i<Client::client_amount;i++){
        if(c->id == client[i]->id){
            //TODO 数据库
            modifyMysql(mysql, "fd", client[i]->fd, c->fd, "users");
            modifyMysql(mysql, "addr", client[i]->addr, c->addr, "users");

            client[i]->fd = c->fd;
            client[i]->addr = c->addr;
            return i;
        }
    }
}

inline int SignUpBehave(Client * c){
    Client newClient(-1,-1);
    client[Client::client_amount ] = newClient;
    *(client[Client::client_amount ] ) = *c;

    //TODO 数据库
    char *values;
    sprintf(values, "values(%d,%d,%s)", c->id, c->fd, c->pwd.c_str());
    insertMysql(mysql, values, "users");
    return ++Client::client_amount;
}

int main(void){
    //TODO 连接数据库
    mysql = connectMysql(HOST_NAME, USER_NAME, PASSWORD, DATABASES);
    //加载*client和messages_pool
    inputClient(mysql,client);
    inputMessages(mysql,messages_pool);

    //创建套接字
    int listen_fd = socket(AF_INET,SOCK_STREAM,0);
    ErrorDeal(listen_fd);

    //绑定套接字
    struct sockaddr_in  saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    inet_pton(AF_INET,LOCALIP,&saddr.sin_addr);
    int ret = bind(listen_fd,(struct sockaddr *)&saddr,sizeof(saddr));
    ErrorDeal(ret);

    //监听
    ret = listen(listen_fd,listen_list_max);
    ErrorDeal(ret);

    //开始连接
    std::thread* t[client_amount_max];
    //Client::client_online = 0;
    int thread_amount = 0;
    while(1){
        printf("connect ready!\n");
        //超过容量的处理
        if(Client::client_amount>client_amount_max){
            //do something
        }
        //获取客户端信息
        Client* temp_client = new Client(-1,-1);
        int fd = accept(listen_fd,(struct sockaddr *)&(temp_client->addr),&(temp_client->addr_len));
        ErrorDeal(fd);
        //判断登陆信息
        int connection_info = LogInOrSignedUp(temp_client);
        int tag = Normal,no = -1;
        switch(connection_info){
            case BadCLient:
                BadCLientBehave(temp_client);
                delete temp_client;
                tag = SomeError;
                break;
            case LogIn:
                no = LogInBehave(temp_client);
                delete temp_client;
                break;
            case SignUp:
                no = SignUpBehave(temp_client);
                delete temp_client;
                break;
            default:
                delete temp_client;
                temp_client = NULL;
                tag = SomeError;
                break;
        }
        if(SomeError == tag) continue;
        //有新的客户端需要IO处理
        t[thread_amount++] = new std::thread([no](){ClientThread(no);});//线程回收后怎么更改这个amount是个问题while(=NULL)?

    }//1.while(1)
    
}//main