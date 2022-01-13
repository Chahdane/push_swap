all :
	@gcc -Wall -Wextra -Werror source/*.c libft/*.c -o push_swap
	@echo "done.."
clean :
	@rm push_swap