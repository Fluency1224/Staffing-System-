/*********************************************
********* change_user_passwd()
********* client �����û����빦��
********* �û�ģʽ root_operate_2()��������
********* 
*********************************************/
#include "protocol.h"
#include "client.h"

void change_user_passwd()//�޸�����
{
	char passwd[DATALEN];
	Msg.cmd_type = REQ_CHANGE_PASSWD;
	printf("new passwd:\n");
	scanf("%s",Msg.data);
	printf("sure passwd:\n");
	scanf("%s",passwd);
	if(strcmp( passwd, Msg.data) == 0)
	{
		write(sockfd,&Msg,UMSGLEN);
		printf("change %s passwd is %s\n",Msg.name,Msg.data);
	}
	else{
		printf("fail try agin\n");
		return;
	}

	read(sockfd,&Msg,UMSGLEN);
	switch(Msg.cmd_type)
	{
	case RTL_SEARCH_ERR: //��ѯʧ��
		printf("%s",Msg.data);
		break;
	case RTL_CHGPSWD_SUCC: //�޸�����ɹ�
		printf("%s",Msg.data);
		break;
	}
	return;
}