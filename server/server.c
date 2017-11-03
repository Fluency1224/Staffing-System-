/*********************************************
*********main()
*********server 主函数
*********网络初始化 建立客户端连接
*********************************************/
#include "protocol.h"
#include "server.h"

int main(int argc, const char *argv[])
{
	int listenfd,connfd;
	socklen_t clilen;
	pid_t pid;
	struct sockaddr_in cliaddr,myaddr;
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	myaddr.sin_family=AF_INET;
	myaddr.sin_port=htons(8888);
	myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(listenfd,(struct sockaddr *)&myaddr,sizeof(myaddr));
	
	listen(listenfd,CONNECTNUM);
	printf("---------------------------------------");
	printf("network init\n");
	init_sqlite(&db);
	while (1)
	{
		clilen = sizeof(cliaddr);
		/*从监听队列中取一个连接出来,并获取连接的地址*/
		if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0)
		{
			perror("accept");
			exit(-1);
		}
		printf("connection from [%s:%d]\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
		printf("---------------------------------------");
		if((pid = fork()) < 0) /*创建子进程*/
		{
			perror("fork\n");
			exit(-1);
		}else if(pid == 0)
		{
			server_operate((void *)&connfd);
			printf("clent quit!\n");
			
			close(connfd);
			sqlite3_close(db);
			exit(0);
		}
		else
		{
			while(1)
			{
				sleep(300);
				printf("server is running!\n");
			}
		}
	}
	sqlite3_close(db);
	close(listenfd);
	return 0;	
}


