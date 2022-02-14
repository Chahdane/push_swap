CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CKECKER_OBJ= checker/*.c lib/*.c source/*.c
OBJ= source/*.c lib/*.c main/main.c

all : push_swap

push_swap :
			$(CC) $(CFLAGS) $(OBJ) -o push_swap
bonus : 
			$(CC) $(CFLAGS) $(CKECKER_OBJ) -o my_checker
clean :
	rm push_swap

fclean : clean

re : clean all