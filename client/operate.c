/*********************************************
*********cli_user_operate()
*********client һ���˵�
*********
*********************************************/
#include "protocol.h"
#include "client.h"

void cli_user_operate()
{
	int ucmd;
	int ret;
	while(1)
	{
		menu_1();
		printf("---------------------------------------");
		printf("Please enter your choice>");
		scanf("%d",&ucmd);
		getchar();
		switch(ucmd)
		{
		case REQ_LOGIN:
			ret = login();
			if(ret == USER_LOGIN)
				user_operate_1();
			else if(ret == ROOT_LOGIN)
				root_operate_2();
			else if(ret == RTL_WRONGPASSWD)
				printf("login fail\n");
			break;
		case REQ_EXIT:
			Msg.cmd_type = REQ_EXIT;
			strcpy(Msg.data,"client exit\n");
			write(sockfd, &Msg,UMSGLEN);
			return;
		}
		printf("enter one char go on:\n");
		getchar();
		system("clear");
	}
}

/*********************************************
*********user_operate_1()
*********client �����˵�
*********�û�ģʽ
*********************************************/
void user_operate_1()
{
	while(1)
	{
		int ucmd;
		menu_3();
		printf("---------------------------------------");
		printf("Please enter your choice>");
		scanf("%d",&ucmd);
		getchar();
		switch(ucmd)
		{
		case 1:
			usearch_user_msg();//��ѯ��Ϣ
			break;
		case 2:
			change_user_passwd();//�޸�����
			break;
		case REQ_EXIT:
			Msg.cmd_type = REQ_EXIT;
			write(sockfd,&Msg,UMSGLEN);
			exit(0);
		}
		printf("enter one char go on:\n");
		getchar();
		system("clear");
	}
}

/*********************************************
*********root_operate_2()
*********client �����˵�
*********����Աģʽ
*********************************************/
void root_operate_2()
{
	while(1)
	{
		menu_2();
		int ucmd;
		printf("---------------------------------------");
		printf("Please enter your choice>");
		scanf("%d",&ucmd);
		getchar();
		switch(ucmd)
		{
		case 1:
			add_user();//�����û�
			break;
		case 2:
			delete_user();//ɾ���û�
			break;
		case 3:
			change_user_msg();//�޸��û���Ϣ
			break;
		case 4:
			search_user_msg();//��ѯ�û���Ϣ
			break;
		case REQ_EXIT:
			Msg.cmd_type = REQ_EXIT;
			write(sockfd,&Msg,UMSGLEN);
			exit(0);
		}
		printf("enter one char go on:\n");
		getchar();
		system("clear");
	}
}
