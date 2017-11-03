#include "protocol.h"
#include "client.h"

void menu_1()//一级菜单
{
	printf("************************************\n");
	printf("************ 1 login      **********\n");
	printf("************ 0 quit       **********\n");
	printf("************************************\n");
}
void menu_2()//用户模式菜单
{
	printf("************************************\n");
	printf("************ 1 add user        *****\n");
	printf("************ 2 delete user     *****\n");
	printf("************ 3 change user msg *****\n");
	printf("************ 4 search user msg *****\n");
	printf("************ 0  quit           *****\n");
	printf("************************************\n");
}
void menu_3()//管理员模式菜单
{
	printf("************************************\n");
	printf("************ 1 search my msg     ***\n");
	printf("************ 2 change my passwd  ***\n");
	printf("************ 0 quit              ***\n");
	printf("************************************\n");
}
