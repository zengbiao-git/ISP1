#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

void *ConFuntion(void *arg)
{
	int sock = *(int *)arg;
	char Buf[30]={0};
	while()
	{
		read(sock,Buf,strlen(Buf)+1);
		printf("%s \n",Buf);
		
	}
	pthread_exit(0);
}

int main()
{
	int sock = 0;
	int client_sock = 0;
	struct sockaddr_in sockaddr ;
	struct sockaddr_in client_sockaddr;
	
	int sockaddr_len = sizeof(sockaddr);
	int client_sockaddr_len = 0;
	
	pthread_t conid = 0;
	
	sock = socket(AF_INET,SOCK_STREAM,0); //创建套接字
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = 9734;
	sockaddr.sin_addr.s_addr = inet_addr("192.168.5.128");
	
	bind(sock,(struct sockaddr*)&sockaddr,sockaddr_len); //将IP地址和端口与套接字关联
	
	listen(sock,10); //10?
	
	printf("wait client connect \n");
	
	while(1)
	{
		client_sock = accept(sock,(struct sockaddr*)&client_addr,(socklen_t*)&client_sockaddr_len);
		printf("begin create thread\n");
		pthread_create(&conid,NULL,ConFuntion,&client_sock);
		
	}
	close(sock);
	return 0;
}
