/*********************************************
*********change_user_passwd()
*********server端 用户修改密码处理函数
*********
*********************************************/
#include "protocol.h"
#include "server.h"

void change_user_passwd(int sockfd)
{
	char *errmsg;
	char inbuf[512];
	
	memset(inbuf,0,512);
	sprintf(inbuf,"update userinfo set pswd='%s' where uname='%s'",Msg.data,Msg.name);//更改用户密码
	if(sqlite3_exec(db,inbuf,NULL,NULL, &errmsg) !=  SQLITE_OK)
	{
		printf("error ii:  %s\n",  errmsg);
		Msg.cmd_type = RTL_SEARCH_ERR;
		strcpy(Msg.data,"change passwd fail\n");
		printf("cchange passwd fail\n");
		write(sockfd,&Msg,UMSGLEN);
		return ;
	}
	Msg.cmd_type = RTL_CHGPSWD_SUCC;
	strcpy(Msg.data,"change passwd success\n");
	write(sockfd,&Msg,UMSGLEN);	
	printf("change passwd success\n");
	return;	
}