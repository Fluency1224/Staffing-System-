#include "protocol.h"
#include <sqlite3.h>

#define UMSGLEN     sizeof(Msg)
#define CONNECTNUM  10
#define DB_ADDR "mysqlite.db"

sqlite3 *db;//定义数据库文件指针


int init_sqlite(sqlite3 **db);//初始化数据库
int callback(void *para, int f_num, char **f_value, char **f_name);
void server_operate(void *arg);

void add_user(int sockfd);
void delete_user(int sockfd);
void search_user_msg(int sockfd);
void server_login(int sockfd);
void change_user_passwd(int sockfd);
void usearch_user_msg(int sockfd);
void change_user_msg(int sockfd);