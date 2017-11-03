#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>          
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <inttypes.h>
#include <signal.h>
#include <sqlite3.h>

#define CHARLEN 2
#define PSWORDLEN 15
#define USERNAMELEN 32
#define PHONELEN 32
#define SALARYLEN 32
#define ADDRLEN 32
#define DATALEN   32

/*client 宏*/
/***********************************************************************/
#define REQ_EXIT           0x0000 /*客户端发起的退出登陆请求*/

#define REQ_LOGIN          0x0001 /*客户端发起的登陆请求*/

#define REQ_ADD_USER       0x0011 /*客户端发起的添加用户*/
#define REQ_DELETE_USER    0x0012 /*客户端发起的删除用户*/
#define REQ_CHANGE_MSG     0x0013 /*客户端发起的修改用户信息*/
#define REQ_SEARCH_MSG     0x0014 /*客户端发起的管理员查询用户信息*/

#define REQ_USEARCH_MSG    0x0021 /*客户端发起的用户查询用户信息*/
#define REQ_CHANGE_PASSWD  0x0022 /*客户端发起的修改密码*/

#define RTL_WRONGPASSWD    0x1000 /*密码错误*/
#define USER_LOGIN         0x1001 /*用户模式*/
#define ROOT_LOGIN         0x1002 /*管理员模式*/


#define RTL_USER_EXIST     (unsigned short)0x1003 /*用户已存在*/
#define RTL_INSERT_ERR     (unsigned short)0x1004 /*添加用户失败*/
#define RTL_ADD_SUCCESS    (unsigned short)0x1005 /*添加用户成功*/

#define RTL_NO_USER        (unsigned short)0x1006 /*用户不存在*/
#define RTL_DELETE_ERR     (unsigned short)0x1007 /*删除用户失败*/
#define RTL_DELETE_SUCCESS (unsigned short)0x1008 /*删除用户成功*/

#define RTL_CHANGE_SUCCESS (unsigned short)0x1009 /*修改信息成功*/
#define RTL_CHANGE_ERR     (unsigned short)0x1010 /*修改信息失败*/

#define RTL_RSEARCH_SUCCESS (unsigned short)0x1011 /*管理员查询信息成功*/
#define RTL_RSEARCH_ERR     (unsigned short)0x1012 /*管理员查询信息失败*/

#define RTL_SEARCH_SUCCESS (unsigned short)0x1011 /*查询信息成功*/
#define RTL_SEARCH_ERR     (unsigned short)0x1012 /*查询信息失败*/

#define RTL_CHGPSWD_SUCC   (unsigned short)0x1013 /*修改密码成功*/
#define RTL_CHGPSWD_ERR    (unsigned short)0x1014 /*修改密码失败*/
/***********************************************************************/
/*server 宏*/
/***********************************************************************/

/***********************************************************************/
typedef uint16_t state_t;

struct XProtocol 
{  
    int cmd_type; 
	unsigned char data[DATALEN];//数据
	/*数据库字段*/
	int no; //编号
	unsigned char name[USERNAMELEN];//姓名 USERNAMELEN
	unsigned char passwd[PSWORDLEN];//密码 PSWORDLEN
	char addr[ADDRLEN]; // 地址 ADDRLEN
	char age[CHARLEN]; // 年龄 CHARLEN
	char level[CHARLEN]; // 等级 CHARLEN
	char phone[PHONELEN]; // 电话 PHONELEN
	char salary[SALARYLEN] ; // 工资 SALARYLEN
	int  type; //权限标志位 0是普通员工 1 是管理员
}Msg;


#endif /*PROTOCOL_H_*/


