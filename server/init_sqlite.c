/*********************************************
********* init_sqlite()
********* server ��ʼ�����ݿ�
********* 
********* 
*********************************************/
#include "protocol.h"
#include "server.h"

int init_sqlite(sqlite3 **db)
{
	int retval = 0;
	printf("%s\n",DB_ADDR);//db�ļ���
	/*��ָ�������ݿ��ļ�,��������ڽ�����һ��ͬ�������ݿ��ļ�*/
	if ((retval = sqlite3_open(DB_ADDR, db)) != SQLITE_OK){
		perror("Can't open database");
		sqlite3_close(*db);
		exit(1);
	} else {
		printf("open sqlite success!\n");
	}

	return retval;
	
}