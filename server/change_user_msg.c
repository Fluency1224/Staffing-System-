/*********************************************
*********change_user_msg()
*********server端 管理员模式修改用户信息处理函数
*********
*********************************************/
#include "protocol.h"
#include "server.h"

void change_user_msg(int sockfd)
{
	char *errmsg;
	char inbuf[512];
	
	memset(inbuf,0,512);
	sprintf(inbuf,"update userinfo set pswd='%s',addr='%s',age='%s',level='%s',phone='%s',salary='%s' where uname='%s'",
		Msg.passwd,Msg.addr,Msg.age,Msg.level,Msg.phone,Msg.salary,Msg.name);
	if(sqlite3_exec(db,inbuf,NULL,NULL, &errmsg) !=  SQLITE_OK)
	{
		printf("error ii:  %s\n",  errmsg);
		Msg.cmd_type = RTL_CHANGE_ERR;
		strcpy(Msg.data,"change msg fail\n");
		printf("change msg fail name %s\n",Msg.name);
		write(sockfd,&Msg,UMSGLEN);
		return ;
	}
	else{
		Msg.cmd_type = RTL_CHANGE_SUCCESS;
		strcpy(Msg.data,"change msg success\n");
		printf("change msg success name %s\n",Msg.name);
		write(sockfd,&Msg,UMSGLEN);
	}
		
}