/*********************************************
*********delete_user()
*********server端 管理员删除用户函数
*********
*********************************************/
#include "protocol.h"
#include "server.h"

void delete_user(int sockfd)
{
	int flag;
	char inbuf[512];
	char *errmsg;
	char **resultp;
	int  nrow,  ncolumn;
	
	memset(inbuf,0,512);
	sprintf(inbuf,"select * from userinfo where uname='%s'",Msg.name);
	printf("%s\n",Msg.name);
	if(sqlite3_get_table(db,inbuf,&resultp,&nrow,&ncolumn,&errmsg) !=  SQLITE_OK)
	{
		printf("error ii:  %s\n",  errmsg);
		return ;
	}
	printf("%d\n",nrow);
	if(nrow * ncolumn > 0)//用户存在
	{
		sprintf(inbuf,"delete from userinfo where uname='%s'",Msg.name);
		if(sqlite3_exec(db,inbuf,NULL,NULL, &errmsg) !=  SQLITE_OK)
		{
			printf("error ii:  %s\n",  errmsg);
			Msg.cmd_type = RTL_DELETE_ERR;
			strcpy(Msg.data,"delete user fail\n");
			printf("delete user fail name %s\n",Msg.name);
			write(sockfd,&Msg,UMSGLEN); 
			return ;
		}
		Msg.cmd_type = RTL_DELETE_SUCCESS;
		strcpy(Msg.data,"delete success\n");
		printf("delete success user name %s\n",Msg.name);
		write(sockfd,&Msg,UMSGLEN);
		return;
	}
	else{
		Msg.cmd_type = RTL_NO_USER;
		strcpy(Msg.data,"no user\n");
		write(sockfd,&Msg,UMSGLEN);
	}
	return;
}