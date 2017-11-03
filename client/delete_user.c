/*********************************************
********* delete_user()
********* client 删除用户功能
********* 管理员模式 user_operate_1()函数调用
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void delete_user()//删除用户
{
	Msg.cmd_type = REQ_DELETE_USER;
	printf("delete name:\n>");
	scanf("%s",Msg.name);
	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_NO_USER: //用户不存在
		printf("%s",Msg.data);
		break;
	case RTL_DELETE_ERR: //删除用户失败
		printf("%s",Msg.data);
		break;
	case RTL_DELETE_SUCCESS: //删除用户成功
		printf("%s",Msg.data);
		break;
	}
	return;
}