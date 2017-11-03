/*********************************************
********* usearch_user_msg()
********* client 用户查询用户信息功能
********* 管理员模式 user_operate_2()函数调用
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void usearch_user_msg()//查询用户信息
{
	Msg.cmd_type = REQ_USEARCH_MSG;

	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_NO_USER://用户不存在
		printf("%s",Msg.data);
		break;
	case RTL_SEARCH_ERR://查询失败
		printf("%s",Msg.data);
		break;
	case RTL_SEARCH_SUCCESS://查询成功
		printf("%s",Msg.data);
		printf("***no    |%d\n***name  |%s\n***addr  |%s\n***age   |%s\n***level |%s\n***phone  |%s\n***salary|%s\n",
			Msg.no,Msg.name,Msg.addr,Msg.age,Msg.level,Msg.phone,Msg.salary);
		break;
	}
	return;
}