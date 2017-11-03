/*********************************************
*********server_operate()
*********server һ���˵�
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
		case REQ_LOGIN: //�ͻ��˵�¼����
			printf("===================================\n");
			server_login(sockfd);
			printf("===================================\n");
			break;
		case REQ_USEARCH_MSG: //�û�ģʽ��ѯ��Ϣ
			usearch_user_msg(sockfd);
			break;
		case REQ_CHANGE_PASSWD: //�û�ģʽ�޸�����
			change_user_passwd(sockfd);
			break;	
		case REQ_ADD_USER: //������ģʽ�����û�
			add_user(sockfd);
			break;	
		case REQ_DELETE_USER: //������ģʽɾ���û�
			delete_user(sockfd);
			break;	
		case REQ_CHANGE_MSG: //������ģʽ�޸���Ϣ
			change_user_msg(sockfd);
			break;
		case REQ_SEARCH_MSG: //������ģʽ��ѯ��Ϣ
			search_user_msg(sockfd);
			break;				
		default:
		case REQ_EXIT:
			return;
		}
	}
}