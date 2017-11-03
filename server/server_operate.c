/*********************************************
*********server_operate()
*********server 一级菜单
*********
*********************************************/
#include "protocol.h"
#include "server.h"

void server_operate(void *arg)
{
	int ret;
	int sockfd = *((int *)arg);
	while(1)
	{	

		read(sockfd,&Msg,UMSGLEN);
		printf("msg type=%d,msg name %s,msg data %s\n",Msg.cmd_type,Msg.name,Msg.data);
		
		switch(Msg.cmd_type)
		{
		case REQ_LOGIN: //客户端登录请求
			printf("===================================\n");
			server_login(sockfd);
			printf("===================================\n");
			break;
		case REQ_USEARCH_MSG: //用户模式查询信息
			usearch_user_msg(sockfd);
			break;
		case REQ_CHANGE_PASSWD: //用户模式修改密码
			change_user_passwd(sockfd);
			break;	
		case REQ_ADD_USER: //管理者模式增加用户
			add_user(sockfd);
			break;	
		case REQ_DELETE_USER: //管理者模式删除用户
			delete_user(sockfd);
			break;	
		case REQ_CHANGE_MSG: //管理者模式修改信息
			change_user_msg(sockfd);
			break;
		case REQ_SEARCH_MSG: //管理者模式查询信息
			search_user_msg(sockfd);
			break;				
		default:
		case REQ_EXIT:
			return;
		}
	}
}