/*********************************************
*********search_user_msg()
*********server端 用户查询信息处理函数
*********
*********************************************/
#include "protocol.h"
#include "server.h"

void search_user_msg(int sockfd)
{
	int nrow,ncolumn;
	char *errmsg,**resultp;
	char inbuf[512];
	
	sprintf(inbuf,"select * from userinfo where uname='%s'",Msg.name);
	if(sqlite3_get_table(db,inbuf,&resultp,&nrow,&ncolumn,&errmsg) !=  SQLITE_OK)
	{
		printf("error ii:  %s\n",  errmsg);
		return ;
	}

	if(nrow > 0)//用户存在
	{
		printf("Root Search User Msg : %s have %dline %dcolumn\n",Msg.name,nrow,ncolumn);
		Msg.no = atoi(resultp[ncolumn]);
		strcpy(Msg.name,resultp[ncolumn+1]);
		strcpy(Msg.passwd,resultp[ncolumn+2]);
		strcpy(Msg.addr,resultp[ncolumn+3]);
		strcpy(Msg.age,resultp[ncolumn+4]);
		strcpy(Msg.level,resultp[ncolumn+5]);
		strcpy(Msg.phone,resultp[ncolumn+6]);
		strcpy(Msg.salary,resultp[ncolumn+7]);
		Msg.type = atoi(resultp[8]);
		
		Msg.cmd_type = RTL_SEARCH_SUCCESS;
		strcpy(Msg.data,"get msg:\n");
		write(sockfd,&Msg,UMSGLEN);
	}
	else
	{
		Msg.cmd_type = RTL_NO_USER;
		strcpy(Msg.data,"no user\n");
		write(sockfd,&Msg,UMSGLEN);
	}
	return;
}