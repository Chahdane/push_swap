all :
	@gcc -Wall -Wextra -Werror source/*.c lib/*.c -o push_swap
	@echo "done.."
	ls
clean :
	@rm push_swap
