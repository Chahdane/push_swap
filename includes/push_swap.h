# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
# include <stdarg.h>

typedef struct stack
{
    int data;
    struct stack *next;    
}   stack;

int	ft_itoa(int n);

int	ft_putstr(char *str);
long	ft_atol(char *str);
void	print_stack_data(stack *top);
void	push(stack **top, int data);
int		is_sorted(stack *top);
void	free_stack(stack *top);
int	ft_printf(const char *str, ...);
void	ft_putstr_fd(char *str, char c);

void	swap(stack *top, char ab);
void	rotate(stack **top, char ab);
void	reverse_rotate(stack **top, char ab);
void	push_element(stack **from, stack **to, char ab);


void	sort_2_elements(stack **top, char ab);
void	sort_3_elements(stack **top);
void	sort_5_elements(stack **top);
void sort(stack **top);

void push_5_to_a(stack **a, stack **b);

void i_sort(stack **top, int n);

void	push2_sort3(stack **top, stack **b);
void	push_to_pos2(stack **top, stack **b);
void	push_to_pos3(stack **top, stack **b);
void	push_to_pos4(stack **top, stack **b);
void	push_to_last_pos(stack **top, stack **b);


#endif