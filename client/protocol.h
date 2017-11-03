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

/*client ��*/
/***********************************************************************/
#define REQ_EXIT           0x0000 /*�ͻ��˷�����˳���½����*/

#define REQ_LOGIN          0x0001 /*�ͻ��˷���ĵ�½����*/

#define REQ_ADD_USER       0x0011 /*�ͻ��˷��������û�*/
#define REQ_DELETE_USER    0x0012 /*�ͻ��˷����ɾ���û�*/
#define REQ_CHANGE_MSG     0x0013 /*�ͻ��˷�����޸��û���Ϣ*/
#define REQ_SEARCH_MSG     0x0014 /*�ͻ��˷���Ĺ���Ա��ѯ�û���Ϣ*/

#define REQ_USEARCH_MSG    0x0021 /*�ͻ��˷�����û���ѯ�û���Ϣ*/
#define REQ_CHANGE_PASSWD  0x0022 /*�ͻ��˷�����޸�����*/

#define RTL_WRONGPASSWD    0x1000 /*�������*/
#define USER_LOGIN         0x1001 /*�û�ģʽ*/
#define ROOT_LOGIN         0x1002 /*����Աģʽ*/


#define RTL_USER_EXIST     (unsigned short)0x1003 /*�û��Ѵ���*/
#define RTL_INSERT_ERR     (unsigned short)0x1004 /*����û�ʧ��*/
#define RTL_ADD_SUCCESS    (unsigned short)0x1005 /*����û��ɹ�*/

#define RTL_NO_USER        (unsigned short)0x1006 /*�û�������*/
#define RTL_DELETE_ERR     (unsigned short)0x1007 /*ɾ���û�ʧ��*/
#define RTL_DELETE_SUCCESS (unsigned short)0x1008 /*ɾ���û��ɹ�*/

#define RTL_CHANGE_SUCCESS (unsigned short)0x1009 /*�޸���Ϣ�ɹ�*/
#define RTL_CHANGE_ERR     (unsigned short)0x1010 /*�޸���Ϣʧ��*/

#define RTL_RSEARCH_SUCCESS (unsigned short)0x1011 /*����Ա��ѯ��Ϣ�ɹ�*/
#define RTL_RSEARCH_ERR     (unsigned short)0x1012 /*����Ա��ѯ��Ϣʧ��*/

#define RTL_SEARCH_SUCCESS (unsigned short)0x1011 /*��ѯ��Ϣ�ɹ�*/
#define RTL_SEARCH_ERR     (unsigned short)0x1012 /*��ѯ��Ϣʧ��*/

#define RTL_CHGPSWD_SUCC   (unsigned short)0x1013 /*�޸�����ɹ�*/
#define RTL_CHGPSWD_ERR    (unsigned short)0x1014 /*�޸�����ʧ��*/
/***********************************************************************/
/*server ��*/
/***********************************************************************/

/***********************************************************************/
typedef uint16_t state_t;

struct XProtocol 
{  
    int cmd_type; 
	unsigned char data[DATALEN];//����
	/*���ݿ��ֶ�*/
	int no; //���
	unsigned char name[USERNAMELEN];//���� USERNAMELEN
	unsigned char passwd[PSWORDLEN];//���� PSWORDLEN
	char addr[ADDRLEN]; // ��ַ ADDRLEN
	char age[CHARLEN]; // ���� CHARLEN
	char level[CHARLEN]; // �ȼ� CHARLEN
	char phone[PHONELEN]; // �绰 PHONELEN
	char salary[SALARYLEN] ; // ���� SALARYLEN
	int  type; //Ȩ�ޱ�־λ 0����ͨԱ�� 1 �ǹ���Ա
}Msg;


#endif /*PROTOCOL_H_*/


