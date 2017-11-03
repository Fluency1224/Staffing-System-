/*********************************************
********* search_user_msg()
********* client 管理员查询用户信息功能
********* 管理员模式 user_operate_1()函数调用
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void search_user_msg()//查询用户信息
{
	//memset(umsg,0,UMSGLEN);
	Msg.cmd_type = REQ_SEARCH_MSG;
	printf("want search user name:\n>");
	scanf("%s",Msg.name);
	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_NO_USER://用户不存在
		printf("%s",Msg.data);
		break;
	case RTL_RSEARCH_ERR://管理员模式查询失败
		printf("%s",Msg.data);
		break;
	case RTL_RSEARCH_SUCCESS://管理员模式查询成功
		printf("%s",Msg.data);
		printf("***no    |%d\n***name  |%s\n***addr  |%s\n***age   |%s\n***level |%s\n***phone |%s\n***salary|%s\n***type  |%d\n",
			Msg.no,Msg.name,Msg.addr,Msg.age,Msg.level,Msg.phone,Msg.salary,Msg.type);
		break;
	}
	return;
}