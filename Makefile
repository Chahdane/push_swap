CC = gcc
CFLAGS = -Wall -Wextra -Werror 
CKECKER_OBJ= checker_src/*.c lib/*.c source/*.c
OBJ= source/*.c lib/*.c main/main.c

all : push_swap

push_swap :
			$(CC) $(CFLAGS) $(OBJ) -o push_swap
bonus : 
			$(CC) $(CFLAGS) $(CKECKER_OBJ) -o checker
clean :
	rm -rf push_swap
	rm -rf checker

fclean : clean

re : clean all