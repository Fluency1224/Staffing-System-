/*********************************************
*********main()
*********client 主函数
*********网络初始化 建立客户端连接
*********************************************/
#include "protocol.h"
#include "client.h"

int main(int argc, const char *argv[])
{
	int fd;
	struct sockaddr_in myaddr;
	fd = socket(AF_INET,SOCK_STREAM,0);
	myaddr.sin_family=AF_INET;
	myaddr.sin_port=htons(8888);
	myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	
	if((connect(fd,(struct sockaddr *)&myaddr,sizeof(myaddr))) < 0)
	{
		perror("network fail!\n");
		exit(-1);
	}
	printf("---------------------------------------");
	printf("network init\n");
	printf("Welcome to the staff management system\n");
	printf("---------------------------------------");
	while(1)
	{
		sockfd = fd;
		cli_user_operate();	
	}


	close(sockfd);
	return 0;
}