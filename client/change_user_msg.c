/*********************************************
********* change_user_msg()
********* client 修改用户信息功能
********* 管理员模式 user_operate_1()函数调用
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void change_user_msg()//修改用户信息
{
	Msg.cmd_type = REQ_CHANGE_MSG;
	printf("want change name:\n>");
	scanf("%s",Msg.name);
	printf("passwd:\n>");
	scanf("%s",Msg.passwd);
	printf("addr:\n>");
	scanf("%s",Msg.addr);
	printf("age:\n>");
	scanf("%s",Msg.age);
	printf("level:\n>");
	scanf("%s",Msg.level);
	printf("phone:\n>");
	scanf("%s",Msg.phone);
	printf("salary:\n>");
	scanf("%s",Msg.salary);
	//printf("权限位:>\n>");
	//scanf("%d",&Msg.type);
	//getchar();
	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_CHANGE_ERR://修改失败
		printf("%s",Msg.data);
		break;
	case RTL_CHANGE_SUCCESS://更新成功
		printf("%s",Msg.data);
		break;
	}
	return;
}