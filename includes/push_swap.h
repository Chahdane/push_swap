# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack
{
    int data;
    struct stack *next;    
}   stack;

long	ft_atol(char *str);
void	print_stack_data(stack *top);
void	push(stack **top, int data);
int		is_sorted(stack *top);
void	free_stack(stack *top);

void	swap(stack *top, char ab);
void	rotate(stack **top, char ab);


void sort_3_elements(stack **top);


#endif