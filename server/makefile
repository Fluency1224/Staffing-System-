server : server.o init_sqlite.o server_operate.o server_login.o usearch_user_msg.o change_user_passwd.o add_user.o delete_user.o change_user_msg.o search_user_msg.o
	gcc server.o init_sqlite.o server_operate.o server_login.o usearch_user_msg.o change_user_passwd.o add_user.o delete_user.o change_user_msg.o search_user_msg.o -lsqlite3  -o server

server.o : server.c
	gcc server.c -c -o server.o 

init_sqlite.o : init_sqlite.c
	gcc init_sqlite.c -c -o init_sqlite.o

server_operate.o : server_operate.c
	gcc server_operate.c -c -o server_operate.o
	
server_login.o : server_login.c
	gcc server_login.c -c -o server_login.o

usearch_user_msg.o : usearch_user_msg.c
	gcc usearch_user_msg.c -c -o usearch_user_msg.o

change_user_passwd.o : change_user_passwd.c
	gcc change_user_passwd.c -c -o change_user_passwd.o
	
add_user.o : add_user.c
	gcc add_user.c -c -o add_user.o

delete_user.o : delete_user.c
	gcc delete_user.c -c -o delete_user.o

change_user_msg .o : change_user_msg.c
	gcc change_user_msg.c -c -o change_user_msg.o
	
search_user_msg.o :search_user_msg.c
	gcc search_user_msg.c -c -o search_user_msg.o

clean :
	@rm -rf ./*.o