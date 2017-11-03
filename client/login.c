/*********************************************
********* login()
********* client 登录函数功能
********* 函数返回值：
********* 0:登录失败 1：登录用户模式 2：登录管理者模式
*********************************************/
#include "protocol.h"
#include "client.h"

int login()
{
	int i_pswd = 0;
pswdwg: 
	Msg.cmd_type = REQ_LOGIN;
	printf("============================\n");
	printf("input your name:\n");
	scanf("%s",Msg.name);
	printf("your passwd:\n");
	scanf("%s",Msg.passwd);
	write(sockfd,&Msg,UMSGLEN);
	
	read(sockfd,&Msg,UMSGLEN);
	printf("============================\n");
	switch(Msg.cmd_type)
	{
	case RTL_WRONGPASSWD://密码错误
		i_pswd++;
		printf("passwd error %d\n",3-i_pswd);
		if(i_pswd < 3)
			goto pswdwg;
		return RTL_WRONGPASSWD;
	case USER_LOGIN://用户模式
		return USER_LOGIN;
	case ROOT_LOGIN://管理员模式
		return ROOT_LOGIN;
	}
}