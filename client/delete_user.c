/*********************************************
********* delete_user()
********* client ɾ���û�����
********* ����Աģʽ user_operate_1()��������
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void delete_user()//ɾ���û�
{
	Msg.cmd_type = REQ_DELETE_USER;
	printf("delete name:\n>");
	scanf("%s",Msg.name);
	write(sockfd,&Msg,UMSGLEN);

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_NO_USER: //�û�������
		printf("%s",Msg.data);
		break;
	case RTL_DELETE_ERR: //ɾ���û�ʧ��
		printf("%s",Msg.data);
		break;
	case RTL_DELETE_SUCCESS: //ɾ���û��ɹ�
		printf("%s",Msg.data);
		break;
	}
	return;
}