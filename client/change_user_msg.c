/*********************************************
********* change_user_msg()
********* client �޸��û���Ϣ����
********* ����Աģʽ user_operate_1()��������
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void change_user_msg()//�޸��û���Ϣ
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
	//printf("Ȩ��λ:>\n>");
	//scanf("%d",&Msg.type);
	//getchar();
	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_CHANGE_ERR://�޸�ʧ��
		printf("%s",Msg.data);
		break;
	case RTL_CHANGE_SUCCESS://���³ɹ�
		printf("%s",Msg.data);
		break;
	}
	return;
}