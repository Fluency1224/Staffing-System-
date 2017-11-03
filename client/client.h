#include "protocol.h"

#define UMSGLEN sizeof(Msg)

int sockfd;

void user_operate_1();
void root_operate_2();
void cli_user_operate();
int login();
void add_user();
void delete_user();
void change_user_msg();
void search_user_msg();
void usearch_user_msg();
void change_user_passwd();