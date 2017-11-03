cient : client.o operate.o menu.o login.o add_user.o delete_user.o change_user_msg.o search_user_msg.o usearch_user_msg.o change_user_passwd.o
	gcc client.o operate.o menu.o login.o add_user.o delete_user.o change_user_msg.o search_user_msg.o usearch_user_msg.o change_user_passwd.o -o client

client.o : client.c
	gcc client.c -c -o client.o

operate.o : operate.c
	gcc operate.c -c -o operate.o
	
menu.o : menu.c
	gcc menu.c -c -o menu.o
	
login.o : login.c
	gcc login.c -c -o login.o
	
usearch_user_msg.o : usearch_user_msg.c
	gcc usearch_user_msg.c -c -o usearch_user_msg.o
	
change_user_passwd.o : change_user_passwd.c
	gcc change_user_passwd.c -c -o change_user_passwd.o

add_user.o : add_user.c
	gcc add_user.c -c -o add_user.o
	
delete_user.o : delete_user.c
	gcc delete_user.c -c -o delete_user.o
	
search_user_msg.o : search_user_msg.c
	gcc search_user_msg.c -c -o search_user_msg.o

change_user_msg.o : change_user_msg.c
	gcc change_user_msg.c -c -o change_user_msg.o
	
clean :
	@rm -rf ./*.o
