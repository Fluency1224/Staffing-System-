/*********************************************
********* add_user()
********* client �����û�����
********* ����Աģʽ user_operate_1()��������
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void add_user()//�����û�
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
	case RTL_USER_EXIST://�û��Ѵ���
		printf("%s",Msg.data);
		break;
	case RTL_INSERT_ERR://�����û�ʧ��
		printf("%s",Msg.data);
		break;
	case RTL_ADD_SUCCESS://����û��ɹ�
		printf("%s",Msg.data);
	}
	return;
}