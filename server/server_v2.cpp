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
#include<algorithm>
#include<random>

#include "mysqltools.h"

#define LOCALIP "192.168.2.233"

const int port = 8888;
const int client_amount_max = 20;
const int listen_list_max = 5;
const int id_length_max = 8;
const int pwd_length_max = 10;
const int translate_bytes_max = 512;

const std::string split_type_gid = ":";
const std::string split_gid_id = "!";
const std::string split_id_msg = "|";
const std::string msg_end = "__MSGED__\0";
const std::string split_type_id = "#";
const std::string split_id_pwd = "$";
const std::string split_id_name = "-";
const std::string split_client_client = "+";
const std::string split_key_change = ";";
/**
 * 未完成： 
 * 如何把密码加密传输
 * 传输图片
 * 
 /

/**
 * 设定消息类型为：
 * 如果是发给客户端的：   信息类型::群号!!消息发送者id||消息内容
 * 如果是发给服务器的：   信息类型::群号!!消息接收者id||消息内容
 *						单聊时群号默认为空，系统消息id、群号和消息内容都为空
*/


enum Signal{LogIn,SignUp,BadCLient,Normal,SomeError,UsrInfo,
	ConnectSuccess,LogInSuccess, WrongPassword,//登陆消息
    FriendRequest,NormalMessage,GroupMessage,GroupCreate,GroupCreateSuccess,
    RequestAgree,RequestRefuse,ChangeSet,GetInfo,//用户消息类型
	//系统消息类型
    ChangeSetFailure,ChangeSetSuccess,GetInfoSuccess,GetInfoFailure,
};

/*客户端收到的：    RequestAgree::!!send_id||send_id的昵称__MSGEND__\x00
				   RequestRefuse::!!||__MSGEND__\x00
	
*/

class Client {
public:
	static int client_amount;
	static int id_squence;
	//static atomic<int> client_online;
	int id;
	int fd;//不在线时此处为-1
	std::string pwd;//方便起见
	std::string name;
	struct sockaddr_in addr;
	socklen_t addr_len;

	Client(int i, int f,std::string p,std::string n) 
		:id(i), fd(f),pwd(p),name(n) {
	}
	~Client() {}

	int m_send() {}//从客户端接受数据
	int m_recv() {}//向客户端发送数据

	//int set_info(){}
};

int Client::client_amount = 0;
int Client::id_squence = 29341;

class Messages {
public:
	int send_id;
	int group_id;
	int info_request_no;//客户端想要获取的信息在client数组里的下标，以便传输数据。
	int recv_id;
	Signal type;
	//int time;
	std::string msg;

	Messages(int s_id, int r_id, Signal t,int i_r_n = -1, std::string m = "",int g_id = -1)
		:send_id(s_id), recv_id(r_id), msg(m), type(t), info_request_no(i_r_n),group_id(g_id){
	}
	~Messages() {}
};



std::map<int,std::vector<Messages> > messages_pool;//前面是接收者id，后面是信息
std::map<int,std::vector<int> > client_relationship; //关系表
std::map<int, std::vector<int> > Group;
Client* client[client_amount_max];//相当于数据库的个人信息

typedef struct {
	struct sockaddr_in addr;
	socklen_t addr_len;
} Client_socket;

std::map<int,std::vector<Client_socket> > client_socket ;
std::mutex m_mutex;


inline void ErrorDeal(int judge) {
	if (judge < 0) {
		printf("%s\n", strerror(errno));
		exit(-1);
	}
}

inline int MRead(std::string & buf, int fd) {
	int al_ret = 0, ret = 0;
	char rd[translate_bytes_max] = { 0 };
	buf.clear();
	while (buf.find(msg_end) == std::string::npos) {
		ret = read(fd, rd, translate_bytes_max);
		if (-1 == ret)
			return -1;
		al_ret += ret;
		buf += rd;
	}
	return al_ret;
}

inline int MWrite(int fd, int signal, int q_id, int id, std::string msg) {
	std::string buf(std::to_string(signal));
	buf += split_type_gid;
	if (-1 != q_id)
		buf += std::to_string(q_id);
	buf += split_gid_id;
	if (-1 != id)
		buf += std::to_string(id);
	buf += split_id_msg;
	if (msg.size())
		buf += msg;
	buf += msg_end;

	int al_ret = 0, ret = 0;
	char wt[translate_bytes_max];
	strcpy(wt,buf.c_str());
	//wt[buf.size() + 1] = '\x00';
	while (al_ret < strlen(wt)) {
		ret = write(fd, wt + al_ret, strlen(wt));
		if (-1 == ret)
			return -1;
		al_ret += ret;
	}
	return 0;
}



void SubClientThread(int client_no) {//检测消息池里有没有发给自己的新消息
	//就是给客户端发消息的线程
	int m_id = client[client_no]->id;
	int fd = client[client_no]->fd;
	Signal tag = Normal;
	while (1 && Normal == tag) {
		while (!messages_pool[m_id].empty() && Normal == tag) {//不空，说明有消息没有传给客户端
			Messages* msg = &(messages_pool[m_id][messages_pool[m_id].size() - 1]);
			//拿到消息后判断关系类型，比如好友请求，别人同意了你的好友请求
			//或者别人发给你的消息
			//或者服务器向客户端发送的个人信息
			//
			Signal sgnl = msg->type;
			int send_id = msg->send_id;//谁发的这个消息
			int group_id = msg->group_id;
			int ret;
			switch (sgnl) {
			case NormalMessage:
				break;
			case FriendRequest://别人发给你的好友请求或拉你进群请求
				/**
				 * 判断是否已经关系表中是否已有好友关系
				 * 判断是否已经在群里
				 * 如果已有，向消息池写入RequestAgree的消息给send_id
				*/
				msg->msg = client[msg->info_request_no]->name;
				if (count(client_relationship[m_id].begin(), client_relationship[m_id].end(), send_id)
					|| (-1 != group_id && !count(Group[group_id].begin(), Group[group_id].end(), send_id))) {
					Messages write_in(msg->recv_id, m_id, RequestAgree, -1, "", group_id);
					{
						std::lock_guard<std::mutex> lock(m_mutex);
						messages_pool[msg->recv_id].insert(messages_pool[msg->recv_id].begin(), write_in);
                        //TODO2 数据库新增一条指令
                        char values[100];
                        sprintf(values,"values(%d,%d,%d,%d,%s,%d)",msg->recv_id, m_id, RequestAgree, -1, "", group_id);
                        insertMysql(values, MESSAGES);
					}
				}
				break;
			case RequestAgree://别人同意了你的好友请求或者是一个拉他进群的请求，或者是建群成功
				/**
				 * 服务器向客户端发送消息告诉说，你请求的那个人同意了，然后把他的昵称发给你
				*/
				if (group_id != -1) msg->msg = "群";
				else msg->msg = client[msg->info_request_no]->name;
				break;
			case RequestRefuse:
				//服务器告诉客户端，别人不同意
				break;
			case ChangeSetSuccess://更改某些设置成功
				break;
			case ChangeSetFailure://更改设置失败
				break;
			case GetInfoSuccess://获取指定用户的信息成功->目前只返回昵称//获取群里成员信息成功->返回 id:name..id:name..格式的msg
				if(-1 == group_id)
					msg->msg = client[msg->info_request_no]->name;
				break;
			case GetInfoFailure:
				break;
			default:
				printf("receive unknown_type message from server\n");
				tag = SomeError;
				break;
			}
			if (SomeError != tag) {
				ret = MWrite(fd, sgnl, group_id, send_id, msg->msg);
				if (-1 == ret)
					tag = SomeError;
			}
			
			{
				std::lock_guard<std::mutex> lock(m_mutex);
				messages_pool[m_id].pop_back();
                deleteLineMysql(myitoa(m_id), MESSAGES);//TODO2 删除m_id指定的数据库行
			}
			
		}//2.while(empty)
	}//1.while(1 && tag)

	return;
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
			client_socket[fd].clear();
			client[client_no]->fd = -1;
            modifyMysql("id", myitoa(client[client_no]->id), "fd", "-1", USERS);//TODO 修改数据库的值
			if (t.joinable()) t.join();
            return;
        }
		std::string buf;
		int ret = MRead(buf, fd);
		if (-1 == ret) {
			client_socket[fd].clear();
			client[client_no]->fd = -1;
            modifyMysql("id", myitoa(client[client_no]->id), "fd", "-1", USERS);//TODO 修改数据库的值
			close(fd);
			if (t.joinable()) t.join();
			return;
		}

       //分辨消息类型

		int npos_type_gid = buf.find(split_type_gid), npos_gid_id = buf.find(split_gid_id);
		int npos_id_msg = buf.find(split_id_msg),npos_msg_end = buf.find(msg_end);
		std::string msg = buf.substr(npos_id_msg, npos_msg_end);
		int npos_id_key = 0, npos_key_change = 0;
		std::string change, key;
		Signal type;
		try { type = (Signal)std::stoi(buf.substr(0, npos_type_gid)); }
		catch (...) { type = SomeError; }
		int send_id = client[client_no]->id;

		int recv_id = 0, group_id = 0;
		try {recv_id = std::stoi(buf.substr(npos_gid_id, npos_id_msg));	}
		catch(...){recv_id = -1;}

		try {group_id = std::stoi(buf.substr(npos_gid_id, npos_id_msg));}
		catch (...) {	group_id = -1;}
		
		

        switch(type){
            case RequestAgree://同意别人的好友请求
				//同意群请求,如果这个群聊id不为-1，那么就是要一个同意加群的消息
				if (group_id != -1 && !count(Group[group_id].begin(), Group[group_id].end(),client_no)) {
					Group[group_id].push_back(client_no);
				}
				//通知别人,加入消息池
				{
					std::lock_guard<std::mutex> lock(m_mutex);
					//首先给自己发一个消息来获取id和名字
					messages_pool[send_id].push_back(Messages(recv_id, send_id, RequestAgree, client_no, "", group_id));//告诉对方这个client_no来获得其他资料
					messages_pool[recv_id].push_back(Messages(send_id, recv_id, RequestAgree,client_no,"",group_id));//告诉对方这个client_no来获得其他资料
                    //TODO2 messages新增数据
                    char values1[100], values2[100];
                    sprintf(values1,"values(%d,%d,%d,%d,%s,%d)",recv_id, send_id, RequestAgree, client_no, "", group_id);
                    sprintf(values2,"values(%d,%d,%d,%d,%s,%d)",send_id, recv_id, RequestAgree, client_no, "", group_id);
                    insertMysql(values1, MESSAGES);
                    insertMysql(values2, MESSAGES);

					client_relationship[send_id].push_back(recv_id);
					client_relationship[recv_id].push_back(send_id);
				}
                break;

			case RequestRefuse://拒绝别人的好友请求
				{
					std::lock_guard<std::mutex> lock(m_mutex);
					messages_pool[recv_id].push_back(Messages(send_id, recv_id, RequestRefuse,-1,"",group_id));//告诉对方这个client_no来获得其他资料
                    //TODO2 messages新增数据
                    char values[100];
                    sprintf(values,"values(%d,%d,%d,%d,%s,%d)",send_id, recv_id, RequestAgree, -1, "", group_id);
                    insertMysql(values, MESSAGES);
                }
				break;
            case FriendRequest://请求添加好友或添加好友进群
				//往消息池写消息
				{
					std::lock_guard<std::mutex> lock(m_mutex);
					messages_pool[recv_id].push_back(Messages(send_id, recv_id, FriendRequest,client_no,"",group_id));
                    //TODO2 messages新增数据
                    char values[100];
                    sprintf(values,"values(%d,%d,%d,%d,%s,%d)",send_id, recv_id, FriendRequest, -1, "", group_id);
                    insertMysql(values, MESSAGES);
				}
                break;
            case GroupCreate://请求创建群
				/**
				* 服务器直接返回一个创建成功的信号和一个群聊id
				* 然后把这个群聊id对应的数组里加入用户的client_no
				*/
				group_id = Client::id_squence++; 
				{
					std::lock_guard<std::mutex> lock(m_mutex);
					messages_pool[send_id].push_back(Messages(send_id, send_id,GroupCreateSuccess, client_no, "", group_id));//告诉我这个群创建好了
                    //TODO2 messages新增数据
                    char values[100];
                    sprintf(values,"values(%d,%d,%d,%d,%s,%d)",send_id, send_id,GroupCreateSuccess, client_no, "", group_id);
                    insertMysql(values, MESSAGES);
				}
				Group[group_id].push_back(client_no);
				
				break;
            case GroupMessage://发送群消息
				{
					std::lock_guard<std::mutex> lock(m_mutex);
					for (int i = 0; i < Group[group_id].size(); i++) {
						recv_id = client[Group[group_id][i]]->id;
						messages_pool[recv_id].push_back(Messages(send_id, recv_id, NormalMessage, -1, msg,group_id));
                        //TODO2 messages新增数据
                        char values[100];
                        sprintf(values,"values(%d,%d,%d,%d,%s,%d)",send_id, recv_id, NormalMessage, -1, msg.c_str(), group_id);
                        insertMysql(values, MESSAGES);
					}
				}
                break;//这两个好像也可以合并
			case NormalMessage://发送单聊消息
				//往消息池写消息
				{
					std::lock_guard<std::mutex> lock(m_mutex);
					messages_pool[recv_id].push_back(Messages(send_id, recv_id, NormalMessage,-1,msg));
                    //TODO2 messages新增数据
                    char values[100];
                    sprintf(values,"values(%d,%d,%d,%d,%s,%d)",send_id, recv_id, NormalMessage,-1, msg.c_str(), -1);
                    insertMysql(values, MESSAGES);
				}
                break;
            case ChangeSet://更改某些设置
				npos_id_key = buf.find(split_id_msg);
				npos_key_change = buf.find(split_key_change);
				change = buf.substr(npos_key_change, npos_msg_end);
				key = buf.substr(npos_id_key, npos_key_change);
				if (key == "name") {
					client[client_no]->name = change;
                    modifyMysql("id", myitoa(client[client_no]->id), "name", change.c_str(), USERS);//TODO 修改数据库的值
				}
				else if (key == "pwd") {
					client[client_no]->pwd = change;
                    modifyMysql("id", myitoa(client[client_no]->id), "pwd", change.c_str(), USERS);//TODO 修改数据库的值
					change.clear();
				}
				else {
					messages_pool[send_id].push_back(Messages(recv_id, send_id, ChangeSetFailure));
                    //TODO2 messages新增数据
                    char values[100];
                    sprintf(values,"values(%d,%d,%d,%d,%s,%d)",recv_id, send_id, ChangeSetFailure, -1, "", -1);
                    insertMysql(values, MESSAGES);
					break;
				}
				messages_pool[send_id].push_back(Messages(recv_id, send_id, ChangeSetSuccess,-1,key+split_key_change+change));
                //TODO2 messages新增数据
                char values[100];
                sprintf(values,"values(%d,%d,%d,%d,%s,%d)",recv_id, send_id, ChangeSetSuccess,-1,(key+split_key_change+change).c_str(),-1);
                insertMysql(values, MESSAGES);
                break;
			case GetInfo://请求获取某个用户或某个群的资料
				if (-1 == group_id) {
					for (int i = 0; i < Client::client_amount; i++) {
						if (recv_id == client[i]->id) {
							std::lock_guard<std::mutex> lock(m_mutex);
							messages_pool[recv_id].push_back(Messages(recv_id,send_id, GetInfoSuccess, i));
                            //TODO2 messages新增数据
                            char values[100];
                            sprintf(values,"values(%d,%d,%d,%d,%s,%d)",recv_id, send_id, GetInfoSuccess, i,"",-1);
                            insertMysql(values, MESSAGES);
							//告诉对方这个client_no来获得其他资料
							break;
						}
					}
				}
				else {
					if (Group.count(group_id))
					{
						msg.clear();
						for (int i = 0 ; i < Group[group_id].size(); i++) {
							msg += std::to_string(client[Group[group_id][i]]->id);
							msg += split_id_name;
							msg += client[Group[group_id][i]]->name;
							msg += split_client_client;

						}//把群里的人的id和name给客户端
						std::lock_guard<std::mutex> lock(m_mutex);
						messages_pool[send_id].push_back(Messages(recv_id, send_id, GetInfoSuccess,-1,msg,group_id));
                        //TODO2 messages新增数据
                        char values[100];
                        sprintf(values,"values(%d,%d,%d,%d,%s,%d)",recv_id, send_id, GetInfoSuccess,-1,msg.c_str(),group_id);
                        insertMysql(values, MESSAGES);
						break;
					}
				}
				{
					std::lock_guard<std::mutex> lock(m_mutex);
					messages_pool[send_id].push_back(Messages(recv_id, send_id, GetInfoFailure,-1,"",group_id));
                    //TODO2 messages新增数据
                    char values[100];
                    sprintf(values,"values(%d,%d,%d,%d,%s,%d)",recv_id, send_id, GetInfoFailure,-1,"",group_id);
                    insertMysql(values, MESSAGES);
				}

				break;
			default:
				printf("receive unknown_type message\n");
				break;
        }//switch


   }//while(1)

}



int LogInOrSignedUp(int fd){
    //接收服务器发来的和客户端有关信息
	std::string sgn;
	int len = MRead(sgn, fd);
    printf("%d,%s\n",sgn.length(),sgn.c_str());
	if (len == -1)
		return SomeError;

	int npos_type_id = sgn.find(split_type_id), npos_id_pwd = sgn.find(split_id_pwd),npos_pwd_end = sgn.find(msg_end);
	int id;
	Signal type;
	try { type = (Signal)std::stoi(sgn.substr(0, npos_type_id)); }
	catch (...) { type = SomeError; }
	//if (sgn.substr(0, npos_type_id).size())
	//	type = (Signal) std::stoi(sgn.substr(0, npos_type_id));
	//else type = SomeError;

	std::string pwd,name;
	int ret;

	switch (type) {
	case SignUp:
		printf("signUp\n");
		client[Client::client_amount] = new Client(Client::id_squence,fd,sgn.substr(npos_id_pwd, npos_pwd_end),sgn.substr(npos_type_id, npos_id_pwd));
        //TODO 数据库新增数据
        char signUpValues[100];
        sprintf(signUpValues,"values(%d,%d,%s,%s)",Client::id_squence,fd,sgn.substr(npos_id_pwd, npos_pwd_end).c_str(),sgn.substr(npos_type_id, npos_id_pwd).c_str());
        insertMysql(signUpValues, USERS);

		ret = MWrite(fd, LogInSuccess, -1, -1, std::to_string(Client::client_amount++));
		if (-1 == ret) 
			return SomeError;
		return LogInSuccess;
	case LogIn:
		printf("Login\n");
		try{id = stoi(sgn.substr(npos_type_id, npos_id_pwd));}
		catch (...) { printf("Login ERROR!,%d,%s\n",client[0]->id,client[0]->pwd.c_str()); return SomeError; }
		
		pwd = sgn.substr(npos_id_pwd, sgn.size());
		for (int i = 0; i < Client::client_amount; i++) {
			if (id == client[i]->id) {
				if (pwd == client[i]->pwd) {
					client[i]->fd = fd;
                    modifyMysql("id", myitoa(client[i]->id), "fd", myitoa(fd), USERS);//TODO 修改数据库的值
					ret = MWrite(fd, LogInSuccess, -1, -1, "");
					if (-1 == ret)
						break;
					return -1 * i;//返回client下标
				}
				else {
					ret = MWrite(fd, WrongPassword, -1, -1, "");
					if (-1 == ret)
						break;
					return WrongPassword;
				}
			}
		}
		ret = MWrite(fd, SomeError, -1, -1, "");
		return SomeError;
		break;
	default:
		printf("unkown_type message from client while login\n");
		return SomeError;
	}    
}

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

//将数据库的数据加载到messages_pool中
int inputMessages()
{
    connectMysql();
    int ret = mysql_query(&mysql, "SELECT send_id,recv_id,type,info_request_no,msg,group_id FROM messages");

    if(!ret)
    {
        MYSQL_RES * message_res = mysql_store_result(&mysql);
        if(message_res)
        {
            int rownum = 0;
            while(MYSQL_ROW row = mysql_fetch_row(message_res))
            {
                Messages write_in(atoi(row[0]),atoi(row[1]),(Signal)atoi(row[2]),atoi(row[3]),row[4],atoi(row[5]));
                messages_pool[atoi(row[1])].push_back(write_in);//messages_poolinsert
            }//while
        }//if(user_res)
        else
        {
            printf("Connect Erro:%d %s\n",mysql_errno(&mysql),mysql_error(&mysql));//返回错误代码、错误消息
                return -1;
        }
        mysql_free_result(message_res);
        mysql_close(&mysql);
    }//if(!ret)
    else
    {
        printf("Connect Erro:%d %s\n",mysql_errno(&mysql),mysql_error(&mysql));//返回错误代码、错误消息
        return -1;
    }
    printf("input Messages_pool success!\n");
    return 1;
}

int main(){

    //加载users数据库到*Client[]
    if(!inputClient())
    {
        printf("inputClient ERROR!\n");
    }
    //加载messages数据库到messages_pool
    if(!inputMap(3))
    {
        printf("inputMessages ERROR!\n");
    }

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
		Client_socket addr;
		addr.addr_len = sizeof(addr);
		int fd = accept(listen_fd, (struct sockaddr *)&addr.addr, &addr.addr_len);
        ErrorDeal(fd);
		//std::cout << fd << "  connect server!" << std::endl;

        //向客户端发送确认信息,告诉客户端你可以开始发送给我id和密码了
        std::string buf;
		ret = MWrite(fd, ConnectSuccess, -1, -1, " ");
		if (-1 == ret)
			continue;


        //判断登陆信息
        int connection_info = LogInOrSignedUp(fd);
		if ( SomeError == connection_info) {
			printf("client closed or unknowntype message\n");
			close(fd);
			continue;
		}
		else if (WrongPassword == connection_info) {
			printf("client gave a wrong password\n");
			close(fd);
			continue;
		}
		else { //有新的客户端需要IO处理
			client_socket[fd].push_back(addr);
			t[thread_amount++] = std::thread([connection_info]() {ClientThread(-1 * connection_info); });//线程回收后怎么更改这个amount是个问题while(=NULL)?
		}
    }//1.while(1)
	close(listen_fd);
	return 0;
}//main