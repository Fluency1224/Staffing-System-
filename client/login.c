/*********************************************
********* login()
********* client ��¼��������
********* ��������ֵ��
********* 0:��¼ʧ�� 1����¼�û�ģʽ 2����¼������ģʽ
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
	case RTL_WRONGPASSWD://�������
		i_pswd++;
		printf("passwd error %d\n",3-i_pswd);
		if(i_pswd < 3)
			goto pswdwg;
		return RTL_WRONGPASSWD;
	case USER_LOGIN://�û�ģʽ
		return USER_LOGIN;
	case ROOT_LOGIN://����Աģʽ
		return ROOT_LOGIN;
	}
}