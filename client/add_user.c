/*********************************************
********* add_user()
********* client 增加用户功能
********* 管理员模式 user_operate_1()函数调用
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void add_user()//增加用户
{
	Msg.cmd_type = REQ_ADD_USER;
	printf("add user name:\n>");
	scanf("%s",Msg.name);
	printf("no:\n>");
	scanf("%d",&Msg.no);
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
	//printf("type:\n>");
	//scanf("%d",&Msg.type);
	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_USER_EXIST://用户已存在
		printf("%s",Msg.data);
		break;
	case RTL_INSERT_ERR://插入用户失败
		printf("%s",Msg.data);
		break;
	case RTL_ADD_SUCCESS://添加用户成功
		printf("%s",Msg.data);
	}
	return;
}