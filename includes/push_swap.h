# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <stdio.h>
typedef struct stack
{
    int data;
    struct stack *next;    
}   stack;

int	ft_atoi(char *str);
void print_stack_data(stack *top);
void    push(stack **top, int data);
#endif