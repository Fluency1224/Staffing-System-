/*********************************************
********* search_user_msg()
********* client ����Ա��ѯ�û���Ϣ����
********* ����Աģʽ user_operate_1()��������
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void search_user_msg()//��ѯ�û���Ϣ
{
	//memset(umsg,0,UMSGLEN);
	Msg.cmd_type = REQ_SEARCH_MSG;
	printf("want search user name:\n>");
	scanf("%s",Msg.name);
	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_NO_USER://�û�������
		printf("%s",Msg.data);
		break;
	case RTL_RSEARCH_ERR://����Աģʽ��ѯʧ��
		printf("%s",Msg.data);
		break;
	case RTL_RSEARCH_SUCCESS://����Աģʽ��ѯ�ɹ�
		printf("%s",Msg.data);
		printf("***no    |%d\n***name  |%s\n***addr  |%s\n***age   |%s\n***level |%s\n***phone |%s\n***salary|%s\n***type  |%d\n",
			Msg.no,Msg.name,Msg.addr,Msg.age,Msg.level,Msg.phone,Msg.salary,Msg.type);
		break;
	}
	return;
}