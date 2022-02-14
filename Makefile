CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CKECKER_OBJ= checker_utls/*.c lib/*.c source/*.c
OBJ= source/*.c lib/*.c main/main.c
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o push_swap
bonus : 
			$(CC) $(CFLAGS) $(CKECKER_OBJ) -o checker
clean :
	rm -fr push_swap
	rm -fr hecker
fclean : clean

re : clean all