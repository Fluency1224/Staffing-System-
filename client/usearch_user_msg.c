/*********************************************
********* usearch_user_msg()
********* client �û���ѯ�û���Ϣ����
********* ����Աģʽ user_operate_2()��������
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void usearch_user_msg()//��ѯ�û���Ϣ
{
	Msg.cmd_type = REQ_USEARCH_MSG;

	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_NO_USER://�û�������
		printf("%s",Msg.data);
		break;
	case RTL_SEARCH_ERR://��ѯʧ��
		printf("%s",Msg.data);
		break;
	case RTL_SEARCH_SUCCESS://��ѯ�ɹ�
		printf("%s",Msg.data);
		printf("***no    |%d\n***name  |%s\n***addr  |%s\n***age   |%s\n***level |%s\n***phone  |%s\n***salary|%s\n",
			Msg.no,Msg.name,Msg.addr,Msg.age,Msg.level,Msg.phone,Msg.salary);
		break;
	}
	return;
}