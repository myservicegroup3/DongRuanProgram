#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/un.h>

//tcp编程：server端

#define LOCALPORT 8888
#define LOCALADDR "127.0.0.1"
#define BACKLOG 10

void client_do(int connected_fd,struct sockaddr_in remote_ipv4_addr);

int main(int argc,char *argv[])
{
	int listening_fd;
	//1.socket
	if((listening_fd = socket(PF_INET,SOCK_STREAM,0))<0)
	{
		fprintf(stderr,"Create socket failed:%s\n",strerror(errno));
		exit(-1);
	}
	
	//2.bind
	#if 0
	struct sockaddr_in {					//ipv4专用地址结构
		sa_family_t sin_family;
		in_port_t sin_port;
		struct in_addr sin_addr;
		unsigned char sin_zero[8];
	}
	#endif 
	struct sockaddr_in local_ipv4_addr;
	memset(&local_ipv4_addr,0,sizeof(local_ipv4_addr));
	local_ipv4_addr.sin_family = AF_INET;
	local_ipv4_addr.sin_port = htons(LOCALPORT);//NBO
	inet_pton(AF_INET,LOCALADDR,&local_ipv4_addr.sin_addr);//NBO

	if(bind(listening_fd,(struct sockaddr * )&local_ipv4_addr,sizeof(local_ipv4_addr))<0)
	{
		fprintf(stderr,"Bind failed:%s\n",strerror(errno));
		exit(-1);
	}

	//3.listen
	if(listen(listening_fd,BACKLOG)<0)
	{
		fprintf(stderr,"Listen on [%s/%d] failed:%s\n",
				LOCALADDR,LOCALPORT,strerror(errno));
		exit(-1);
	}

	//4.accept
	struct sockaddr_in remote_ipv4_addr;
	socklen_t len = sizeof(remote_ipv4_addr);
	int connected_fd;
	
	while(1)
	{	
		if((connected_fd=accept(listening_fd,(struct sockaddr * )&remote_ipv4_addr,&len))<0)
		{
			fprintf(stderr,"Accept a new connection failed:%s\n",strerror(errno));
			exit(-1);
		}
		
		pid_t pid;
		pid = fork();
		if(pid<0)
		{
			fprintf(stderr,"fork failed:%s\n",strerror(errno));
			//FIXME
		}
		else if(pid==0)
		{
			//关闭对自己无用的描述符号
			close(listening_fd);
			client_do(connected_fd,remote_ipv4_addr);
			exit(0);
		}
		else
		{
			//关闭对自己无用的描述符号
			close(connected_fd);
		}
	}
	
	//最后关闭listening_fd
	close(listening_fd);
	return 0;
}


void client_do(int connected_fd,struct sockaddr_in remote_ipv4_addr)
{
	//5.write
	char banner[255];
	char remote_ipv4_str[] = "ddd.ddd.ddd.ddd\0";

	//获取对方的ip地址，并且转换为字符串
	if(inet_ntop(AF_INET,&remote_ipv4_addr.sin_addr,remote_ipv4_str,strlen(remote_ipv4_str))==NULL)
	{
		fprintf(stderr,"inet_ntop failed:%s\n",strerror(errno));
		exit(-1);
	}

	//获取对方的端口号
	int remote_port = ntohs(remote_ipv4_addr.sin_port);

	sprintf(banner,"HTTP/1.1 200 OK\n\n<center><h1><font color='red'>welcome to myserver, your address is : %s/%d</font></h1></center>",
		remote_ipv4_str,remote_port);	

	//发送banner给对方
	int ret_w;
	if((ret_w=write(connected_fd,banner,strlen(banner)))<strlen(banner))
	{
		if(ret_w<0)
		{
			fprintf(stderr,"write failed:%s\n",strerror(errno));
			//?FIXME
		}
		printf("write less than expected!\n");	
	}

	//6.close
	close(connected_fd);
	sleep(20);
}
