/*********************************************
*********server_login()
*********用户登录处理函数
*********
*********************************************/
#include "protocol.h"
#include "server.h"

void server_login(int sockfd)
{
	char *errmsg;
	char inbuf[512];
	int flag;
	char **resultp;
	int  nrow,  ncolumn;
	
	sprintf(inbuf,"select uname from userinfo where uname='%s' and pswd = '%s'",Msg.name,Msg.passwd);
	
	if  (sqlite3_get_table(db, inbuf,  &resultp,  &nrow, &ncolumn,  &errmsg) !=  SQLITE_OK)
	{
		printf("error :  %s\n",  errmsg);
		exit(-1);
	}
	if(nrow*ncolumn)
	{
		memset(inbuf,0,512);
		sprintf(inbuf,"select uname from userinfo where uname='%s' and type=1",Msg.name);
		
		if  (sqlite3_get_table(db, inbuf,  &resultp,  &nrow, &ncolumn,  &errmsg) !=  SQLITE_OK)
		{
			printf("error :  %s\n",  errmsg);
			exit(-1);
		}
		if(nrow*ncolumn)
		{
			printf("in the root_login\n");
			Msg.cmd_type = ROOT_LOGIN;
			write(sockfd,&Msg,UMSGLEN);
		}
		else{
			printf("in the user_login\n");
			Msg.cmd_type = USER_LOGIN;
			write(sockfd,&Msg,UMSGLEN);
		}
		
	}
	else {
		Msg.cmd_type = RTL_WRONGPASSWD;
		write(sockfd,&Msg,UMSGLEN);
	}

}