#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFLEN 1024

int main(int argc,char **argv)
{
	int connected_fd;
	
	//0.parse command 
	if(argc!=3)
	{
		printf("usage: client <ip> <port> \n");
		exit(0);
	}
	
	short remote_port;
	#if 0
	sscanf(argv[2],"%hd",&remote_port);
	atoi();
	#endif

	remote_port = strtol(argv[2],NULL,10);
	
	//1.socket
	if((connected_fd = socket(PF_INET,SOCK_STREAM,0))<0)
	{
		fprintf(stderr,"create socket failed:%s\n",strerror(errno));
		exit(-1);
	}
	
	//2.connect
	struct sockaddr_in remote_ipv4_addr;
	memset(&remote_ipv4_addr,0,sizeof(remote_ipv4_addr));
	remote_ipv4_addr.sin_family = AF_INET;
	remote_ipv4_addr.sin_port = htons(remote_port);
	inet_pton(AF_INET,argv[1],&remote_ipv4_addr.sin_addr);

	if(connect(connected_fd,(struct sockaddr *)&remote_ipv4_addr,sizeof(remote_ipv4_addr))<0)
	{
		fprintf(stderr,"connect failed:%s\n",strerror(errno));
	}

	//3.read/write
	char buf[BUFLEN];
	int ret_r;
	if((ret_r=read(connected_fd,buf,sizeof(buf)-1))<0)
	{
		fprintf(stderr,"read failed:%s\n",strerror(errno));
		//FIXME
	}
	else if(ret_r==0)
	{
		printf("socket is closed by peer!s\n");
	}
	else
	{
		buf[ret_r] = 0;
		printf("%s\n",buf);		
	}

	//4.close
	close(connected_fd);

	return 0;
}
