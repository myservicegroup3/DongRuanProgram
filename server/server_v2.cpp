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

#define LOCALIP "127.0.0.1"

const int port = 8888;
const int client_amount_max = 20;
const int listen_list_max = 5;
const int id_length_max = 8;
const int pwd_length_max = 10;
const int translate_bytes_max = 256;
//未完成： 由于不知道每次传过来多少信息，建议把每条信息最后加上一个结束符
//还没有添加锁！！！！

enum{LogIn,SignUp,BadCLient,Normal,SomeError,
    FriendRequest,GroupInvitation,NormalMessage,RequestAgree,ChangeSet};

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
    int type;
    //int time;
    std::string msg;
    
    Messages(int s_id,int r_id,std::string m):send_id(s_id),recv_id(r_id),msg(m){
        type = NormalMessage;
    }
    ~Messages(){}
};


std::map<int,std::vector<Messages> > messages_pool;//前面是接收者id，后面是信息
std::map<int,std::vector<int> > client_relationship; //关系表
Client* client[client_amount_max];//相当于数据库的个人信息


void SubClientThread(int client_no){//检测消息池里有没有发给自己的新消息
    int tag = Normal;
    while(1 && Normal == tag){
        int m_id = client[client_no]->id;
        while(!messages_pool[m_id].empty()){//不空，说明有消息没有传给客户端
            Messages* msg = &(messages_pool[m_id][messages_pool[m_id].size()-1]);
            //拿到消息后判断关系类型，比如好友请求，别人同意了你的好友请求，或者别人发给你的消息,或者服务器更新的个人信息
            //
            std::string sgnl;
            if(FriendRequest == msg->type){
                //不是自己好友
                //向客户端发送添加好友信号
                //在接收客户端消息的线程里再去判断
                sgnl = std::to_string(FriendRequest);
                int ret = write(client[client_no]->fd,&sgnl,sgnl.size());
                if( -1 == ret){
                    tag =  SomeError;
                    break;
                }
            }//if
            else{ //直接发送信息
                sgnl = std::to_string(NormalMessage);
                int ret = write(client[client_no]->fd,&sgnl,sgnl.size());
                if( -1 == ret){
                    tag =  SomeError;
                    break;
                }
                std::string buf = msg->msg;
                std::string id = std::to_string (msg->send_id);
                id.append(1,'|');
                id += buf;
                

                //对同一个文件描述符，一个进行写，一个进行读，同时进行需要加锁嘛？
                int ret = write(client[client_no]->fd,&id,id.size());
                if( -1 == ret){
                    tag =  SomeError;
                    break;
                }
            }
            //TODO 数据库

            messages_pool[m_id].pop_back();
        }//2.while(empty)
    }//1.while(1 && tag)

}

void ClientThread(int client_no){
    /*开个线程
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
        //分辨消息类型是给别人发消息还是更改某些设定还是一些系统消息
        //所以客户端需要告诉服务器消息类型
        /**
         * 比如获得/更改个人信息
         * 拉取某个用户的信息
         * 比如同意某人的好友请求
        */
        //同意好友请求
        int sgnl = std::stoi(buf);
        switch(sgnl){
            case RequestAgree:
                break;
            case 
        }

        //给别人发消息
        //从消息中解析出发送对象的id号，假设id的格式 id|消息
        int m_id = client[client_no]->id;
        int recv_id = std::stoi(buf);
        size_t erase = buf.find("|");
        buf = buf.erase(0,erase+1);
        Messages msg(client[client_no]->id,recv_id,buf);

        //从关系表里判断是否消息接收者是否为好友，不是的话把消息存储为系统消息。
        //如果是好友请求的话，消息不是常规的字符串，可以设置为一些易于存储的东西
        if(client_relationship[m_id].find(client_relationship[m_id].begin(),client_relationship[m_id].end(),recv_id) != client_relationship[m_id].end() ){
            msg->type = FriendRequest;
        }//if
        //检测是否为群聊申请
        /**
         * if(judge something)
         * msg->type = GroupInvitation;
         */
        messages_pool[recv_id].push_back(msg);

        //TODO 数据库
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

    //根据传来的信号判断是登陆还是注册
    char sgn = -1;
    int ret = read(c->fd,&sgn, sizeof(char));
    if(-1 == ret)
        return -1;
    //注册
    if(sgn == '0'){
        return SignUp;
    }
    

    std::string buf = "id\n";
    ret =  read(c->fd,&buf,buf.size());
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

    
}

void BadCLientBehave(Client * c){
    //密码错误

    //告诉客户端
    std::string buf = "Wrong Password";
    //char buf = '0';
    int ret = write(c->fd,&buf,buf.size());
    close(c->fd);
}

int LogInBehave(Client * c){
    //告诉客户端
    char buf = '1';
    int ret = write(c->fd,&buf,sizeof(buf));


    for(int i=0;i<Client::client_amount;i++){
        if(c->id == client[i]->id){
            //TODO 数据库

            client[i]->fd = c->fd;
            client[i]->addr = c->addr;
            return i;
        }
    }
}//
inline int SignUpBehave(Client * c){
    client[Client::client_amount ] = new Client(-1,-1);
    *(client[Client::client_amount ] ) = *c;

    //TODO 数据库

    return ++Client::client_amount;
}


int main(void){
    //TODO 数据库
    
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
    std::thread t[client_amount_max];
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
        //向客户端发送确认信息
        std::string buf = "connected!";
        write(fd,&buf,buf.size());
        //判断登陆信息
        int connection_info = LogInOrSignedUp(temp_client);
        int tag = Normal,no = -1;
        switch(connection_info){
            case BadCLient:
                printf("wrong password\n");
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
                printf("client closeed before detection\n");
                close(temp_client->fd);
                delete temp_client;
                temp_client = NULL;
                tag = SomeError;
                break;
        }
        if(SomeError == tag) continue;
        std::string buf = "Log in!";
        write(fd,&buf,buf.size());

        //有新的客户端需要IO处理
        t[thread_amount++] = std::thread([no](){ClientThread(no);});//线程回收后怎么更改这个amount是个问题while(=NULL)?

    }//1.while(1)
    
}//main