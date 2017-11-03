/*********************************************
********* init_sqlite()
********* server 初始化数据库
********* 
********* 
*********************************************/
#include "protocol.h"
#include "server.h"

int init_sqlite(sqlite3 **db)
{
	int retval = 0;
	printf("%s\n",DB_ADDR);//db文件名
	/*打开指定的数据库文件,如果不存在将创建一个同名的数据库文件*/
	if ((retval = sqlite3_open(DB_ADDR, db)) != SQLITE_OK){
		perror("Can't open database");
		sqlite3_close(*db);
		exit(1);
	} else {
		printf("open sqlite success!\n");
	}

	return retval;
	
}