#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

int main()
{
	int sock = 0;
	int client_sock = 0;
	struct sockaddr_in sockaddr ;
	int sockaddr_len = sizeof(sockaddr);
	char Buf[100];
	
	sock = socket(AF_INET,SOCK_STREAM,0); //创建套接字
	
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = 9734;
	sockaddr.sin_addr.s_addr = inet_addr("192.168.5.128");
	
	connect(sock,(struct sockaddr*)&sockaddr,sockaddr_len);
	
	while(1)
	{
		fgets(Buf,100,stdin);
		Buf[strlen(Buf)-1] = 0;
		printf("Buf : %s\n",Buf);
		write(sock,Buf,100);
	}
	close(sock);
	return 0;
}
