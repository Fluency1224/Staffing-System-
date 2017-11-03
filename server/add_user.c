/*********************************************
*********add_user()
*********server端 管理员增加用户函数
*********
*********************************************/
#include "protocol.h"
#include "server.h"

void add_user(int sockfd)
{
	int flag;
	char inbuf[512];
	char *errmsg;
	char **resultp;
	int  nrow,  ncolumn;
	
	memset(inbuf,0,512);
	sprintf(inbuf,"select * from userinfo where uname='%s'",Msg.name);
	if(sqlite3_get_table(db,inbuf,&resultp,&nrow,&ncolumn,&errmsg) !=  SQLITE_OK)
	{
		printf("error ii:  %s\n",  errmsg);
		return ;
	}

	if(nrow > 0)//用户存在
	{
		Msg.cmd_type = RTL_USER_EXIST;
		strcpy(Msg.data,"user done\n");
		write(sockfd,&Msg,UMSGLEN);
		return;
	}
	else{
		
		memset(inbuf,0,512);
		sprintf(inbuf,"insert into userinfo values('%d','%s','abcd1234','%s','%s','%s','%s','%s',0)",
			Msg.no,Msg.name,Msg.addr,Msg.age,Msg.level,Msg.phone,Msg.salary);
		if(sqlite3_exec(db,inbuf,NULL,NULL, &errmsg) !=  SQLITE_OK)
		{
			printf("error ii:  %s\n",  errmsg);
			Msg.cmd_type = RTL_INSERT_ERR;
			strcpy(Msg.data,"add user fail\n");
			printf("add user fail name %s",Msg.name);
			write(sockfd,&Msg,UMSGLEN);
			return ;
		}
		else{
			Msg.cmd_type = RTL_ADD_SUCCESS;
			strcpy(Msg.data,"add success\n");
			printf("add success user name %s",Msg.name);
			write(sockfd,&Msg,UMSGLEN);
		}
	}
	
	return;
}